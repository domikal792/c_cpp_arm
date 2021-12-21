/// @file LogoPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "LogoPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont26x16.hpp"

LogoPage::LogoPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void LogoPage::OnCreate() 
{
    // TODO: Add page setup. Display logo of polsl.
    MonochromeView::ConstView id = MonochromeText::font26x16.GetCharView('1');
    m_rView.DrawAt(53, 18, id, MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
}

void LogoPage::Refresh() 
{
    // Do nothing.
}
