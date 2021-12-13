/// @file Factory.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_FACTORY_HPP
#define MONOCHROMEGRAPHICDISPLAY_FACTORY_HPP

namespace MonochromeGraphicDisplay
{

class MonochromeGraphicDisplayIf;
class DisplayDriverIf;

/// Factory of monochrome graphic display instances.
class Factory
{
public:
    /// Create an instance of monochrome graphic display.
    /// 
    /// @param pDisplayDriverIf Pointer to the display driver interface.
    ///
    /// @note User takes responsibility for managing lifetime of returned object!
    ///
    /// @return Pointer to a newly allocated monochrome graphic display object. 
    static MonochromeGraphicDisplayIf* CreateInstance(DisplayDriver* const pDisplayDriverIf);

private:
    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;
};

}

#endif
