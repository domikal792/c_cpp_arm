/// @file DisplayDataCmdImpl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include "DisplayDataCmdImpl.hpp"

namespace DisplayComm
{

DisplayDataCmdImpl::DisplayDataCmdImpl(GPIO_TypeDef * const pDcPort, 
                                       const uint32_t dcPin) :
    m_pDcPort(pDcPort),
    m_DcPin(dcPin)
{
    assert(pDcPort != nullptr);
}

void DisplayDataCmdImpl::EnableCmdMode() const 
{
    LL_GPIO_ResetOutputPin(m_pDcPort, m_DcPin);
}

void DisplayDataCmdImpl::EnableDataMode() const
{
    LL_GPIO_SetOutputPin(m_pDcPort, m_DcPin);
}

}
