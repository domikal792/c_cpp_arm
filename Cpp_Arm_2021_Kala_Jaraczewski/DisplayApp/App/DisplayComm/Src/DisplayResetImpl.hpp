/// @file DisplayResetImpl.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_DISPLAY_RESET_IMPL_HPP
#define DISPLAY_COMM_DISPLAY_RESET_IMPL_HPP

#include <cstdint>

#include "gpio.h"

#include "DisplayComm/DisplayResetIf.hpp"

namespace DisplayComm
{

/// Implementation of display reset.
class DisplayResetImpl :
    public DisplayResetIf
{
public:
    /// Constructor of display reset class.
    /// 
    /// @param pResetPort Port of the reset pin.
    /// @param resetPin Reset pin number.
    DisplayResetImpl(GPIO_TypeDef* const pResetPort, 
                     const uint32_t resetPin);

    /// @copydoc DisplayComm::DisplayResetIf::Reset
    void Reset() const override;

private:
    GPIO_TypeDef* const m_pResetPort;
    const uint32_t m_ResetPin;
};

}

#endif
