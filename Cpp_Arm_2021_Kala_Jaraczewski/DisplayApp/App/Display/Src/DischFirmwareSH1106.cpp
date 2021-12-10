
#include "DischFirmwareSH1106.h"
#include <new>
#include <string.h>
#include <stdlib.h>
#include "spi.h"

using namespace disch::firmware;

// https://www.velleman.eu/downloads/29/infosheets/sh1106_datasheet.pdf
// Based on https://github.com/afiskon/stm32-ssd1306

constexpr const uint8_t SH1106::HEIGHT;
constexpr const uint8_t SH1106::WIDTH;
constexpr const bool SH1106::MIRROR_VERT;
constexpr const bool SH1106::MIRROR_HORIZ;
constexpr const uint8_t SH1106::COLUMN_OFFSET;

SH1106 &SH1106::getInstance()
{
	static SH1106 instance;
	return instance;
}

SH1106::SH1106()
{
	m_buf = new(std::nothrow) uint8_t[getBufSize()];
}

SH1106::~SH1106()
{
	delete[] m_buf;
}

void SH1106::setCommInterface(DisplayComm::DisplayCommIf* pDisplayCommIf,
					  		  DisplayComm::DisplayResetIf* pDisplayResetIf)
{
	m_pDisplayCommIf = pDisplayCommIf;
	m_pDisplayResetIf = pDisplayResetIf;
}

