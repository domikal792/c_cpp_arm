/// @file MonochromeGraphic.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_MONOCHROMEGRAPHIC_HPP
#define MONOCHROMEGRAPHICDISPLAY_MONOCHROMEGRAPHIC_HPP

#include <stdint.h>
namespace MonochromeGraphicDisplay
{

/// Monochrome graphic.
class MonochromeGraphic
{
public:
    // TODO: Add constructor and getter for size and columns.

    /// Construct a new Monochrome Graphic object
    /// 
    /// @param pData Pointer to graphic array data
    MonochromeGraphic(const uint8_t *pData);

    /// Get the graphic Data object
    /// 
    /// @return const uint8_t* graphic array data
    const uint8_t * GetData() const;

private:

    /// Graphic array data
    /// 
    const uint8_t * m_graphicData = nullptr;

};

}

#endif
