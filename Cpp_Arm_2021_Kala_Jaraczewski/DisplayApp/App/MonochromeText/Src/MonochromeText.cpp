/// @file MonochromeText.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "MonochromeText/MonochromeText.hpp"

namespace MonochromeText
{

void MonochromeText::WriteChar(MonochromeView::DynamicView& rView, 
                               const int32_t x, const int32_t y, 
                               const MonochromeFont& rFont, 
                               const char character, 
                               const uint8_t drawOption)
{
    // Check if character is valid
    if (character >= 32 || character <= 126)
    {
        MonochromeView::ConstView font = rFont.GetCharView(character);
        rView.DrawAt(x, y, font, drawOption);
    }
}

void MonochromeText::WriteString(MonochromeView::DynamicView& rView, 
                                 const int32_t x, const int32_t y, 
                                 const MonochromeFont& rFont, 
                                 const char* const pString, 
                                 const uint8_t drawOption)
{
    uint8_t i = 0U;

    const bool transpose = (drawOption & MonochromeView::DRAW_OPT_TRANSPOSE) != 0;
    const bool yMirror = (drawOption & MonochromeView::DRAW_OPT_Y_MIRROR) != 0;
    int32_t delta = yMirror ? (rFont.GetWidth()) : (-1 * rFont.GetWidth());
    int32_t cursor = 0;

	while(*(pString + i))
    {

        if (transpose)
        {
            WriteChar(rView, x + cursor, y, rFont, *(pString + i), drawOption);
        }
        else
        {
            WriteChar(rView, x, y + cursor, rFont, *(pString + i), drawOption);
        }

        cursor += delta;

        if (i++ == 255U)
        {
            break;
        }
    }
}

}
