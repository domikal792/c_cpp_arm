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

bool DynamicView::IfViewChanged() const
{
    const bool ifViewChanged = m_IfViewChanged;
    m_IfViewChanged = false;
    return ifViewChanged;
}

void DynamicView::DrawAt(const int32_t x, 
                         const int32_t y, 
                         const ViewIf& rAnotherView, 
                         const uint8_t drawOption)
{
    if ((x >= static_cast<int32_t>(m_Width)) || (y >= static_cast<int32_t>(m_Height)))
    {
        return;
    }

    const bool transpose = static_cast<bool>(drawOption & DRAW_OPT_TRANSPOSE);
    const bool xMirror = static_cast<bool>(drawOption & DRAW_OPT_X_MIRROR);
    const bool yMirror = static_cast<bool>(drawOption & DRAW_OPT_Y_MIRROR);
    const bool negColors = static_cast<bool>(drawOption & DRAW_OPT_NEGATIVE_COLORS);

    const size_t anotherViewWidth = (transpose ? rAnotherView.Height() : rAnotherView.Width());
    const size_t anotherViewHeight = (transpose ? rAnotherView.Width() : rAnotherView.Height());
    const int32_t xSignedStopPx = (x + static_cast<int32_t>(anotherViewWidth));
    const int32_t ySignedStopPx = (y + static_cast<int32_t>(anotherViewHeight));

    if ((xSignedStopPx <= 0) || (ySignedStopPx <= 0))
    {
        return;
    }

    size_t xCurrentPx = static_cast<size_t>(std::max(x, 0L));
    const size_t xStopPx = std::min(static_cast<size_t>(xSignedStopPx), m_Width);
    const size_t yStartPx = static_cast<size_t>(std::max(y, 0L));
    const size_t yStopPx = std::min(static_cast<size_t>(ySignedStopPx), m_Height);

    assert(xCurrentPx < xStopPx);
    assert(yStartPx < yStopPx);

    size_t xAnotherViewCurrentPx = 0U;
    size_t yAnotherViewStartPx = 0U;

    if (yMirror)
    {
        xAnotherViewCurrentPx = std::min(static_cast<size_t>(static_cast<int32_t>(anotherViewWidth) + x), anotherViewWidth) - 1U;
    }
    else
    {
        xAnotherViewCurrentPx = static_cast<size_t>(std::max(-1 * x, 0L));
    }

    if (xMirror)
    {
        yAnotherViewStartPx = std::min(static_cast<size_t>(static_cast<int32_t>(anotherViewHeight) + y), anotherViewHeight) - 1U;
    }
    else
    {
        yAnotherViewStartPx = static_cast<size_t>(std::max(-1 * y, 0L));
    }

    assert(xAnotherViewCurrentPx < anotherViewWidth);
    assert(yAnotherViewStartPx < anotherViewHeight);

    for (; xCurrentPx < xStopPx; ++xCurrentPx)
    {
        size_t yAnotherViewCurrentPx = yAnotherViewStartPx;
        for (size_t yCurrentPx = yStartPx; yCurrentPx < yStopPx; ++yCurrentPx)
        {
            bool pxColor = false;

            if (transpose)
            {
                pxColor = rAnotherView.GetPixelColor(yAnotherViewCurrentPx, xAnotherViewCurrentPx);
            }
            else
            {
                pxColor = rAnotherView.GetPixelColor(xAnotherViewCurrentPx, yAnotherViewCurrentPx);
            }
            
            SetPixelColor(xCurrentPx, yCurrentPx, negColors ? !pxColor : pxColor);

            if (xMirror)
            {
                --yAnotherViewCurrentPx;
                assert(yAnotherViewCurrentPx >= 0U);
            }
            else
            {
                assert(yAnotherViewCurrentPx < anotherViewHeight);
                ++yAnotherViewCurrentPx;
            }
        }

        if (yMirror)
        {
            --xAnotherViewCurrentPx;
            assert(xAnotherViewCurrentPx >= 0U);
        }
        else
        {
            assert(xAnotherViewCurrentPx < anotherViewWidth);
            ++xAnotherViewCurrentPx;
        }
    }
}

void DynamicView::DrawLine(const int32_t x1, const int32_t y1,
                           const int32_t x2, const int32_t y2,
                           const bool color)
{
    int32_t deltaX = abs(x2 - x1);
    int32_t deltaY = abs(y2 - y1);
    int32_t signX = ((x1 < x2) ? 1 : -1);
	int32_t signY = ((y1 < y2) ? 1 : -1);
	int32_t currentX = x1;
	int32_t currentY = y1;

	int32_t error = deltaX - deltaY;
	int32_t error2;

    SetPixelColor(x2, y2, color);
	while(((currentX != x2) || (currentY != y2)))
	{
		SetPixelColor(currentX, currentY, color);
		error2 = error * 2;
		if(error2 > -deltaY)
		{
		  error -= deltaY;
		  currentX += signX;
		}
		else
		{
		  /* nothing to do */
		}

		if(error2 < deltaX)
		{
		  error += deltaX;
		  currentY += signY;
		}
		else
		{
		  /* nothing to do */
		}
	}

}

void DynamicView::SetPixelColor(const size_t x, const size_t y, const bool color)
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

        m_IfViewChanged = true;
    }
}

void DynamicView::Fill(const bool color)
{
    const size_t bufferSize = ViewHelper::GetBufferSize(m_Width, m_Height);
    const uint8_t data = (color ? 0xFFU : 0x00U);
    std::memset(m_pBuffer, data, bufferSize);
    m_IfViewChanged = true;
}

}
