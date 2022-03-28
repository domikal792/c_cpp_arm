/// @file DisplayResetIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAY_COMM_DISPLAY_RESET_IF_HPP
#define DISPLAY_COMM_DISPLAY_RESET_IF_HPP

namespace DisplayComm
{

/// Interface for the reseting display.
class DisplayResetIf
{
public:
    virtual ~DisplayResetIf()
    {
    }

    /// Reset display.
    virtual void Reset() const = 0;
};

}

#endif
