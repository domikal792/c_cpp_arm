/// @file EmptyPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "EmptyPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont10x7.hpp"
#include "MonochromeText/MonochromeText.hpp"

EmptyPage::EmptyPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void EmptyPage::OnCreate() 
{
    constexpr const char LINE1[] = "Pusta strona";
    constexpr const uint8_t DRAW_OPT = (MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
    MonochromeText::MonochromeText::WriteString(m_rView, 0, 27, MonochromeText::font10x7, LINE1, DRAW_OPT);
}

void EmptyPage::Refresh() 
{
    // Do nothing.
}
