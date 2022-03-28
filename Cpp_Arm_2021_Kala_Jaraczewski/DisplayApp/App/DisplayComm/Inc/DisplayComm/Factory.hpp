/// @file Factory.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_FACTORY_HPP
#define DISPLAY_COMM_FACTORY_HPP

#include <cstdint>

#include "spi.h"
#include "gpio.h"

namespace DisplayComm
{

class DisplayCommIf;
class DisplayResetIf;
class DisplayDataCmdIf;

/// Factory for display communication layer.
class Factory
{
public:
    /// Create a display reset object.
    /// 
    /// @param pResetPort Port of the reset pin.
    /// @param resetPin Reset pin number.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return DisplayResetIf* Pointer to a newly allocated reset object. 
    static DisplayResetIf* CreateDisplayReset(GPIO_TypeDef* const pResetPort, 
                                              const uint32_t resetPin);

    /// Create a data command driver object.
    /// 
    /// @param pDcPort Port of D/C pin.
    /// @param dcPin D/C pin number.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return DisplayResetIf* Pointer to a newly allocated D/C driver object. 
    static DisplayDataCmdIf* CreateDataCmd(GPIO_TypeDef * const pDcPort, 
                                           const uint32_t dcPin);

    /// Create a display comm object.
    /// 
    /// @param pSpi Pointer to the SPI interface.
    /// @param pCsPort Port of the chip select pin.
    /// @param csPin Chip select pin.
    /// @param pDataCmdIf Pointer to data command interface.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return DisplayCommIf* Pointer to a newly allocated communication driver object. 
    static DisplayCommIf* CreateDisplayCommSpi(SPI_TypeDef* const pSpi,
                                               GPIO_TypeDef* const pCsPort, 
                                               const uint32_t csPin,
                                               const DisplayDataCmdIf* const pDataCmdIf);

private:
    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;
};

}

#endif
