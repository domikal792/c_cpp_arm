/// @file MonochromeFont.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include "MonochromeGraphicDisplay/MonochromeFont.hpp"

namespace MonochromeGraphicDisplay
{

MonochromeFont::MonochromeFont(const size_t width, 
				    		   const size_t height, 
							   const size_t firstCharAsciiOffset, 
							   const size_t charsNum, 
							   const MonochromeView::ViewIf* const pCharsViews) :
	m_Width(width),
	m_Height(height),
	m_FirstCharAsciiOffset(firstCharAsciiOffset),
	m_CharsNum(charsNum),
	m_pCharsViews(pCharsViews)
{
}

MonochromeFont::MonochromeFont(uint8_t width, uint8_t height, const uint16_t * pData) :
		m_Width(width),
		m_Height(height),
		m_FirstCharAsciiOffset(0U),
		m_CharsNum(0U),
		m_pCharsViews(nullptr),
		m_pData(pData)
{
}

uint8_t MonochromeFont::GetWidth() const 
{ 
	return m_Width; 
}

uint8_t MonochromeFont::GetHeight() const 
{ 
	return m_Height; 
}

const MonochromeView::ViewIf& MonochromeFont::GetCharView(const char character)
{
	size_t charIdx = static_cast<size_t>(character) - m_FirstCharAsciiOffset;
	assert(charIdx < m_CharsNum);
	return m_pCharsViews[charIdx];
}

const uint16_t * MonochromeFont::GetData() const 
{ 
	return m_pData; 
}

}
