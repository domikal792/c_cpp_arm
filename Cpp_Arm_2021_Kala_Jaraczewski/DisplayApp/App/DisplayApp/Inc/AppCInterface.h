/// @file AppCInterface.h

#ifndef APP_C_INTERFACE_H
#define APP_C_INTERFACE_H

#include "AppInitStruct.h"

/// Application context wrapper.
typedef struct
{
    void* const m_pAppContext;
} AppContext;

#ifdef __cplusplus
extern "C"
{
#endif

/// Create static application instance.
///
/// @param pAppInitStruct Pointer to application initialization structure.
///
/// @return Pointer to an application context.
AppContext* App_Create(const AppInitStruct* const pAppInitStruct);

/// Function called in main loop.
///
/// @param pAppContext Pointer to an application context.
void App_Tick(AppContext* const pAppContext);

#ifdef DEBUG
/// Function called in main loop for debugging purposes.
///
/// @param pAppContext Pointer to an application context.
void App_DebugTick(AppContext* const pAppContext);
#endif

#ifdef __cplusplus
}
#endif

#endif

