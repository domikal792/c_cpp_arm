/// @file MonochromeFont.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "MonochromeGraphicDisplay/MonochromeFont.hpp"

namespace MonochromeGraphicDisplay
{
MonochromeFont::MonochromeFont(uint8_t width, uint8_t height, const uint16_t * pData) :
		m_width(width),
		m_height(height),
		m_pData(pData)
	{}

uint8_t MonochromeFont::GetWidth() const { return m_width; }

uint8_t MonochromeFont::GetHeight() const { return m_height; }

const uint16_t * MonochromeFont::GetData() const { return m_pData; }

}
