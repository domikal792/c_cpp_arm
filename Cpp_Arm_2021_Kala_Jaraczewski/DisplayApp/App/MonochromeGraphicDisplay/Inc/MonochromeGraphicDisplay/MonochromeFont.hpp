/// @file MonochromeFont.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP
#define MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP

#include <cstddef>
#include <cstdint>

#include "MonochromeView/ViewIf.hpp"

namespace MonochromeGraphicDisplay
{

/// Monochrome font.
class MonochromeFont
{
public:
    /// Construct a new Monochrome Font object
    ///
    /// @deprecated This constructor is deprecated and it will be removed when all fonts are converted to the views.
    /// 
    /// @param width Font width in pixels
    /// @param height Font height in pixels
    /// @param firstCharAsciiOffset Offset in ASCII table of the first character in font.
    /// @param charsNum Number of characters in font.
    /// @param pCharsViews Pointer to font characters views array. First element should has ASCII code 
    MonochromeFont(const size_t width, 
                   const size_t height, 
                   const size_t firstCharAsciiOffset, 
                   const size_t charsNum, 
                   const MonochromeView::ViewIf* const pCharsViews);

    /// Construct a new Monochrome Font object
    ///
    /// @deprecated This constructor is deprecated and it will be removed when all fonts are converted to the views.
    /// 
    /// @param width Font width in pixels
    /// @param height Font height in pixels
    /// @param pData Pointer to font array data
    MonochromeFont(uint8_t width, uint8_t height, const uint16_t * pData);

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
    const MonochromeView::ViewIf& GetCharView(const char character);
    
    /// Get the Data object
    ///
    /// @deprecated This method is deprecated and it will be removed when all fonts are converted to the views.
    ///
    /// @return const uint16_t* 
	const uint16_t * GetData() const;

private:
    const size_t m_Width;
	const size_t m_Height;
    const size_t m_FirstCharAsciiOffset;
    const size_t m_CharsNum;
    const MonochromeView::ViewIf* const m_pCharsViews;

    /// @deprecated This member is deprecated and it will be removed when all fonts are converted to the views.
	const uint16_t * m_pData;

};

}

#endif
