/// @file AppCInterface.h

#ifndef APP_C_INTERFACE_H
#define APP_C_INTERFACE_H

#include "AppInitStruct.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// Initialize application.
///
/// @param pAppInitStruct Pointer to application initialization structure.
void App_Init(const AppInitStruct* const pAppInitStruct);

/// Function called in main loop.
void App_Tick();

#ifdef DEBUG
/// Function called in main loop for debugging purposes.
void App_DebugTick();
#endif

#ifdef __cplusplus
}
#endif

#endif

