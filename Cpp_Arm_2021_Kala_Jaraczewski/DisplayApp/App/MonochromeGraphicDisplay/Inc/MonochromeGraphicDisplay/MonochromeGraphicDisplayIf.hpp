/// @file MonochromeGraphicDisplayIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_MONOCHROMEGRAPHICDISPLAYIF_HPP
#define MONOCHROMEGRAPHICDISPLAY_MONOCHROMEGRAPHICDISPLAYIF_HPP

#include "MonochromeFont.hpp"
#include "MonochromeGraphic.hpp"
#include <cstdint>
#include <cstddef>

namespace MonochromeGraphicDisplay
{

/// Interface for monochrome graphic dosplay.
class MonochromeGraphicDisplayIf
{
public:
    /// Fill the whole diplay with a single color. 
    /// 
    /// @param color [0 - black, 1 - default display color]
    virtual void Fill(const bool color) = 0;

    /// Clear the whole display.
    virtual void Clear() = 0;

    /// Draw a single pixel.
    /// 
    /// @param x Position in pixles, starting from left edge.
    /// @param y Position in pixles, starting from top edge.
    /// @param color 
    virtual void DrawPixel(const size_t x, const size_t y, const bool color) = 0;

    /// Draw line between two points.
    /// 
    /// @param x1 First point position in pixles, starting from left edge.
    /// @param y1 First point position in pixles, starting from top edge.
    /// @param x2 Second point position in pixles, starting from left edge.
    /// @param y2 Second point position in pixles, starting from top edge.
    /// @param color [0 - black, 1 - default display color]
    virtual void DrawLine(const size_t x1, const size_t y1, 
                          const size_t x2, const size_t y2, 
                          const bool color) = 0;

    /// Set cursor at the position.
    ///
    /// @param x Position in pixles, starting from left edge.
    /// @param y Position in pixles, starting from top edge.
    virtual void SetCursor(const size_t x,
                           const size_t y) = 0;

    /// Write character on the display.
    /// 
    /// @param ch Character to write.
    /// @param rFont Font for character.
    /// @param color [0 - black, 1 - default display color]
    virtual void WriteChar(const char ch, const MonochromeFont& rFont, const bool color) = 0;

    /// Write string on the display.
    /// 
    /// @param pStr Null-terminated C like string to write on the display.
    /// @param rFont Font for string.
    /// @param color [0 - black, 1 - default display color]
    virtual void WriteString(const char* const pStr, const MonochromeFont& rFont, const bool color) = 0;

    /// Display graphic on the display.
    /// 
    /// @param pGraphic Graphic object.
    virtual void DisplayGraphic(const MonochromeGraphic& rGraphic) = 0;
};

}

#endif
