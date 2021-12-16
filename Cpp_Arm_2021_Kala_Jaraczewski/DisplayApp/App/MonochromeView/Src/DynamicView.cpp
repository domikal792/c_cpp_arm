/// @file DynamicView.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>
#include <algorithm>

#include "assert.h"

#include "MonochromeView/DynamicView.hpp"
#include "ViewHelper.hpp"

namespace MonochromeView
{

DynamicView::DynamicView(uint8_t* const pBuffer, const size_t width, const size_t height) :
    m_pBuffer(pBuffer),
    m_Width(width),
    m_Height(height)
{
    assert(m_pBuffer != nullptr);
    assert(m_Width > 0U);
    assert(m_Height > 0U);
}

size_t DynamicView::Width() const
{
    return m_Width;
}

size_t DynamicView::Height() const
{
    return m_Height;
}

const uint8_t* DynamicView::Data() const
{
    return m_pBuffer;
}

bool DynamicView::GetPixelColor(const size_t x, const size_t y) const
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

void DynamicView::DrawAt(const int32_t x, const int32_t y, const ViewIf& rView)
{
    if ((x >= static_cast<int32_t>(m_Width)) || (y >= static_cast<int32_t>(m_Height)))
    {
        return;
    }

    const int32_t xSignedStopPx = (x + static_cast<int32_t>(rView.Width()));
    const int32_t ySignedStopPx = (y + static_cast<int32_t>(rView.Height()));

    if ((xSignedStopPx <= 0) || (ySignedStopPx <= 0))
    {
        return;
    }

    // TODO: Add optimization for drawing the whole 8 bits at once (range of cells).

    size_t xCurrentPx = static_cast<size_t>(std::max(x, 0L));
    const size_t xStopPx = std::min(static_cast<size_t>(xSignedStopPx), m_Width);
    const size_t yStartPx = static_cast<size_t>(std::max(y, 0L));
    const size_t yStopPx = std::min(static_cast<size_t>(ySignedStopPx), m_Height);

    assert(xCurrentPx < xStopPx);
    assert(yStartPx < yStopPx);

    size_t xAnotherViewCurrentPx = static_cast<size_t>(std::max(-1 * x, 0L));
    const size_t yAnotherViewStartPx = static_cast<size_t>(std::max(-1 * y, 0L));

    assert(xAnotherViewCurrentPx < rView.Width());
    assert(yAnotherViewStartPx < rView.Height());

    for (; xCurrentPx < xStopPx; ++xCurrentPx)
    {
        size_t yAnotherViewCurrentPx = yAnotherViewStartPx;
        for (size_t yCurrentPx = yStartPx; yCurrentPx < yStopPx; ++yCurrentPx)
        {
            const bool pxColor = rView.GetPixelColor(xAnotherViewCurrentPx, yAnotherViewCurrentPx);
            DrawAt(xCurrentPx, yCurrentPx, pxColor);
            ++yAnotherViewCurrentPx;
        }
        ++xAnotherViewCurrentPx;
    }
}

void DynamicView::DrawAt(const size_t x, const size_t y, const bool color)
{
    if ((x < m_Width) && (y < m_Height))
    {
        const size_t cellIdx = ViewHelper::GetCellIndex(x, y, m_Width);
        const uint8_t pxInCellIdx = ViewHelper::GetPixelIndex(y);

        if (color)
        {
            m_pBuffer[cellIdx] |= (1U << pxInCellIdx);
        }
        else
        {
            m_pBuffer[cellIdx] &= ~(1U << pxInCellIdx);
        }
    }
}

void DynamicView::Fill(const bool color)
{
    const size_t bufferSize = ViewHelper::GetBufferSize(m_Width, m_Height);
    const uint8_t data = (color ? 0xFFU : 0x00U);
    std::memset(m_pBuffer, data, bufferSize);
}

};
