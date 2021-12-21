/// @file StatusPage.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>
#include <cstdio>

#include "main.h"

#include "StatusPage.hpp"
#include "MonochromeText/Fonts/MonochromeFont26x16.hpp"

StatusPage::StatusPage(MonochromeView::DynamicView& rView) :
    m_rView(rView)
{
}

void StatusPage::OnCreate() 
{
    // Just refresh
    Refresh();

    // TODO: Remove the following.
    MonochromeView::ConstView id = MonochromeText::font26x16.GetCharView('3');
    m_rView.DrawAt(53, 18, id, MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR);
}

void StatusPage::Refresh() 
{
    constexpr const char FORMAT[] = "Uptime: %lu.%lus";
    constexpr const size_t BUF_SIZE = 30;
    static char buf[BUF_SIZE];
    const uint32_t nowMs = HAL_GetTick();
    const uint32_t timeIsSec = nowMs / 1000U;
    const uint32_t aTenthOfASec = (nowMs / 100U) % 10U;

    (void)std::memset(buf, 0, BUF_SIZE);
    (void)std::snprintf(buf, BUF_SIZE, FORMAT, timeIsSec, aTenthOfASec);

    // TODO: Write prepared string into view.
}
