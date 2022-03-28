/// @file Sh1106Impl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include <cstring>

#include "DisplayComm/DisplayCommIf.hpp"
#include "DisplayComm/DisplayResetIf.hpp"
#include "Sh1106Impl.hpp"

namespace Sh1106
{

template<size_t WIDTH, size_t HEIGHT>
constexpr const size_t Sh1106Impl<WIDTH, HEIGHT>::ROWS_NUM;

template<size_t WIDTH, size_t HEIGHT>
constexpr const size_t Sh1106Impl<WIDTH, HEIGHT>::DISPLAY_BUFFER_SIZE;

template<size_t WIDTH, size_t HEIGHT>
Sh1106Impl<WIDTH, HEIGHT>::Sh1106Impl(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                       DisplayComm::DisplayResetIf* const pDisplayResetIf, 
                       const bool mirrorVertically, 
                       const bool mirrorHorizontally,
                       const size_t columnOffset) :
    m_MirrorVertically(mirrorVertically),
    m_MirrorHorizontally(mirrorHorizontally),
    m_ColumnOffset(columnOffset),
    m_pDisplayCommIf(pDisplayCommIf),
    m_pDisplayResetIf(pDisplayResetIf),
    m_IsColorInverted(false),
    m_DisplayView(m_DisplayBuffer, WIDTH, HEIGHT)
{
    assert(m_pDisplayCommIf != nullptr);
    assert(m_pDisplayResetIf != nullptr);

    std::memset(m_DisplayBuffer, 0, DISPLAY_BUFFER_SIZE);

    InitDeviceDriver();
}

template<size_t WIDTH, size_t HEIGHT>
bool Sh1106Impl<WIDTH, HEIGHT>::TurnOnDisplay() 
{
    return m_pDisplayCommIf->WriteCmd(0xAFU);
}

template<size_t WIDTH, size_t HEIGHT>
bool Sh1106Impl<WIDTH, HEIGHT>::TurnOffDisplay() 
{
    return m_pDisplayCommIf->WriteCmd(0xAEU);
}

template<size_t WIDTH, size_t HEIGHT>
bool Sh1106Impl<WIDTH, HEIGHT>::InverseColor(bool inverse) 
{
    bool result = false;

    if (inverse)
    {
        result = m_pDisplayCommIf->WriteCmd(0xA7U);
    }
    else
    {
        result = m_pDisplayCommIf->WriteCmd(0xA6U);
    }

    return result;
}

template<size_t WIDTH, size_t HEIGHT>
bool Sh1106Impl<WIDTH, HEIGHT>::SetContrast(uint8_t value) 
{
    bool result = m_pDisplayCommIf->WriteCmd(0x81U);
    result = result && m_pDisplayCommIf->WriteCmd(value);
    return result;
}

template<size_t WIDTH, size_t HEIGHT>
bool Sh1106Impl<WIDTH, HEIGHT>::RefreshScreen() 
{
    bool result = true;

    // Write data to each page of RAM. Number of pages
    // depends on the screen HEIGHT:
    //
    //  * 32px   ==  4 pages
    //  * 64px   ==  8 pages
    //  * 128px  ==  16 pages
    for (size_t i = 0U; i < ROWS_NUM; ++i)
    {
        // Set the current RAM page address.
        result = result && m_pDisplayCommIf->WriteCmd(0xB0U + i);
        result = result && m_pDisplayCommIf->WriteCmd(static_cast<uint8_t>(m_ColumnOffset));
        result = result && m_pDisplayCommIf->WriteCmd(0x10U);
        result = result && m_pDisplayCommIf->WriteData(&m_DisplayBuffer[i * WIDTH], WIDTH);
    }

    return result;
}

template<size_t WIDTH, size_t HEIGHT>
MonochromeView::DynamicView& Sh1106Impl<WIDTH, HEIGHT>::GetView() 
{
    return m_DisplayView;
}

template<size_t WIDTH, size_t HEIGHT>
size_t Sh1106Impl<WIDTH, HEIGHT>::GetWidth()
{
    return WIDTH;
}

template<size_t WIDTH, size_t HEIGHT>
size_t Sh1106Impl<WIDTH, HEIGHT>::GetHeight()
{
    return HEIGHT;
}

template<size_t WIDTH, size_t HEIGHT>
void Sh1106Impl<WIDTH, HEIGHT>::InitDeviceDriver()
{
    m_pDisplayResetIf->Reset();

    bool result = TurnOffDisplay();

    // Set Memory Addressing Mode
    result = result && m_pDisplayCommIf->WriteCmd(0x20U);

    // 00b - Horizontal Addressing Mode, 01b - Vertical Addressing Mode
    // 10b - Page Addressing Mode (RESET), 11b - Invalid
    result = result && m_pDisplayCommIf->WriteCmd(0x00U);

    // Set Page Start Address for Page Addressing Mode: 0-7
    result = result && m_pDisplayCommIf->WriteCmd(0xB0U);

    if (m_MirrorVertically)
    {
        // Mirror vertically
        result = result && m_pDisplayCommIf->WriteCmd(0xC0U);
    }
    else
    {
        // Set COM Output Scan Direction
        result = result && m_pDisplayCommIf->WriteCmd(0xC8U);
    }

    // Set low column address
    result = result && m_pDisplayCommIf->WriteCmd(0x00U);

    // Set high column address
    result = result && m_pDisplayCommIf->WriteCmd(0x10U);

    // Set start line address
    result = result && m_pDisplayCommIf->WriteCmd(0x40U);

    // Set contrast
    result = result && SetContrast(0xFFU);

    if (m_MirrorHorizontally)
    {
        // Mirror horizontally
        result = result && m_pDisplayCommIf->WriteCmd(0xA0U);
    }
    else
    {
        // Set segment re-map 0 to 127
        result = result && m_pDisplayCommIf->WriteCmd(0xA1U);
    }

    // Inverse color
    result = result && InverseColor(m_IsColorInverted);

    if (HEIGHT == 128U)
    {
        // Found in the Luma Python lib for SH1106.
        result = result && m_pDisplayCommIf->WriteCmd(0xFFU);
    }
    else
    {
        // Set multiplex ratio (1 to 64)
        result = result && m_pDisplayCommIf->WriteCmd(0xA8U);
    }

    if (HEIGHT == 32U)
    {
        result = result && m_pDisplayCommIf->WriteCmd(0x1FU);
    }

    if ((HEIGHT == 64U) || (HEIGHT == 128U))
    {
        result = result && m_pDisplayCommIf->WriteCmd(0x3FU);
    }

    // 0xa4 - Output follows RAM content, 0xa5 - Output ignores RAM content
    result = result && m_pDisplayCommIf->WriteCmd(0xA4U);

    // Set display offset - CHECK
    result = result && m_pDisplayCommIf->WriteCmd(0xD3U);

    // Not offset    
    result = result && m_pDisplayCommIf->WriteCmd(0x00U);

    // Set display clock divide ratio/oscillator frequency
    result = result && m_pDisplayCommIf->WriteCmd(0xD5U);

    // Set divide ratio
    result = result && m_pDisplayCommIf->WriteCmd(0xF0U);

    // Set pre-charge period
    result = result && m_pDisplayCommIf->WriteCmd(0xD9U);

    result = result && m_pDisplayCommIf->WriteCmd(0x22U);

    // Set com pins hardware configuration
    result = result && m_pDisplayCommIf->WriteCmd(0xDAU);

    if (HEIGHT == 32U)
    {
        result = result && m_pDisplayCommIf->WriteCmd(0x02U);
    }

    if ((HEIGHT == 64U) || (HEIGHT == 128U))
    {
        result = result && m_pDisplayCommIf->WriteCmd(0x12U);
    }

    // Set vcomh
    result = result && m_pDisplayCommIf->WriteCmd(0xDBU);

    // 0x20 - 0.77 x Vcc
    result = result && m_pDisplayCommIf->WriteCmd(0x20U);

    // Set DC-DC enable
    result = result && m_pDisplayCommIf->WriteCmd(0x8DU);

    result = result && m_pDisplayCommIf->WriteCmd(0x14U);

    // Turn on display.
    result = result && TurnOnDisplay();

    // Refresh screen.
    result = result && RefreshScreen();

    // Assert success.
    assert(result == true);
}

/// Supported display resolutions.
template class Sh1106Impl<128U, 32U>;
template class Sh1106Impl<128U, 64U>;
template class Sh1106Impl<128U, 128U>;

}
