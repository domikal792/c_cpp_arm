/// @file DisplayCommSpiImpl.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_DISPLAY_COMM_SPI_IMPL_HPP
#define DISPLAY_COMM_DISPLAY_COMM_SPI_IMPL_HPP

#include <cstdint>

#include "spi.h"
#include "gpio.h"

#include "DisplayComm/DisplayCommIf.hpp"

namespace DisplayComm
{

class DisplayDataCmdIf;

/// Implementation of SPI communication driver for the display.
class DisplayCommSpiImpl :
    public DisplayCommIf
{
public:
    /// Constructor of display comm implementation class. 
    ///
    /// @param pSpi Pointer to the SPI interface.
    /// @param pCsPort Port of the chip select pin.
    /// @param csPin Chip select pin.
    /// @param pDataCmdIf Pointer to data command interface.
    DisplayCommSpiImpl(SPI_TypeDef* const pSpi,
                       GPIO_TypeDef* const pCsPort, 
                       const uint32_t csPin,
                       const DisplayDataCmdIf* const pDataCmdIf);

    /// @copydoc DisplayComm::DisplayCommIf::WriteCmd
    bool WriteCmd(const uint8_t cmd) const override;

    /// @copydoc DisplayComm::DisplayCommIf::WriteData
    bool WriteData(const uint8_t* const pData, const size_t dataSize) const override;

private:
    static constexpr const uint32_t TXE_FLAG_CHECKS_MAX_NUM = 1000U; 

    SPI_TypeDef* const m_pSpi;
    GPIO_TypeDef* const m_pCsPort;
    const uint32_t m_CsPin;
    const DisplayDataCmdIf* const m_pDataCmdIf;
};

}

#endif
