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
    virtual ~ViewIf()
    {
    }

    /// Width of an view in pixels.
    virtual size_t Width() const = 0;

    /// Height of an view in pixels.
    virtual size_t Height() const = 0;

    /// Get constant data of an view.
    virtual const uint8_t* Data() const = 0;
};

}

#endif
