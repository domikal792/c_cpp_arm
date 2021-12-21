/// @file DynamicView.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEVIEW_DYNAMICVIEW_HPP
#define MONOCHROMEVIEW_DYNAMICVIEW_HPP

#include "ViewIf.hpp"

namespace MonochromeView
{

/// No additional draw options.
constexpr const uint8_t DRAW_OPT_NONE = 0x00U;

/// Draw transposition of a view.
constexpr const uint8_t DRAW_OPT_TRANSPOSE = 0x01U;

/// Mirror a view horizontally.
constexpr const uint8_t DRAW_OPT_X_MIRROR = 0x02U;

/// Mirror a view vertically.
constexpr const uint8_t DRAW_OPT_Y_MIRROR = 0x04U;

/// Negative colors of a view.
constexpr const uint8_t DRAW_OPT_NEGATIVE_COLORS = 0x08U;

/// Dynamic view.
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

    /// @copydoc MonochromeView::ViewIf::GetPixelColor
    bool GetPixelColor(const size_t x, const size_t y) const override;

    /// @copydoc MonochromeView::ViewIf::GetPixelColor::IfViewChanged
    bool IfViewChanged() const;

    /// Draw at {x, y} another view.
    /// 
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// @param rAnotherView View to draw.
    /// @param drawOption Drawing option DRAW_OPT_TRANSPOSE or DRAW_OPT_X_MIRROR or DRAW_OPT_Y_MIRROR
    void DrawAt(const int32_t x, 
                const int32_t y, 
                const ViewIf& rAnotherView, 
                const uint8_t drawOption = DRAW_OPT_NONE);

    /// Draw line between {x1, y1} and {x2, y2} points.
    /// 
    /// @param x1 First point position in pixles, starting from left edge.
    /// @param y1 First point position in pixles, starting from top edge.
    /// @param x2 Second point position in pixles, starting from left edge.
    /// @param y2 Second point position in pixles, starting from top edge.
    /// @param color [0 - black, 1 - default display color]
    void DrawLine(const size_t x1, const size_t y1, 
                  const size_t x2, const size_t y2, 
                  const bool color);

    /// Set color of a pixel at {x, y}.
    /// 
    /// @param x Horizontal coordinate.
    /// @param y Vertical coordinate.
    /// @param color Color of the pixel. [0 - black, 1 - default color].
    void SetPixelColor(const size_t x, const size_t y, const bool color);

    /// Fill the whole view with a single color.
    /// 
    /// @param color Color to fill view. [0 - black, 1 - default color].
    void Fill(const bool color);

private:
    DynamicView(const DynamicView&)  = delete;
    void operator=(const DynamicView&) = delete;

    /// @copydoc MonochromeView::ViewIf::Data
    const uint8_t* Data() const override;

    uint8_t* const m_pBuffer;
    const size_t m_Width;
    const size_t m_Height;
    mutable bool m_IfViewChanged;
};

}

#endif
