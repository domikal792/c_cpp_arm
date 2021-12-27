/// @file MonochromeText.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "MonochromeText/MonochromeText.hpp"

namespace MonochromeText
{

void MonochromeText::WriteChar(MonochromeView::DynamicView& rView, 
                               const size_t x, const size_t y, 
                               const MonochromeFont& rFont, 
                               const char character, 
                               const uint8_t drawOption)
{
    // Check if character is valid
    if (character < 32 || character > 126)
    {
        
        // Check remaining space on current line
        if (rView.Width() < (x + rFont.GetWidth()) ||
            rView.Height() < (y + rFont.GetHeight()))
        {
            // Not enough space on current line
        }
        else
        {
            MonochromeView::ConstView font = rFont.GetCharView(character);
            rView.DrawAt(x, y, font, drawOption);
        }
    }
}

void MonochromeText::WriteString(MonochromeView::DynamicView& rView, 
                                 const size_t x, const size_t y, 
                                 const MonochromeFont& rFont, 
                                 const char* const pString, 
                                 const uint8_t drawOption)
{
    // TODO: Add x,y operations
    uint8_t i = 0;
	while(*(pString + i))
    {
        WriteChar(rView, x, y, rFont, *(pString + i), drawOption);
		++i;
    }
}

}
