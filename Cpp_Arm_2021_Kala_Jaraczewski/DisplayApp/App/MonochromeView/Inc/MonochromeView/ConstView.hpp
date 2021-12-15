/// @file ConstView.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEVIEW_CONSTVIEW_HPP
#define MONOCHROMEVIEW_CONSTVIEW_HPP

#include "ViewIf.hpp"

namespace MonochromeView
{

class ConstView : 
    public ViewIf
{
public:
    /// Construct a new constant view object.
    /// 
    /// @param pBuffer Pointer to the view data buffer. The first element is a left-top cell (1 column and 8 rows pixels). 
    ///                The first column is repeated for each next 'width' pixels.
    /// @param width Width of a view.
    /// @param height Height of a view.
    ConstView(const uint8_t* const pBuffer, const size_t width, const size_t height);

    /// @copydoc MonochromeView::ViewIf::Width
    size_t Width() const override;

    /// @copydoc MonochromeView::ViewIf::Height
    size_t Height() const override;

private:
    /// @copydoc MonochromeView::ViewIf::Data
    const uint8_t* Data() const override;

    const uint8_t* const m_pBuffer;
    const size_t m_Width;
    const size_t m_Height;
};

}

#endif
