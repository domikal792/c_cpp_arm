/// @file AppImpl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>

#include "assert.h"
#include "main.h"

#include "AppImpl.hpp"
#include "DisplayComm/DisplayCommIf.hpp"
#include "DisplayComm/DisplayDataCmdIf.hpp"
#include "DisplayComm/DisplayResetIf.hpp"
#include "DisplayComm/Factory.hpp"
#include "MonochromeGraphicDisplay/DisplayDriverIf.hpp"
#include "Sh1106/Factory.hpp"

AppImpl::AppImpl(const AppInitStruct* const pAppInitStruct) :
    m_ActivePage(0U),
    m_LastScreenRefreshMs(0U),
    m_LastAutoscrollMs(0U),
    m_VertScrollbarFrameView(),
    m_VertScrollbarView(),
    m_LogPage(m_Pages[0U].m_View),
    m_AboutPage(m_Pages[1U].m_View),
    m_StatusPage(m_Pages[2U].m_View),
    m_EmptyPage(m_Pages[3U].m_View)
{
    m_pDisplayReset.reset(DisplayComm::Factory::CreateDisplayReset(
        pAppInitStruct->m_pDisplaySpiInterface->m_pResPort,
        pAppInitStruct->m_pDisplaySpiInterface->m_ResPin
    ));

    m_pDisplayDataCmd.reset(DisplayComm::Factory::CreateDataCmd(
        pAppInitStruct->m_pDisplaySpiInterface->m_pDcPort,
        pAppInitStruct->m_pDisplaySpiInterface->m_DcPin
    ));

    m_pDisplayComm.reset(DisplayComm::Factory::CreateDisplayCommSpi(
        pAppInitStruct->m_pDisplaySpiInterface->m_pSpi,
        pAppInitStruct->m_pDisplaySpiInterface->m_pCsPort,
        pAppInitStruct->m_pDisplaySpiInterface->m_CsPin,
        m_pDisplayDataCmd.get()
    ));

    m_pDisplayDriver.reset(Sh1106::Factory::Create128x64Driver(
        m_pDisplayComm.get(),
        m_pDisplayReset.get(),
        false,
        false,
        2U
    ));

    assert(m_pDisplayReset);
    assert(m_pDisplayDataCmd);
    assert(m_pDisplayComm);
    assert(m_pDisplayDriver);

    m_Pages[0U].m_pPageIf = &m_LogPage;
    m_Pages[1U].m_pPageIf = &m_AboutPage;
    m_Pages[2U].m_pPageIf = &m_StatusPage;
    m_Pages[3U].m_pPageIf = &m_EmptyPage;

    for (size_t i = 0U; i < PAGES_NUM; ++i)
    {
        assert(m_Pages[i].m_pPageIf != nullptr);
        m_Pages[i].m_pPageIf->OnCreate();
    }

    RefreshScrollbar();
    RefreshScreen();
}

AppImpl::~AppImpl()
{

}

void AppImpl::Tick()
{
    RefreshScreen();
}

void AppImpl::RefreshScreen()
{
    const uint32_t nowMs = HAL_GetTick();
    const uint32_t refreshScreenDuration = nowMs - m_LastScreenRefreshMs;

    if (refreshScreenDuration < SCREEN_REFRESH_MS)
    {
        return;
    }

    m_LastScreenRefreshMs = nowMs;
    MonochromeView::DynamicView& rDisplayView = m_pDisplayDriver->GetView();
    bool activePageChanged = false;
    const uint32_t autoscrollDuration = nowMs - m_LastAutoscrollMs;

    if (autoscrollDuration >= AUTOSCROLL_MS)
    {
        // Update scrollbar and active page.
        m_LastAutoscrollMs = nowMs;
        m_ActivePage = (m_ActivePage + 1U) % PAGES_NUM;
        RefreshScrollbar();
        activePageChanged = true;
    }

    // Refresh page.
    m_Pages[m_ActivePage].m_pPageIf->Refresh();

    const bool viewChanged = m_Pages[m_ActivePage].m_View.IfViewChanged();

    if (activePageChanged || viewChanged)
    {
        rDisplayView.DrawAt(PAGE_X_COORD, PAGE_Y_COORD, m_Pages[m_ActivePage].m_View);
        m_pDisplayDriver->RefreshScreen();
    }
}

void AppImpl::RefreshScrollbar()
{
    constexpr const int32_t X_SCROLLBAR_POSITION = 1;
    int32_t yScrollbarPosition = static_cast<int32_t>(m_ActivePage) * VERT_SCROLLBAR_HEIGHT;

    MonochromeView::DynamicView& rDisplayView = m_pDisplayDriver->GetView();

    if (yScrollbarPosition == 0)
    {
        yScrollbarPosition = 1U;
    }

    if ((static_cast<size_t>(yScrollbarPosition) + m_VertScrollbarView.Height()) >= VERT_SCROLLBAR_FRAME_HEIGHT)
    {
        yScrollbarPosition = VERT_SCROLLBAR_FRAME_HEIGHT - m_VertScrollbarView.Height() - 1U;
    }
    
    m_VertScrollbarFrameView.Fill(true);
    m_VertScrollbarFrameView.DrawAt(X_SCROLLBAR_POSITION, yScrollbarPosition, m_VertScrollbarView);

    rDisplayView.DrawAt(VERT_SCROLLBAR_FRAME_X_COORD, VERT_SCROLLBAR_FRAME_Y_COORD, m_VertScrollbarFrameView);
}

