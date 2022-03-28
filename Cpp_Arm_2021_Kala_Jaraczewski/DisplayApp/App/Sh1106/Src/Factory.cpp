/// @file Factory.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include <new>

#include "assert.h"

#include "Sh1106/Factory.hpp"
#include "Sh1106Impl.hpp"

namespace Sh1106
{

MonochromeGraphicDisplay::DisplayDriverIf* Factory::Create128x32Driver(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                                                                       DisplayComm::DisplayResetIf* const pDisplayResetIf,
                                                                       const bool mirrorVertically, 
                                                                       const bool mirrorHorizontally,
                                                                       const size_t columnOffset)
{
    constexpr const size_t WIDTH = 128U;
    constexpr const size_t HEIGHT = 32U;
    assert(pDisplayCommIf != nullptr);
    assert(pDisplayResetIf != nullptr);
    MonochromeGraphicDisplay::DisplayDriverIf* pSh1106Driver = new (std::nothrow) Sh1106Impl<WIDTH, HEIGHT>(
        pDisplayCommIf, pDisplayResetIf, mirrorVertically, mirrorHorizontally, columnOffset);
    assert(pSh1106Driver != nullptr);
    return pSh1106Driver;
}

MonochromeGraphicDisplay::DisplayDriverIf* Factory::Create128x64Driver(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                                                                       DisplayComm::DisplayResetIf* const pDisplayResetIf,
                                                                       const bool mirrorVertically, 
                                                                       const bool mirrorHorizontally,
                                                                       const size_t columnOffset)
{
    constexpr const size_t WIDTH = 128U;
    constexpr const size_t HEIGHT = 64U;
    assert(pDisplayCommIf != nullptr);
    assert(pDisplayResetIf != nullptr);
    MonochromeGraphicDisplay::DisplayDriverIf* pSh1106Driver = new (std::nothrow) Sh1106Impl<WIDTH, HEIGHT>(
        pDisplayCommIf, pDisplayResetIf, mirrorVertically, mirrorHorizontally, columnOffset);
    assert(pSh1106Driver != nullptr);
    return pSh1106Driver;
}

MonochromeGraphicDisplay::DisplayDriverIf* Factory::Create128x128Driver(DisplayComm::DisplayCommIf* const pDisplayCommIf, 
                                                                        DisplayComm::DisplayResetIf* const pDisplayResetIf,
                                                                        const bool mirrorVertically, 
                                                                        const bool mirrorHorizontally,
                                                                        const size_t columnOffset)
{
    constexpr const size_t WIDTH = 128U;
    constexpr const size_t HEIGHT = 128U;
    assert(pDisplayCommIf != nullptr);
    assert(pDisplayResetIf != nullptr);
    MonochromeGraphicDisplay::DisplayDriverIf* pSh1106Driver = new (std::nothrow) Sh1106Impl<WIDTH, HEIGHT>(
        pDisplayCommIf, pDisplayResetIf, mirrorVertically, mirrorHorizontally, columnOffset);
    assert(pSh1106Driver != nullptr);
    return pSh1106Driver;
}

}
