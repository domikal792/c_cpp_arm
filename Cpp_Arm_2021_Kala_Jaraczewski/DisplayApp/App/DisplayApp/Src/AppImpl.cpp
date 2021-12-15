/// @file AppImpl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <cstring>

#include "main.h"
#include "DischFirmwareSH1106.h"
#include "DischFirmwarePhotos.h"

#include "AppImpl.hpp"
#include "DisplayComm/Factory.hpp"
#include "DisplayComm/DisplayResetIf.hpp"
#include "DisplayComm/DisplayDataCmdIf.hpp"
#include "DisplayComm/DisplayCommIf.hpp"
#include "Sh1106/Factory.hpp"
#include "MonochromeGraphicDisplay/DisplayDriverIf.hpp"
#include "MonochromeView/ConstView.hpp"
#include "MonochromeView/DynamicView.hpp"

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

    m_pDisplayDriver.reset(Sh1106::Factory::Create128x64Driver(m_pDisplayComm.get(), m_pDisplayReset.get()));

    MonochromeView::ConstView photo(disch::firmware::sgLogoPhoto.getData(), 128U, 64U);
    m_pDisplayDriver->GetView().Draw(0U, 0U, photo);
    m_pDisplayDriver->RefreshScreen();


//    SH1106::getInstance().setCommInterface(m_pDisplayComm.get(), m_pDisplayReset.get());
//    SH1106::getInstance().init();
//
//    SH1106::getInstance().displayPhoto(disch::firmware::sgLogoPhoto);

//    constexpr const char ARM_CPP[] = "ARM CPP";
//    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(ARM_CPP) - 1) * 16) / 2, 0 });
//    SH1106::getInstance().writeString(ARM_CPP, font16x26, SH1106::COLOR_BLUE);
//
//    constexpr const char Y2021[] = "2021";
//    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(Y2021) - 1) * 7) / 2, 28 });
//    SH1106::getInstance().writeString(Y2021, font7x10, SH1106::COLOR_BLUE);
//
//    constexpr const char KALA_JARACZEWSKI[] = "Kala, Jaraczewski";
//    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(KALA_JARACZEWSKI) - 1) * 7) / 2, 40 });
//    SH1106::getInstance().writeString(KALA_JARACZEWSKI, font7x10, SH1106::COLOR_BLUE);
//
//    constexpr const char TELEINFORMATYKA[] = "Teleinformatyka";
//    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(TELEINFORMATYKA) - 1) * 6) / 2, 52 });
//    SH1106::getInstance().writeString(TELEINFORMATYKA, font6x8, SH1106::COLOR_BLUE);
//
//    SH1106::getInstance().updateScreen();
}

AppImpl::~AppImpl()
{

}

void AppImpl::Tick()
{
    LL_mDelay(500);
    static bool inverse = false;
    static uint8_t contrast = 255;
    m_pDisplayDriver->InverseColor(inverse);
    m_pDisplayDriver->SetContrast(contrast);
    contrast -= 5;
    inverse = !inverse;
}

#ifdef DEBUG
void AppImpl::DebugTick()
{

}
#endif
