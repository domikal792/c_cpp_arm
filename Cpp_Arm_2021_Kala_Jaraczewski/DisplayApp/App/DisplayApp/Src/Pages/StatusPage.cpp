/// @file StatusPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>
#include <cstdio>

#include "main.h"

#include "StatusPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont10x7.hpp"
#include "MonochromeText/MonochromeText.hpp"

StatusPage::StatusPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void StatusPage::OnCreate() 
{
    constexpr const char LINE1[] = "Uptime:";
    constexpr const uint8_t DRAW_OPT = (MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
    MonochromeText::MonochromeText::WriteString(m_rView, 0, 21, MonochromeText::font10x7, LINE1, DRAW_OPT);

    Refresh();
}

void StatusPage::Refresh() 
{
    constexpr const char FORMAT[] = "%lu.%lus";
    constexpr const uint8_t DRAW_OPT = (MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
    constexpr const size_t BUF_SIZE = 30;
    static char buf[BUF_SIZE];
    const uint32_t nowMs = HAL_GetTick();
    const uint32_t timeIsSec = nowMs / 1000U;
    const uint32_t aTenthOfASec = (nowMs / 100U) % 10U;

    (void)std::memset(buf, 0, BUF_SIZE);
    (void)std::snprintf(buf, BUF_SIZE, FORMAT, timeIsSec, aTenthOfASec);

    MonochromeText::MonochromeText::WriteString(m_rView, 5, 33, MonochromeText::font10x7, buf, DRAW_OPT);
}
