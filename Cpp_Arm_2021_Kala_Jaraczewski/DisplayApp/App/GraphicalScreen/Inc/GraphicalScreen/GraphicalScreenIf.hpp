/// @file GraphicalScreenIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef GRAPHICALSCREEN_GRAPHICALSCREENIF_HPP
#define GRAPHICALSCREEN_GRAPHICALSCREENIF_HPP

#include "GraphicalScreen/Fonts.hpp"
#include "GraphicalScreen/Graphics.hpp"
#include <cstdint>
#include <cstddef>

namespace GraphicalScreen
{

class GraphicalScreenIf
{
    public:

    /// 
    /// 
    /// @param color [0 - normal, 1 - inversed]
    virtual void Fill(bool color) = 0;

    /// Clear
    /// 
    virtual void Clear() = 0;

    /// Draw Pixel
    /// 
    /// @param x 
    /// @param y 
    /// @param color 
    virtual void DrawPixel(uint8_t x, uint8_t y, bool color) = 0;

    /// 
    /// 
    /// @param x1 
    /// @param y1 
    /// @param x2 
    /// @param y2 
    /// @param color 
    virtual void DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool color) = 0;

    /// 
    /// 
    /// @param ch 
    /// @param font 
    /// @param color 
    virtual void WriteChar(char ch, const Font & font, bool color) = 0;

    /// 
    /// 
    /// @param pStr 
    /// @param font 
    /// @param color 
    virtual void WriteString(const char * pStr, const Font & font, bool color) = 0;

    /// 
    /// 
    /// @param photo 
    virtual void displayGraphic(const Graphic & graphic) = 0;

};

}

#endif