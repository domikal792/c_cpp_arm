/// @file AppCInterface.cpp

#include "AppCInterface.h"
#include "assert.h"

#include "AppImpl.hpp"

AppContext* App_Create(const AppInitStruct* const pAppInitStruct)
{
    static AppImpl appImpl(pAppInitStruct);
    static AppContext appContext =
    {
        .m_pAppContext = &appImpl
    };

    return &appContext;
}
void App_Tick(AppContext* const pAppContext)
{
    assert(pAppContext != nullptr);
    assert(pAppContext->m_pAppContext != nullptr);
    static_cast<AppImpl*>(pAppContext->m_pAppContext)->Tick();
}

#ifdef DEBUG
void App_DebugTick(AppContext* const pAppContext)
{
    assert(pAppContext != nullptr);
    assert(pAppContext->m_pAppContext != nullptr);
    static_cast<AppImpl*>(pAppContext->m_pAppContext)->DebugTick();
}
#endif
