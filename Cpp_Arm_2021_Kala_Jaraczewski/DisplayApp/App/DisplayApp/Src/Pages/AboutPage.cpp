/// @file AboutPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "AboutPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont18x11.hpp"
#include "MonochromeText/Fonts/MonochromeFont10x7.hpp"
#include "MonochromeText/MonochromeText.hpp"

AboutPage::AboutPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void AboutPage::OnCreate() 
{
    constexpr const char LINE1[] = "Arm Cpp";
    constexpr const char LINE2[] = "Autorzy:";
    constexpr const char LINE3[] = "-Kala";
    constexpr const char LINE4[] = "-Jaraczewski";
    constexpr const uint8_t DRAW_OPT = (MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
    MonochromeText::MonochromeText::WriteString(m_rView, 0, 0, MonochromeText::font18x11, LINE1, DRAW_OPT);
    m_rView.DrawLine(0, 20, m_rView.Width() - 1, 20, true);
    MonochromeText::MonochromeText::WriteString(m_rView, 0, 23, MonochromeText::font10x7, LINE2, DRAW_OPT);
    MonochromeText::MonochromeText::WriteString(m_rView, 5, 35, MonochromeText::font10x7, LINE3, DRAW_OPT);
    MonochromeText::MonochromeText::WriteString(m_rView, 5, 47, MonochromeText::font10x7, LINE4, DRAW_OPT);
}

void AboutPage::Refresh() 
{
    // Do nothing.
}