bool SH1106::init()
{
	if(!m_pDisplayCommIf || !m_pDisplayResetIf)
		return false;

	if(!m_buf)
		return false;

	bool success = true;
	m_currPoint.m_x = 0;
	m_currPoint.m_y = 0;

	reset();

	LL_mDelay(100);

	success = setDisplayOn(false);

    if(success)
		success = writeCmd(0x20); //Set Memory Addressing Mode
    if(success)
		success = writeCmd(0x00); // 00b,Horizontal Addressing Mode; 01b,Vertical Addressing Mode;
                                // 10b,Page Addressing Mode (RESET); 11b,Invalid
    if(success)
		success = writeCmd(0xB0); //Set Page Start Address for Page Addressing Mode,0-7

    if(MIRROR_VERT && success)
		success = writeCmd(0xC0); // Mirror vertically
    else if(success)
		success = writeCmd(0xC8); //Set COM Output Scan Direction

    if(success)
		success = writeCmd(0x00); //---set low column address
    if(success)
		success = writeCmd(0x10); //---set high column address

    if(success)
		success = writeCmd(0x40); //--set start line address - CHECK

    if(success)
		success = setContrast(0xFF);

    if(MIRROR_HORIZ && success)
		success = writeCmd(0xA0); // Mirror horizontally

    else if(success)
		success = writeCmd(0xA1); //--set segment re-map 0 to 127 - CHECK

    if(success)
    	success = setColorInverted(m_inverted);


    if(HEIGHT == 128 && success)
    	success = writeCmd(0xFF); // Found in the Luma Python lib for SH1106.

    else if(success)
		success = writeCmd(0xA8); //--set multiplex ratio(1 to 64) - CHECK


    if (HEIGHT == 32 && success)
    	success = writeCmd(0x1F); //

    else if (HEIGHT == 64 && success)
    	success = writeCmd(0x3F); //

	else if (HEIGHT == 128 && success)
		success = writeCmd(0x3F); // Seems to work for 128px high displays too.

    if(success)
		success = writeCmd(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content

    if(success)
		success = writeCmd(0xD3); //-set display offset - CHECK
    if(success)
		success = writeCmd(0x00); //-not offset

    if(success)
		success = writeCmd(0xD5); //--set display clock divide ratio/oscillator frequency
    if(success)
		success = writeCmd(0xF0); //--set divide ratio

    if(success)
		success = writeCmd(0xD9); //--set pre-charge period
    if(success)
		success = writeCmd(0x22); //

    if(success)
		success = writeCmd(0xDA); //--set com pins hardware configuration - CHECK

    if (HEIGHT == 32 && success)
    	success = writeCmd(0x02); //

    else if (HEIGHT == 64 && success)
    	success = writeCmd(0x12); //

	else if (HEIGHT == 128 && success)
		success = writeCmd(0x12); // Seems to work for 128px high displays too.

    if(success)
		success = writeCmd(0xDB); //--set vcomh
    if(success)
		success = writeCmd(0x20); //0x20,0.77xVcc

    if(success)
		success = writeCmd(0x8D); //--set DC-DC enable
    if(success)
		success = writeCmd(0x14); //

    if(success)
		success = setDisplayOn(true); //--turn on SSD1306 panel

    // Clear screen
    fill(COLOR_BLACK);

    // Flush buffer to screen
    if(success)
		success = updateScreen();

    m_initialized = success;

    return success;
}

bool SH1106::setDisplayOn(bool on)
{
	bool success = writeCmd(on ? 0xAF : 0xAE);
	if(success)
		m_dispOn = on;

	return success;
}

void SH1106::setCursor(sPoint point)
{
	m_currPoint = point;
}

bool SH1106::setColorInverted(bool inverse)
{
	bool success = true;
    if(inverse)
    	success = writeCmd(0xA7); //--set inverse color
    else
		success = writeCmd(0xA6); //--set normal color

    if(success)
    	m_inverted = inverse;

    return success;
}

bool SH1106::setContrast(uint8_t value)
{
	bool success = true;
	if(success)
		success = writeCmd(0x81); // contrast control mode
	if(success)
		success = writeCmd(value);
	return success;
}

void SH1106::fill(eColor color)
{
	memset(m_buf, color == COLOR_BLACK ? 0x00 : 0xFF, getBufSize());
}

bool SH1106::clear()
{
	fill(COLOR_BLACK);
	return updateScreen();
}

bool SH1106::drawPixel(sPoint point, eColor color)
{
    if(point.m_x >= WIDTH || point.m_y >= HEIGHT) {
        // Don't write outside the buffer
        return false;
    }

    // Draw in the right color
    if(color == COLOR_BLUE)
        m_buf[point.m_x + (point.m_y / 8) * WIDTH] |= 1 << (point.m_y % 8);
    else
    	m_buf[point.m_x + (point.m_y / 8) * WIDTH] &= ~(1 << (point.m_y % 8));

    return true;
}

bool SH1106::drawLine(sPoint point1, sPoint point2, eColor color)
{
	int32_t deltaX = abs(point2.m_x - point1.m_x);
	int32_t deltaY = abs(point2.m_y - point1.m_y);
	int32_t signX = ((point1.m_x < point2.m_x) ? 1 : -1);
	int32_t signY = ((point1.m_y < point2.m_y) ? 1 : -1);
	int32_t error = deltaX - deltaY;
	int32_t error2;
	bool success = true;

	success = drawPixel(point2, color);
	while(((point1.m_x != point2.m_x) || (point1.m_y != point2.m_y)) && success)
	{
		success = drawPixel(point1, color);
		error2 = error * 2;
		if(error2 > -deltaY)
		{
		  error -= deltaY;
		  point1.m_x += signX;
		}
		else
		{
		  // nothing to do
		}

		if(error2 < deltaX)
		{
		  error += deltaX;
		  point1.m_y += signY;
		}
		else
		{
		  // nothing to do
		}
	}
	return success;
}



bool SH1106::writeChar(char ch, const Font & font, eColor color)
{
    uint32_t i, b, j;
    bool success = true;

    // Check if character is valid
    if (ch < 32 || ch > 126)
        return false;

    // Check remaining space on current line
    if (WIDTH < (m_currPoint.m_x + font.getWidth()) ||
        HEIGHT < (m_currPoint.m_y + font.getHeight()))
    {
        // Not enough space on current line
        return false;
    }

    // Use the font to write
    for(i = 0; i < font.getHeight() && success; i++) {
        b = font.getData()[(ch - 32) * font.getHeight() + i];

        for(j = 0; j < font.getWidth() && success; j++) {
        	sPoint point = m_currPoint;
        	point.m_x += j;
        	point.m_y += i;

            if((b << j) & 0x8000)  {
            	success = drawPixel(point, color);
            } else {
            	success = drawPixel(point, (eColor)!color);
            }
        }
    }

    // The current space is now taken
    m_currPoint.m_x += font.getWidth();

    return success;
}

bool SH1106::writeString(const char * pStr, const Font & font, eColor color)
{
	bool success = true;
	uint8_t i = 0;
	while(*(pStr + i) && (success = writeChar(*(pStr + i), font, color)))
		++i;
	return success;
}

bool SH1106::updateScreen()
{
    // Write data to each page of RAM. Number of pages
    // depends on the screen height:
    //
    //  * 32px   ==  4 pages
    //  * 64px   ==  8 pages
    //  * 128px  ==  16 pages
	bool success = true;
    for(uint8_t i = 0; i < HEIGHT / 8 && success; i++) {
    	if(success)
    		success = writeCmd(0xB0 + i); // Set the current RAM page address.
    	if(success)
    		success = writeCmd(0x00 + COLUMN_OFFSET);
    	if(success)
    		success = writeCmd(0x10);
    	if(success)
    		success = writeData(&m_buf[WIDTH * i], WIDTH);
    }
    return success;
}

void SH1106::reset()
{
	m_pDisplayResetIf->Reset();
}

bool SH1106::writeCmd(uint8_t cmd)
{
	return m_pDisplayCommIf->WriteCmd(cmd);
}

bool SH1106::writeData(uint8_t * pData, uint8_t dataLen)
{
	return m_pDisplayCommIf->WriteData(pData, static_cast<size_t>(dataLen));
}

bool SH1106::displayPhoto(const Photo & photo)
{
	memcpy(m_buf, photo.getData(), getBufSize());
	return updateScreen();
}
