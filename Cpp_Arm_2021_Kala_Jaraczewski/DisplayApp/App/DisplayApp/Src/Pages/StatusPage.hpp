/// @file StatusPage.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAYAPP_STATUSPAGE_HPP
#define DISPLAYAPP_STATUSPAGE_HPP

#include "MonochromeView/DynamicView.hpp"
#include "PageIf.hpp"

class StatusPage :
    public PageIf
{
public:
    StatusPage(MonochromeView::DynamicView& rView);

    /// @copydoc PageIf::OnCreate
    void OnCreate() override;

    /// @copydoc PageIf::Refresh
    void Refresh() override;

private:
    MonochromeView::DynamicView& m_rView;
};

#endif
