/// @file MonochromeText.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMETEXT_MONOCHROMETEXT_HPP
#define MONOCHROMETEXT_MONOCHROMETEXT_HPP

#include <cstddef>
#include <cstdint>

#include "MonochromeText/MonochromeFont.hpp"
#include "MonochromeView/DynamicView.hpp"

namespace MonochromeText
{

/// Monochrome text.
class MonochromeText
{
public:
    /// Write 'character' at {x, y} point in the view 'rView' using font 'rFont' and draw options 'drawOption'.
    /// 
    /// @param rView View to write character in.
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// @param rFont Font.
    /// @param character Character to write.
    /// @param drawOption Draw options, @see MonochromeView::DynamicView::DrawAt
    static void WriteChar(MonochromeView::DynamicView& rView, 
                          const size_t x, const size_t y, 
                          const MonochromeFont& rFont, 
                          const char character, 
                          const uint8_t drawOption = MonochromeView::DRAW_OPT_NONE);

    /// Write string 'pString' at {x, y} point in the view 'rView' using font 'rFont' and draw options 'drawOption'.
    /// 
    /// @param rView View to write string in.
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// @param rFont Font.
    /// @param pString Null-terminated C like string to write on the display.
    /// @param drawOption Draw options, @see MonochromeView::DynamicView::DrawAt
    static void WriteString(MonochromeView::DynamicView& rView, 
                            const size_t x, const size_t y, 
                            const MonochromeFont& rFont, 
                            const char* const pString, 
                            const uint8_t drawOption = MonochromeView::DRAW_OPT_NONE);

private:
    MonochromeText(const MonochromeText&) = delete;
    void operator=(const MonochromeText&) = delete;
};

}

#endif
