/// @file DisplayCommIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_DISPLAY_COMM_IF_HPP
#define DISPLAY_COMM_DISPLAY_COMM_IF_HPP

#include <cstdint>
#include <cstddef>

namespace DisplayComm
{

/// Interface for communication with display.
class DisplayCommIf
{
public:
    virtual ~DisplayCommIf()
    {
    }

    /// Write command to the display.
    /// 
    /// @param cmd Command code.
    ///
    /// @return Write result.
    virtual bool WriteCmd(const uint8_t cmd) const = 0;

    /// Write data to the display.
    /// 
    /// @param pData Pointer to the data buffer.
    /// @param dataSize Data size in bytes.
    ///
    /// @return Write result.
    virtual bool WriteData(const uint8_t* const pData, const size_t dataSize) const = 0;
};

}

#endif
