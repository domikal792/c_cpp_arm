/// @file ViewIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEVIEW_VIEWIF_HPP
#define MONOCHROMEVIEW_VIEWIF_HPP

#include <cstddef>
#include <cstdint>

namespace MonochromeView
{

/// View interface.
class ViewIf
{
public:
    static constexpr const size_t PIXELS_PER_CELL = 8U;
    
    virtual ~ViewIf()
    {
    }

    /// Width of an view in pixels.
    virtual size_t Width() const = 0;

    /// Height of an view in pixels.
    virtual size_t Height() const = 0;

    /// Get constant data of an view.
    virtual const uint8_t* Data() const = 0;

    /// Get color of the pixel.
    /// 
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// 
    /// @return Color of the pixel. [0 - black, 1 - default color].
    virtual bool GetPixelColor(const size_t x, const size_t y) const = 0;

    /// Check if the view has been changed since the last check.
    virtual bool IfViewChanged() const = 0;
};

}

#endif
