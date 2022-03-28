/// @file Sh1106Impl.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef SH1106_SH1106_IMPL_HPP
#define SH1106_SH1106_IMPL_HPP

#include <cstdint>
#include <cstddef>

#include "MonochromeGraphicDisplay/DisplayDriverIf.hpp"
#include "MonochromeView/DynamicView.hpp"

namespace DisplayComm
{

class DisplayCommIf;
class DisplayResetIf;

}

namespace Sh1106
{

/// Implementation of SH1106 driver.
/// 
/// @tparam WIDTH Width of the display.
/// @tparam HEIGHT Height of the display.
template<size_t WIDTH, size_t HEIGHT>
class Sh1106Impl :
    public MonochromeGraphicDisplay::DisplayDriverIf
{
public:
    /// Construct a new Sh1106 driver base class.
    /// 
    /// @param pDisplayCommIf Pointer to the display communication interface.
    /// @param pDisplayResetIf Pointer to the display reset interface.
    /// @param mirrorVertically Set to true to mirror vertically.
    /// @param mirrorHorizontally Set to false to mirror horizontally.
    /// @param columnOffset Offset of the first column.
    Sh1106Impl(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
               DisplayComm::DisplayResetIf* const pDisplayResetIf, 
               const bool mirrorVertically, 
               const bool mirrorHorizontally,
               const size_t columnOffset);

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::TurnOnDisplay
    bool TurnOnDisplay() override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::TurnOffDisplay
    bool TurnOffDisplay() override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::InverseColor
    bool InverseColor(bool inverse) override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::SetContrast
    bool SetContrast(uint8_t value) override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::RefreshScreen
    bool RefreshScreen() override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::GetView
    virtual MonochromeView::DynamicView& GetView() override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::GetWidth
    size_t GetWidth() override;

    /// @copydoc MonochromeGraphicDisplay::DisplayDriverIf::GetHeight
    size_t GetHeight() override;

private:
    static constexpr const size_t ROWS_NUM = HEIGHT / 8U;
    static constexpr const size_t DISPLAY_BUFFER_SIZE = WIDTH * ROWS_NUM;

    void InitDeviceDriver();

    const bool m_MirrorVertically;
    const bool m_MirrorHorizontally;
    const size_t m_ColumnOffset;
    DisplayComm::DisplayCommIf* const m_pDisplayCommIf;
    DisplayComm::DisplayResetIf* const m_pDisplayResetIf;
    bool m_IsColorInverted;
    uint8_t m_DisplayBuffer[DISPLAY_BUFFER_SIZE];
    MonochromeView::DynamicView m_DisplayView;
};

}

#endif 
