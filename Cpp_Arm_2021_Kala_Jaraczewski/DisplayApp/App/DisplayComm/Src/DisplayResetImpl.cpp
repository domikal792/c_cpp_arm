/// @file DisplayResetImpl.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"
#include "stm32f1xx_ll_utils.h"

#include "DisplayResetImpl.hpp"

namespace DisplayComm
{

DisplayResetImpl::DisplayResetImpl(GPIO_TypeDef* const pResetPort, 
                                   const uint32_t resetPin) :
    m_pResetPort(pResetPort),
    m_ResetPin(resetPin)
{
    assert(pResetPort != nullptr);
}

void DisplayResetImpl::Reset() const 
{
    LL_GPIO_ResetOutputPin(m_pResetPort, m_ResetPin);
    LL_mDelay(10U);
    LL_GPIO_SetOutputPin(m_pResetPort, m_ResetPin);
    LL_mDelay(110U);
}

}
