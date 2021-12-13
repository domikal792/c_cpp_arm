/// @file DisplayDriverIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_DISPLAYDRIVERIF_HPP
#define MONOCHROMEGRAPHICDISPLAY_DISPLAYDRIVERIF_HPP

#include <cstdint>
#include <cstddef>

namespace MonochromeGraphicDisplay
{

/// Diver interface of graphical screens.
class DisplayDriverIf
{
    virtual ~DisplayDriverIf()
    {
    }

    /// Turns on display.
    /// 
    /// @return Result.
    virtual bool TurnOnDisplay() = 0;

    /// Turns off display.
    /// 
    /// @return Result.
    virtual bool TurnOffDisplay() = 0;

    /// Inverse display colors.
    /// 
    /// @param color [0 - normal, 1 - inversed]
    ///
    /// @return Result.
    virtual bool InverseColor(bool inverse) = 0;

    /// Set the contrast.
    /// 
    /// @param value Contrast [0u..255u].
    ///
    /// @return Result.
    virtual bool SetContrast(uint8_t value) = 0;

    /// Refresh screen.
    /// 
    /// @return Result.
    virtual bool RefreshScreen() = 0;

    /// Get the column buffer.
    /// 
    /// @param rowIdx [0u..ceil(GetScreenHeight() / 8)] index of an row, starting at left-top corner.
    ///
    /// @return Buffer with length of GetWidth() bytes.
    virtual uint8_t* GetRowBuffer(const size_t rowIdx) = 0;

    /// Get the display width.
    /// 
    /// @return Width in pixels. 
    virtual size_t GetWidth() = 0;

    /// Get the display height.
    /// 
    /// @return Height in pixels. 
    virtual size_t GetHeight() = 0;
};

}

#endif
