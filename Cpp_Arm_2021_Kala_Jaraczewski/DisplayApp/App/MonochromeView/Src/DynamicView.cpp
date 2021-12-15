/// @file DynamicView.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>

#include "assert.h"

#include "MonochromeView/DynamicView.hpp"

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

void DynamicView::Draw(const size_t x, const size_t y, const ViewIf& rView)
{
    // TODO: Implement drawing at target possition.
    // TODO: Add optimization for drawing the whole 8 bits.
    // TODO: Validate size overflow.
    const size_t anotherViewSize = rView.Height() * rView.Width() / 8U;
    std::memcpy(m_pBuffer, rView.Data(), anotherViewSize);
}

void DynamicView::Draw(const size_t x, const size_t y, const bool color)
{
    // TODO: Implement it
}

void DynamicView::Fill(const bool color)
{
    const size_t bufferSize = m_Width * m_Height / 8U;
    const uint8_t data = (color ? 0xFFU : 0x00);
    std::memset(m_pBuffer, data, bufferSize);
}

};
