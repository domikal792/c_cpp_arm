/// @file Factory.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "assert.h"

#include "Sh1106/Factory.hpp"
#include "Sh1106Impl.hpp"

namespace Sh1106
{

GraphicalScreen::GraphicalScreenDriverIf* Factory::CreateDriver(DisplayComm::DisplayCommIf *pDisplayCommIf, 
                                                                DisplayComm::DisplayResetIf *pDisplayResetIf)
{
    // TODO: Implement factory method.
    GraphicalScreen::GraphicalScreenDriverIf* pSh1106Driver = nullptr;
    assert(pSh1106Driver != nullptr);
    return pSh1106Driver;
}

}
