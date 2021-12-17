/// @file MonochromeFont.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP
#define MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP

#include <cstddef>
#include <cstdint>

#include "assert.h"

#include "MonochromeView/ConstStorageView.hpp"

namespace MonochromeGraphicDisplay
{

/// Monochrome font.
/// 
/// @tparam WIDTH Font width in pixels.
/// @tparam HEIGHT Font height in pixels.
template<size_t WIDTH, size_t HEIGHT>
class MonochromeFont
{
public:
    /// Construct a new Monochrome Font object
    ///
    /// @deprecated This constructor is deprecated and it will be removed when all fonts are converted to the views.
    /// 
    /// @param pCharsViews Pointer to font characters views array. First element should has ASCII code.
    /// @param firstCharAsciiOffset Offset in ASCII table of the first character in font.
    /// @param charsNum Number of characters in font.
    MonochromeFont(const MonochromeView::ConstStorageView<WIDTH, HEIGHT>* const pCharsViews,
                   const size_t firstCharAsciiOffset, 
                   const size_t charsNum) :
        m_FirstCharAsciiOffset(firstCharAsciiOffset),
        m_CharsNum(charsNum),
        m_pCharsViews(pCharsViews)
    {
        assert(pCharsViews != nullptr);
    }

    /// Get the Width object
    /// 
    /// @return uint8_t 
	uint8_t GetWidth() const
    {
        return WIDTH;
    }
    
    /// Get the Height object
    /// 
    /// @return uint8_t 
	uint8_t GetHeight() const
    {
        return HEIGHT;
    }

    /// Get character view.
    /// 
    /// @param character Character to get view of.
    ///
    /// @return Character view.
    const MonochromeView::ViewIf& GetCharView(const char character)
    {
        size_t charIdx = static_cast<size_t>(character) - m_FirstCharAsciiOffset;
        assert(charIdx < m_CharsNum);
        return m_pCharsViews[charIdx];
    }

private:
    const size_t m_FirstCharAsciiOffset;
    const size_t m_CharsNum;
    const MonochromeView::ConstStorageView<WIDTH, HEIGHT>* const m_pCharsViews;

};

}

#endif
