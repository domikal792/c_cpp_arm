/// @file ViewHelper.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEVIEW_VIEWHELPER_HPP
#define MONOCHROMEVIEW_VIEWHELPER_HPP

#include <cstddef>
#include <cstdint>

#include "MonochromeView/ViewIf.hpp"

namespace MonochromeView
{

class ViewHelper
{
public:
    static size_t GetCellIndex(const size_t x, const size_t y, const size_t width)
    {
        return (y / ViewIf::PIXELS_PER_CELL) * width + x;
    }

    static uint8_t GetPixelIndex(const size_t y)
    {
        return (y % ViewIf::PIXELS_PER_CELL);
    }

    static size_t GetBufferSize(const size_t width, const size_t height)
    {
        return (width * height / ViewIf::PIXELS_PER_CELL);
    }

private:
    ViewHelper(const ViewHelper&) = delete;
    void operator=(const ViewHelper&) = delete;
};

}

#endif
