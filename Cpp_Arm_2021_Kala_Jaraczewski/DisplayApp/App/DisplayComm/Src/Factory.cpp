/// @file Factory.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <new>

#include "assert.h"

#include "DisplayComm/Factory.hpp"
#include "DisplayResetImpl.hpp"
#include "DisplayDataCmdImpl.hpp"
#include "DisplayCommSpiImpl.hpp"

namespace DisplayComm
{

DisplayResetIf* Factory::CreateDisplayReset(GPIO_TypeDef* const pResetPort, 
                                            const uint32_t resetPin)
{
    assert(pResetPort != nullptr);
    DisplayResetIf* pDisplayResetIf = new (std::nothrow) DisplayResetImpl(pResetPort, resetPin);
    assert(pDisplayResetIf != nullptr);
    return pDisplayResetIf;
}

DisplayDataCmdIf* Factory::CreateDataCmd(GPIO_TypeDef * const pDcPort, 
                                         const uint32_t dcPin)
{
    assert(pDcPort != nullptr);
    DisplayDataCmdIf* pDisplayDataCmdIf = new (std::nothrow) DisplayDataCmdImpl(pDcPort, dcPin);
    assert(pDisplayDataCmdIf != nullptr);
    return pDisplayDataCmdIf;
}

DisplayCommIf* Factory::CreateDisplayCommSpi(SPI_TypeDef* const pSpi,
                                             GPIO_TypeDef* const pCsPort, 
                                             const uint32_t csPin,
                                             const DisplayDataCmdIf* const pDataCmdIf)
{
    assert(pSpi != nullptr);
    assert(pCsPort != nullptr);
    assert(pDataCmdIf != nullptr);
    DisplayCommIf* pDisplayCommIf = new (std::nothrow) DisplayCommSpiImpl(pSpi, pCsPort, csPin, pDataCmdIf);
    assert(pDisplayCommIf);
    return pDisplayCommIf;
}

}
