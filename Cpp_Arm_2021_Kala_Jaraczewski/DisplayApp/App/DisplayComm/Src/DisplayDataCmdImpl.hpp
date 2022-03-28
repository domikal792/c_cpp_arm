/// @file DisplayDataCmdImpl.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_DISPLAY_DATA_CMD_IMPL_HPP
#define DISPLAY_COMM_DISPLAY_DATA_CMD_IMPL_HPP

#include <cstdint>

#include "gpio.h"

#include "DisplayComm/DisplayDataCmdIf.hpp"

namespace DisplayComm
{

/// Implementation of driver for changing device mode.
class DisplayDataCmdImpl :
    public DisplayDataCmdIf
{
public:
    /// Constructor of data command driver class.
    /// 
    /// @param pDcPort Port of D/C pin.
    /// @param dcPin D/C pin number.
    DisplayDataCmdImpl(GPIO_TypeDef * const pDcPort, 
                       const uint32_t dcPin);

    /// @copydoc DisplayComm::DisplayDataCmdIf::EnableCmdMode
    void EnableCmdMode() const override;

    /// @copydoc DisplayComm::DisplayDataCmdIf::EnableDataMode
    void EnableDataMode() const override;

private:
    GPIO_TypeDef* const m_pDcPort;
    const uint32_t m_DcPin;
};

}

#endif
