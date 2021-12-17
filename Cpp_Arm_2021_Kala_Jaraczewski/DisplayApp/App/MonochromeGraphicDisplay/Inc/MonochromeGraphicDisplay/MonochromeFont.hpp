/// @file MonochromeFont.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP
#define MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP

#include <cstddef>
#include <cstdint>

#include "MonochromeView/ConstView.hpp"

namespace MonochromeGraphicDisplay
{

/// Monochrome font.
class MonochromeFont
{
public:
    /// Construct a new Monochrome Font object
    /// 
    /// @param pCharsViews Pointer to font characters bytes array. First element should has ASCII code.
    /// @param width Font width in pixels.
    /// @param height Font height in pixels.
    /// @param firstCharAsciiOffset Offset in ASCII table of the first character in font.
    /// @param charsNum Number of characters in font.
    MonochromeFont(const uint8_t* const pCharsBytes,
                   const size_t width,
                   const size_t height,
                   const size_t firstCharAsciiOffset, 
                   const size_t charsNum);

    /// Get the Width object
    /// 
    /// @return uint8_t 
	uint8_t GetWidth() const;
    
    /// Get the Height object
    /// 
    /// @return uint8_t 
	uint8_t GetHeight() const;

    /// Get character view.
    /// 
    /// @param character Character to get view of.
    ///
    /// @return Character view.
    MonochromeView::ConstView GetCharView(const char character) const;

private:
    const size_t m_Width;
    const size_t m_Height;
    const size_t m_FirstCharAsciiOffset;
    const size_t m_CharsNum;
    const size_t m_SingleCharBytesNum;
    const uint8_t* const m_pCharsBytes;

};

}

#endif
