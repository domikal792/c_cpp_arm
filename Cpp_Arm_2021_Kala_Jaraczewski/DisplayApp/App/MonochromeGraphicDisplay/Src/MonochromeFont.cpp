/// @file MonochromeFont.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include "MonochromeGraphicDisplay/MonochromeFont.hpp"

namespace MonochromeGraphicDisplay
{

MonochromeFont::MonochromeFont(const uint8_t* const pCharsBytes,
               const size_t width,
               const size_t height,
               const size_t firstCharAsciiOffset, 
               const size_t charsNum) :
    m_Width(width),
    m_Height(height),
    m_FirstCharAsciiOffset(firstCharAsciiOffset),
    m_CharsNum(charsNum),
    m_SingleCharBytesNum(width * ((height + 7U) / 8U)),
    m_pCharsBytes(pCharsBytes)
{
    assert(pCharsBytes != nullptr);
}

uint8_t MonochromeFont::GetWidth() const
{
    return m_Width;
}

uint8_t MonochromeFont::GetHeight() const
{
    return m_Height;
}

MonochromeView::ConstView MonochromeFont::GetCharView(const char character) const
{
    size_t charIdx = static_cast<size_t>(character) - m_FirstCharAsciiOffset;
    assert(charIdx < m_CharsNum);

    return MonochromeView::ConstView(&m_pCharsBytes[charIdx * m_SingleCharBytesNum], m_Width, m_Height);
}

}
