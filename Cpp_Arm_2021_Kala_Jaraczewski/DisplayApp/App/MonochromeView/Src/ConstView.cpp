/// @file ConstView.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include "MonochromeView/ConstView.hpp"
#include "ViewHelper.hpp"

namespace MonochromeView
{

ConstView::ConstView(const uint8_t* const pBuffer, const size_t width, const size_t height) :
    m_pBuffer(pBuffer),
    m_Width(width),
    m_Height(height)
{
    assert(m_pBuffer != nullptr);
    assert(m_Width > 0U);
    assert(m_Height > 0U);
}

size_t ConstView::Width() const
{
    return m_Width;
}

size_t ConstView::Height() const
{
    return m_Height;
}

const uint8_t* ConstView::Data() const
{
    return m_pBuffer;
}

bool ConstView::GetPixelColor(const size_t x, const size_t y) const
{
    bool color = false;

    if ((x < m_Width) && (y < m_Height))
    {
        const size_t cellIdx = ViewHelper::GetCellIndex(x, y, m_Width);
        const uint8_t pxInCellIdx = ViewHelper::GetPixelIndex(y);
        color = static_cast<bool>(m_pBuffer[cellIdx] & (1U << pxInCellIdx));
    }

    return color;
}

};
