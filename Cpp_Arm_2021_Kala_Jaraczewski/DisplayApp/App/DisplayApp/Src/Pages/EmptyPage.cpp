/// @file EmptyPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "EmptyPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont26x16.hpp"

EmptyPage::EmptyPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void EmptyPage::OnCreate() 
{
    // TODO: Add page setup. Print sth link "Empty Page" string on screen.
    MonochromeView::ConstView id = MonochromeText::font26x16.GetCharView('4');
    m_rView.DrawAt(53, 18, id, MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
}

void EmptyPage::Refresh() 
{
    // Do nothing.
}
