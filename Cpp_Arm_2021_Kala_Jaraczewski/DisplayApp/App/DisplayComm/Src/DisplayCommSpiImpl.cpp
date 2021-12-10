/// @file DisplayCommSpiImpl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include "DisplayComm/DisplayDataCmdIf.hpp"
#include "DisplayCommSpiImpl.hpp"

namespace DisplayComm
{

constexpr const uint32_t DisplayCommSpiImpl::TXE_FLAG_CHECKS_MAX_NUM;

DisplayCommSpiImpl::DisplayCommSpiImpl(SPI_TypeDef* const pSpi,
                                       GPIO_TypeDef* const pCsPort, 
                                       const uint32_t csPin,
                                       const DisplayDataCmdIf* const pDataCmdIf) :
    m_pSpi(pSpi),
    m_pCsPort(pCsPort),
    m_CsPin(csPin),
    m_pDataCmdIf(pDataCmdIf)
{
    assert(pSpi != nullptr);
    assert(pCsPort != nullptr);
    assert(pDataCmdIf != nullptr);
}

bool DisplayCommSpiImpl::WriteCmd(const uint8_t cmd) const 
{
    uint32_t txeCheckCounter = 0U;
    LL_GPIO_ResetOutputPin(m_pCsPort, m_CsPin);
    m_pDataCmdIf->EnableCmdMode();
    LL_SPI_Enable(m_pSpi);

    LL_SPI_TransmitData8(m_pSpi, cmd);
    while((LL_SPI_IsActiveFlag_BSY(m_pSpi)) &&
          (++txeCheckCounter < TXE_FLAG_CHECKS_MAX_NUM));

    LL_SPI_Disable(m_pSpi);

    LL_GPIO_SetOutputPin(m_pCsPort, m_CsPin);

    return (txeCheckCounter < TXE_FLAG_CHECKS_MAX_NUM);
}

bool DisplayCommSpiImpl::WriteData(const uint8_t* const pData, const size_t dataSize) const 
{
    uint32_t txeCheckCounter = 0U;
    LL_GPIO_ResetOutputPin(m_pCsPort, m_CsPin);
    m_pDataCmdIf->EnableDataMode();
    LL_SPI_Enable(m_pSpi);

    for(uint8_t i = 0U; (i < dataSize) && (txeCheckCounter < TXE_FLAG_CHECKS_MAX_NUM); ++i)
    {
        txeCheckCounter = 0U;
        LL_SPI_TransmitData8(m_pSpi, pData[i]);
        while((LL_SPI_IsActiveFlag_BSY(m_pSpi)) &&
              (++txeCheckCounter < TXE_FLAG_CHECKS_MAX_NUM));
    }

    LL_SPI_Disable(m_pSpi);
    LL_GPIO_SetOutputPin(m_pCsPort, m_CsPin);

    return (txeCheckCounter < TXE_FLAG_CHECKS_MAX_NUM);
}

}
