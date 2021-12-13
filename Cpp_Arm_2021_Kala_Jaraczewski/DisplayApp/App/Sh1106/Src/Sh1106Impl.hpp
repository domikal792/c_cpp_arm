/// @file Sh1106Impl.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef SH1106_SH1106_IMPL_HPP
#define SH1106_SH1106_IMPL_HPP

#include "GraphicalScreen/GraphicalScreenDriverIf.hpp"

namespace DisplayComm
{

class DisplayCommIf;
class DisplayResetIf;

}

namespace Sh1106
{

/// Implementation of SH1106 driver.
class Sh1106Impl // :
    // public GraphicalScreen::GraphicalScreenDriverIf // TODO: Inherit from GraphicalScreenDriverIf
{
public:
    /// Construct a new Sh1106 driver.
    /// 
    /// @param pDisplayCommIf Pointer to the display communication interface.
    /// @param pDisplayResetIf Pointer to the display reset interface.
    Sh1106Impl(DisplayComm::DisplayCommIf *pDisplayCommIf, DisplayComm::DisplayResetIf *pDisplayResetIf);

    // TODO: Add missing methods form GraphicalScreenDriverIf
};

}

#endif 
