/// @file AppCInterface.cpp

#include "AppCInterface.h"
#include "AppImpl.hpp"

AppImpl& GetInstance(const AppInitStruct* const pAppInitStruct = nullptr)
{
    static AppImpl appImpl(pAppInitStruct);
    return appImpl;
}

void App_Init(const AppInitStruct* const pAppInitStruct)
{
    (void)GetInstance(pAppInitStruct);
}

void App_Tick()
{
    GetInstance().Tick();
}

#ifdef DEBUG
void App_DebugTick()
{
    GetInstance().DebugTick();
}
#endif
