/// @file DynamicView.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEVIEW_DYNAMICVIEW_HPP
#define MONOCHROMEVIEW_DYNAMICVIEW_HPP

#include "ViewIf.hpp"

namespace MonochromeView
{

class DynamicView : 
    public ViewIf
{
public:
    /// Construct a new constant view object.
    /// 
    /// @param pBuffer Pointer to the view data buffer. The first element is a left-top cell (1 column and 8 rows pixels). 
    ///                The first column is repeated for each next 'width' pixels.
    /// @param width Width of a view.
    /// @param height Height of a view.
    DynamicView(uint8_t* const pBuffer, const size_t width, const size_t height);

    /// @copydoc MonochromeView::ViewIf::Width
    size_t Width() const override;

    /// @copydoc MonochromeView::ViewIf::Height
    size_t Height() const override;

    /// Draw at {x, y} another view.
    /// 
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// @param rView View to draw.
    void Draw(const size_t x, const size_t y, const ViewIf& rView);

    /// Draw at {x, y} a single pixel.
    /// 
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// @param color Color of the pixel. [0 - black, 1 - default color].
    void Draw(const size_t x, const size_t y, const bool color);

    /// Fill the whole view with a single color.
    /// 
    /// @param color Color to fill view. [0 - black, 1 - default color].
    void Fill(const bool color);

private:
    /// @copydoc MonochromeView::ViewIf::Data
    const uint8_t* Data() const override;

    uint8_t* const m_pBuffer;
    const size_t m_Width;
    const size_t m_Height;
};

}

#endif
