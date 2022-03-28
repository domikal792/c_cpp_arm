/// @file AboutPage.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAYAPP_ABOUTPAGE_HPP
#define DISPLAYAPP_ABOUTPAGE_HPP

#include "MonochromeView/DynamicView.hpp"
#include "PageIf.hpp"

class AboutPage :
    public PageIf
{
public:
    AboutPage(MonochromeView::DynamicView& rView);

    /// @copydoc PageIf::OnCreate
    void OnCreate() override;

    /// @copydoc PageIf::Refresh
    void Refresh() override;

private:
    MonochromeView::DynamicView& m_rView;
};

#endif
