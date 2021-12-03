
#ifndef __DISCH_FIRMWARE_PHOTOS_H__
#define __DISCH_FIRMWARE_PHOTOS_H__

#include "DischFirmwareDisplayConf.h"

namespace disch
{
namespace firmware
{

class Photo
{
public:
	Photo(const uint8_t * pData) {
		m_photoData = pData;
	}

	const uint8_t * getData() const {
		return m_photoData;
	}

private:
	const uint8_t * m_photoData = nullptr;

};	/* Photo */

#ifdef INCLUDE_SG_LOGO
extern Photo sgLogoPhoto;
#endif

} /* firmware */
} /* disch */


#endif /* __DISCH_FIRMWARE_PHOTOS_H__ */
