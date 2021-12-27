/// @file LogoPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "LogoPage.hpp"
#include "../MonochromeGraphicLogoPolSl.hpp"

LogoPage::LogoPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void LogoPage::OnCreate() 
{
    m_rView.DrawAt(29, 0, logoPolSl);
}

void LogoPage::Refresh() 
{
    // Do nothing.
}
