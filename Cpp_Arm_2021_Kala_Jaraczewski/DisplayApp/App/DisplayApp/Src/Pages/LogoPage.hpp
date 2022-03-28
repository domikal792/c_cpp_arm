/// @file LogoPage.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAYAPP_LOGOPAGE_HPP
#define DISPLAYAPP_LOGOPAGE_HPP

#include "MonochromeView/DynamicView.hpp"
#include "PageIf.hpp"

class LogoPage :
    public PageIf
{
public:
    LogoPage(MonochromeView::DynamicView& rView);

    /// @copydoc PageIf::OnCreate
    void OnCreate() override;

    /// @copydoc PageIf::Refresh
    void Refresh() override;

private:
    MonochromeView::DynamicView& m_rView;
};

#endif
