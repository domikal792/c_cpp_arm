/// @file MonochromeGraphic.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "MonochromeGraphicDisplay/MonochromeGraphic.hpp"

namespace MonochromeGraphicDisplay
{

MonochromeGraphic::MonochromeGraphic(const uint8_t *pData)  { m_graphicData = pData; }

const uint8_t * MonochromeGraphic::GetData() const { return m_graphicData; }

}
