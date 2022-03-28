/// @file DisplayDataCmdIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_DISPLAY_DATA_CMD_IF_HPP
#define DISPLAY_COMM_DISPLAY_DATA_CMD_IF_HPP

namespace DisplayComm
{

/// Interface for changing mode of the display.
class DisplayDataCmdIf
{
public:
    virtual ~DisplayDataCmdIf()
    {
    }

    /// Enable command mode in the display.
    virtual void EnableCmdMode() const = 0;

    /// Enable data mode in the display.
    virtual void EnableDataMode() const = 0;
};

}

#endif
