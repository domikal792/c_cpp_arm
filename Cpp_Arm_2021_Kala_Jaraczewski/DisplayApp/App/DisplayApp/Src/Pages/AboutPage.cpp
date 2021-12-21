/// @file AboutPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "AboutPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont26x16.hpp"

AboutPage::AboutPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void AboutPage::OnCreate() 
{
    // TODO: Add page setup. Add information about authors and course. Print with MonochromeText::WriteString
    MonochromeView::ConstView id = MonochromeText::font26x16.GetCharView('2');
    m_rView.DrawAt(53, 18, id, MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
}

void AboutPage::Refresh() 
{
    // Do nothing.
}
