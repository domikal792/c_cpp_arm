/// @file Factory.h
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef SH1106_FACTORY_HPP
#define SH1106_FACTORY_HPP

namespace GraphicalScreen
{

class GraphicalScreenDriverIf;

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
    /// Create a SH1106 driver instance.
    /// 
    /// @param pDisplayCommIf Pointer to the display communication interface.
    /// @param pDisplayResetIf Pointer to the display reset interface.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return GraphicalScreen::GraphicalScreenDriverIf* Pointer to a newly allocated SH1106 driver object. 
    static GraphicalScreen::GraphicalScreenDriverIf* CreateDriver(DisplayComm::DisplayCommIf *pDisplayCommIf, 
                                                                  DisplayComm::DisplayResetIf *pDisplayResetIf);

private:
    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;
};

}

#endif
