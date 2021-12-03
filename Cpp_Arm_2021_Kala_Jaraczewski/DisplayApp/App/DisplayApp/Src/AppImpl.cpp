/// @file AppImpl.cpp

#include "AppImpl.hpp"
#include "DischFirmwareSH1106.h"

using namespace disch::firmware;

AppImpl::AppImpl(const AppInitStruct* const pAppInitStruct)
{
    SH1106::getInstance().setSpiInterface(
            pAppInitStruct->m_pDisplaySpiInterface->m_pSpi,
            pAppInitStruct->m_pDisplaySpiInterface->m_pCsPort,
            pAppInitStruct->m_pDisplaySpiInterface->m_CsPin,
            pAppInitStruct->m_pDisplaySpiInterface->m_pDcPort,
            pAppInitStruct->m_pDisplaySpiInterface->m_DcPin,
            pAppInitStruct->m_pDisplaySpiInterface->m_pResPort,
            pAppInitStruct->m_pDisplaySpiInterface->m_ResPin
    );
    SH1106::getInstance().init();

    constexpr const char ARM_CPP[] = "ARM CPP";
    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(ARM_CPP) - 1) * 16) / 2, 0 });
    SH1106::getInstance().writeString(ARM_CPP, font16x26, SH1106::COLOR_BLUE);

    constexpr const char Y2021[] = "2021";
    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(Y2021) - 1) * 7) / 2, 28 });
    SH1106::getInstance().writeString("2021", font7x10, SH1106::COLOR_BLUE);

    constexpr const char KALA_JARACZEWSKI[] = "Kala, Jaraczewski";
    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(KALA_JARACZEWSKI) - 1) * 7) / 2, 40 });
    SH1106::getInstance().writeString(KALA_JARACZEWSKI, font7x10, SH1106::COLOR_BLUE);

    constexpr const char TELEINFORMATYKA[] = "Teleinformatyka";
    SH1106::getInstance().setCursor({ (SH1106::WIDTH - (sizeof(TELEINFORMATYKA) - 1) * 6) / 2, 52 });
    SH1106::getInstance().writeString(TELEINFORMATYKA, font6x8, SH1106::COLOR_BLUE);

    SH1106::getInstance().updateScreen();
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

}
#endif
