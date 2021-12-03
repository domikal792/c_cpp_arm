

#ifndef __DISCH_FIRMWARE_SH1106_H__
#define __DISCH_FIRMWARE_SH1106_H__

#include "main.h"
#include "DischFirmwareFonts.h"
#include "DischFirmwarePhotos.h"

namespace disch
{
namespace firmware
{

class SH1106
{
public:
	static constexpr const uint8_t HEIGHT = 64;
	static constexpr const uint8_t WIDTH = 128;

	enum eColor {
		COLOR_BLACK = 0x00,
		COLOR_BLUE = 0x01
	};

	struct sPoint {
		uint8_t m_x = 0,
				m_y = 0;
		sPoint(uint8_t x, uint8_t y) : m_x(x), m_y(y) {}
		sPoint & operator=(const sPoint & oth)
		{
			m_x = oth.m_x;
			m_y = oth.m_y;
			return *this;
		}
		sPoint() {}
	};

	SH1106(const SH1106 &) = delete;
	void operator=(const SH1106 &) = delete;
	virtual ~SH1106();

	static SH1106 &getInstance();

	void setSpiInterface(SPI_TypeDef * SPIx,
			  	  	  	 GPIO_TypeDef * csPort, uint32_t csPin,
						 GPIO_TypeDef * dcPort, uint32_t dcPin,
						 GPIO_TypeDef * resPort, uint32_t resPin);

	bool init();


	bool isDisplayOn() const { return m_dispOn; }
	bool isDisplayInitialized() const { return m_initialized; }
	bool isColorInverted() const { return m_inverted; }

	bool setDisplayOn(bool on);
	void setCursor(sPoint point);
	bool setColorInverted(bool inverse);
	bool setContrast(uint8_t value);
	void fill(eColor color);
	bool clear();
	bool drawPixel(sPoint point, eColor color);
	bool drawLine(sPoint point1, sPoint point2, eColor color);
	bool writeChar(char ch, const Font & font, eColor color);
	bool writeString(const char * pStr, const Font & font, eColor color);
	bool displayPhoto(const Photo & photo);

	bool updateScreen();

	static constexpr uint16_t getBufSize() { return HEIGHT * WIDTH / 8; }

private:
	SH1106();

	void reset();
	bool writeCmd(uint8_t cmd);
	bool writeData(uint8_t * pData, uint8_t dataLen);


private:
	static constexpr const bool MIRROR_VERT = false;
	static constexpr const bool MIRROR_HORIZ = false;
	// Some displays has column offset
	static constexpr const uint8_t COLUMN_OFFSET = 2;

	static constexpr const uint32_t TXE_FLAG_CHECKS_MAX_NUM = 1000;
	SPI_TypeDef * m_SPIx = nullptr;
	GPIO_TypeDef * m_csPort = nullptr,
				 * m_dcPort = nullptr,
				 * m_resPort = nullptr;
	uint32_t m_csPin,
			 m_dcPin,
			 m_resPin;

	uint8_t * m_buf = nullptr;
	sPoint m_currPoint;
	bool m_dispOn = false;
	bool m_inverted = false;
	bool m_initialized = false;

}; /* SH1106 */

} /* firmware */
} /* disch */

#endif /* __DISCH_FIRMWARE_SH1106_H__ */
