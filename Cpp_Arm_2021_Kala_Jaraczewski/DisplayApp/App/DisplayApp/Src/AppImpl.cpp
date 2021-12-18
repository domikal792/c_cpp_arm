/// @file AppImpl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>

#include "assert.h"

#include "AppImpl.hpp"
#include "DisplayComm/DisplayCommIf.hpp"
#include "DisplayComm/DisplayDataCmdIf.hpp"
#include "DisplayComm/DisplayResetIf.hpp"
#include "DisplayComm/Factory.hpp"
#include "MonochromeGraphicDisplay/DisplayDriverIf.hpp"
#include "MonochromeGraphicDisplay/Fonts/MonochromeFont26x16.hpp"
#include "MonochromeGraphicDisplay/Fonts/MonochromeFont11x18.hpp"
#include "MonochromeGraphicDisplay/Fonts/MonochromeFont7x10.hpp"
#include "MonochromeGraphicDisplay/Fonts/MonochromeFont6x8.hpp"
#include "MonochromeView/ConstStorageView.hpp"
#include "MonochromeView/ConstView.hpp"
#include "MonochromeView/DynamicView.hpp"
#include "Sh1106/Factory.hpp"

using namespace disch::firmware;

AppImpl::AppImpl(const AppInitStruct* const pAppInitStruct)
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
}

AppImpl::~AppImpl()
{

}

void AppImpl::Tick()
{

}

#ifdef DEBUG
void AppImpl::DebugTick()
{
    volatile static uint32_t dbgType = 6U;

    if (dbgType == 1U)
    {
        static const MonochromeView::ConstView photo(disch::firmware::sgLogoPhoto.getData(), 128U, 64U);
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
        m_pDisplayDriver->GetView().DrawAt(x, y, photo, drawOption1);
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

        MonochromeView::ConstView chView = MonochromeGraphicDisplay::font26x16.GetCharView(c);

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

        MonochromeView::ConstView chView = MonochromeGraphicDisplay::font26x16.GetCharView(c);

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

        MonochromeView::ConstView chView = MonochromeGraphicDisplay::font8x6.GetCharView(c);

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
}
#endif
