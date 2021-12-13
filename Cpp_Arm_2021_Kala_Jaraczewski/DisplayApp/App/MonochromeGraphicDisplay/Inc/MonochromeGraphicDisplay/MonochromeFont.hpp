/// @file MonochromeFont.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP
#define MONOCHROMEGRAPHICDISPLAY_MONOCHROMEFONT_HPP

#include <stdint.h>
namespace MonochromeGraphicDisplay
{

/// Monochrome font.
class MonochromeFont
{
public:
    // TODO: Add constructor and getters for characters

    /// Construct a new Monochrome Font object
    /// 
    /// @param width Font width in pixels
    /// @param height Font height in pixels
    /// @param pData Pointer to font array data
    MonochromeFont(uint8_t width, uint8_t height, const uint16_t * pData);

    /// Get the Width object
    /// 
    /// @return uint8_t 
	uint8_t GetWidth() const;
    
    /// Get the Height object
    /// 
    /// @return uint8_t 
	uint8_t GetHeight() const;
    
    /// Get the Data object
    /// 
    /// @return const uint16_t* 
	const uint16_t * GetData() const;

private:

    const uint8_t m_width;    /*!< Font width in pixels */
	const uint8_t m_height;   /*!< Font height in pixels */
	const uint16_t * m_pData; /*!< Pointer to font array data */

};

}

#endif
