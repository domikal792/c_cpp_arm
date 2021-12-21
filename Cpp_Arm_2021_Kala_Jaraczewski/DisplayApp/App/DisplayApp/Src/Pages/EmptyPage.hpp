/// @file EmptyPage.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAYAPP_EMPTYPAGE_HPP
#define DISPLAYAPP_EMPTYPAGE_HPP

#include "MonochromeView/DynamicView.hpp"
#include "PageIf.hpp"

class EmptyPage :
    public PageIf
{
public:
    EmptyPage(MonochromeView::DynamicView& rView);

    /// @copydoc PageIf::OnCreate
    void OnCreate() override;

    /// @copydoc PageIf::Refresh
    void Refresh() override;

private:
    MonochromeView::DynamicView& m_rView;
};

#endif