#ifdef DEBUG

#include "MonochromeGraphicLogoPolSl.hpp"
#include "MonochromeText/Fonts/MonochromeFont10x7.hpp"
#include "MonochromeText/Fonts/MonochromeFont18x11.hpp"
#include "MonochromeText/Fonts/MonochromeFont26x16.hpp"
#include "MonochromeText/Fonts/MonochromeFont8x6.hpp"
#include "MonochromeView/ConstStorageView.hpp"
#include "MonochromeView/ConstView.hpp"
#include "MonochromeView/DynamicStorageView.hpp"
#include "MonochromeView/DynamicView.hpp"

void AppImpl::DebugTick()
{
    volatile static uint32_t dbgType = 0U;

    if (dbgType == 1U)
    {
        static int32_t x = -128;
        static int32_t y = -64;
        static bool inverse = false;
        static uint8_t contrast = 255;
        static uint8_t cnt = 0;
        volatile static uint8_t drawOption1 = MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR;

        LL_mDelay(10);

        if (cnt++ >= 50U)
        {
            m_pDisplayDriver->InverseColor(inverse);
            m_pDisplayDriver->SetContrast(contrast);
            contrast -= 5;
            inverse = !inverse;
            cnt = 0U;
        }

        m_pDisplayDriver->GetView().Fill(false);
        m_pDisplayDriver->GetView().DrawAt(x, y, logoPolSl, drawOption1);
        m_pDisplayDriver->RefreshScreen();

        x += 2;
        y += 1;
        if (x == 128)
        {
            x = -128;
            y = -64;
            drawOption1 = (drawOption1 + 1) % 8;
        }
    }

    if (dbgType == 2U)
    {
        volatile static uint8_t drawOption2 = MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR;
        volatile static char c = 'P';
        static int8_t y = 0;

        MonochromeView::ConstView chView = MonochromeText::font26x16.GetCharView(c);

        m_pDisplayDriver->GetView().Fill(false);
        m_pDisplayDriver->GetView().DrawAt(10, y, chView, drawOption2);
        m_pDisplayDriver->RefreshScreen();

        ++y;
        LL_mDelay(30U);
    }

    if (dbgType == 3U)
    {
        volatile static uint8_t drawOption3 = MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR | MonochromeView::DRAW_OPT_NEGATIVE_COLORS;
        volatile static char c = 'P';
        static int8_t x = 0;

        MonochromeView::ConstView chView = MonochromeText::font26x16.GetCharView(c);

        m_pDisplayDriver->GetView().Fill(true);
        m_pDisplayDriver->GetView().DrawAt(x, 10, chView, drawOption3);
        m_pDisplayDriver->RefreshScreen();

        ++x;
        LL_mDelay(30U);
    }

    if (dbgType == 4U)
    {
        m_pDisplayDriver->InverseColor(true);
    }

    if (dbgType == 5U)
    {
        m_pDisplayDriver->InverseColor(false);
    }

    if (dbgType == 6U)
    {
        volatile static uint8_t drawOption4 = MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR;
        volatile static char c = ' ';
        static int8_t x = 0;
        static uint8_t cnt = 0U;

        MonochromeView::ConstView chView = MonochromeText::font8x6.GetCharView(c);

        m_pDisplayDriver->GetView().Fill(false);
        m_pDisplayDriver->GetView().DrawAt(x, 10, chView, drawOption4);
        m_pDisplayDriver->RefreshScreen();

        ++x;

        if ((cnt++ == 10U))
        {
            cnt = 0U;
            if (++c >= '~')
            {
                c = ' ';
            }
        }

        LL_mDelay(30U);
    }

    if (dbgType == 7U)
    {
        static MonochromeView::DynamicStorageView<35, 35> frame;
        volatile static uint8_t drawOption5 = MonochromeView::DRAW_OPT_TRANSPOSE | MonochromeView::DRAW_OPT_Y_MIRROR | MonochromeView::DRAW_OPT_NEGATIVE_COLORS;
        volatile static uint8_t drawOption6 = MonochromeView::DRAW_OPT_NONE;
        volatile static char c = 'P';
        static int8_t x = 0;

        frame.Fill(true);
        MonochromeView::ConstView chView = MonochromeText::font8x6.GetCharView(c);
        frame.DrawAt(15, 14, chView, drawOption5);

        m_pDisplayDriver->GetView().Fill(false);
        m_pDisplayDriver->GetView().DrawAt(x, 10, frame, drawOption6);
        m_pDisplayDriver->RefreshScreen();

        ++x;

        LL_mDelay(30U);
    }

    if (dbgType == 8U)
    {
        static int8_t x2 = 0;
        m_pDisplayDriver->GetView().Fill(false);
        m_pDisplayDriver->GetView().DrawLine(0, 0, x2, 63, true);
        m_pDisplayDriver->RefreshScreen();

        ++x2;
        LL_mDelay(30U);
    }
}
#endif
