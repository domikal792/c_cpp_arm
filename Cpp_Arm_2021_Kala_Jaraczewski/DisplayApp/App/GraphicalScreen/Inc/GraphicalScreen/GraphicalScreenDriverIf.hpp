/// @file GraphicalScreenDriverIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef GRAPHICALSCREEN_GRAPHICALSCREENDRIVERIF_HPP
#define GRAPHICALSCREEN_GRAPHICALSCREENDRIVERIF_HPP

#include <cstdint>
#include <cstddef>

namespace GraphicalScreen
{

class GraphicalScreenDriverIf
{
    /// Turns on display
    /// 
    /// @return true 
    /// @return false 
    virtual bool TurnOnDisplay() = 0;

    /// Turns off display
    /// 
    /// @return true 
    /// @return false 
    virtual bool TurnOffDisplay() = 0;

    /// Set the Color object
    /// 
    /// @param color [0 - normal, 1 - inversed]
    /// @return true 
    /// @return false 
    virtual bool SetColor(bool color) = 0;

    /// Set the Contrast object
    /// 
    /// @param value contrast [0u..255u]
    /// @return true 
    /// @return false 
    virtual bool SetContrast(uint8_t value) = 0;

    /// Update screen
    /// 
    /// @return true 
    /// @return false 
    virtual bool UpdateScreen() = 0;

    /// Get the Buffer object
    /// 
    /// @return uint8_t* 
    virtual uint8_t* GetBuffer() = 0;

    /// Get the Screen Width object
    /// 
    /// @return uint8_t 
    virtual uint8_t GetScreenWidth() = 0;

    /// Get the Screen Height object
    /// 
    /// @return uint8_t 
    virtual uint8_t GetScreenHeight() = 0;

};

}

#endif