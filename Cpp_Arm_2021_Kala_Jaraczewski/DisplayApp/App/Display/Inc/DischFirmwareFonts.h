
#ifndef __DISCH_FIRMWARE_FONTS_H__
#define __DISCH_FIRMWARE_FONTS_H__

#include <stdint.h>
#include <DischFirmwareDisplayConf.h>

namespace disch
{
namespace firmware
{

class Font
{
public:
	Font(uint8_t width, uint8_t height, const uint16_t * pData) :
		m_width(width),
		m_height(height),
		m_pData(pData)
	{}

	uint8_t getWidth() 			const { return m_width; }
	uint8_t getHeight() 		const { return m_height; }
	const uint16_t * getData() 	const { return m_pData; }

private:
	const uint8_t m_width;    /*!< Font width in pixels */
	const uint8_t m_height;   /*!< Font height in pixels */
	const uint16_t * m_pData; /*!< Pointer to data font data array */

}; /* Fonts */

#ifdef INCLUDE_FONT_6x8
extern Font font6x8;
#endif
#ifdef INCLUDE_FONT_7x10
extern Font font7x10;
#endif
#ifdef INCLUDE_FONT_11x18
extern Font font11x18;
#endif
#ifdef INCLUDE_FONT_16x26
extern Font font16x26;
#endif

} /* firmware */
} /* disch */


#endif /* __DISCH_FIRMWARE_FONTS_H__ */
