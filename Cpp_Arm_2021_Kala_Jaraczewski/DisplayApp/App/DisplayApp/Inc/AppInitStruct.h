/// @file AppInitStruct.h

#ifndef APP_INIT_STRUCT_H
#define APP_INIT_STRUCT_H

#include <stdint.h>

#include "spi.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// Structure for display SPI interface.
typedef struct
{
    SPI_TypeDef * m_pSpi;
    GPIO_TypeDef * m_pCsPort;
    uint32_t m_CsPin;
    GPIO_TypeDef * m_pDcPort;
    uint32_t m_DcPin;
    GPIO_TypeDef * m_pResPort;
    uint32_t m_ResPin;
} DisplaySpiInterface;

/// Structure for application initialization.
typedef struct
{
    DisplaySpiInterface* m_pDisplaySpiInterface;
} AppInitStruct;

#ifdef __cplusplus
}
#endif

#endif
