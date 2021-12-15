/// @file Factory.h
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef SH1106_FACTORY_HPP
#define SH1106_FACTORY_HPP

#include <cstddef>

namespace MonochromeGraphicDisplay
{

class DisplayDriverIf;

}

namespace DisplayComm
{

class DisplayCommIf;
class DisplayResetIf;

}

namespace Sh1106
{

/// Factory of SH1106 dirvers.
class Factory
{
public:
    /// Create a SH1106 driver instance for resolution 128x32 px (width x height).
    /// 
    /// @param pDisplayCommIf Pointer to the display communication interface.
    /// @param pDisplayResetIf Pointer to the display reset interface.
    /// @param mirrorVertically Set to true to mirror vertically.
    /// @param mirrorHorizontally Set to false to mirror horizontally.
    /// @param columnOffset Offset of the first column.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return Pointer to a newly allocated SH1106 driver object. 
    static MonochromeGraphicDisplay::DisplayDriverIf* Create128x32Driver(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                                                                         DisplayComm::DisplayResetIf* const pDisplayResetIf, 
                                                                         const bool mirrorVertically = false, 
                                                                         const bool mirrorHorizontally = false,
                                                                         const size_t columnOffset = 0U);

    /// Create a SH1106 driver instance for resolution 128x64 px (width x height).
    /// 
    /// @param pDisplayCommIf Pointer to the display communication interface.
    /// @param pDisplayResetIf Pointer to the display reset interface.
    /// @param mirrorVertically Set to true to mirror vertically.
    /// @param mirrorHorizontally Set to false to mirror horizontally.
    /// @param columnOffset Offset of the first column.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return Pointer to a newly allocated SH1106 driver object. 
    static MonochromeGraphicDisplay::DisplayDriverIf* Create128x64Driver(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                                                                         DisplayComm::DisplayResetIf* const pDisplayResetIf, 
                                                                         const bool mirrorVertically = false, 
                                                                         const bool mirrorHorizontally = false,
                                                                         const size_t columnOffset = 0U);

    /// Create a SH1106 driver instance for resolution 128x128 px (width x height).
    /// 
    /// @param pDisplayCommIf Pointer to the display communication interface.
    /// @param pDisplayResetIf Pointer to the display reset interface.
    /// @param mirrorVertically Set to true to mirror vertically.
    /// @param mirrorHorizontally Set to false to mirror horizontally.
    /// @param columnOffset Offset of the first column.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return Pointer to a newly allocated SH1106 driver object. 
    static MonochromeGraphicDisplay::DisplayDriverIf* Create128x128Driver(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                                                                          DisplayComm::DisplayResetIf* const pDisplayResetIf, 
                                                                          const bool mirrorVertically = false, 
                                                                          const bool mirrorHorizontally = false,
                                                                          const size_t columnOffset = 0U);

private:
    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;
};

}

#endif
