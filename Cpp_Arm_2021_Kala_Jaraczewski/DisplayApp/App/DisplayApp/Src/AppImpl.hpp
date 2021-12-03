/// @file AppImpl.hpp

#ifndef APP_IMPL_HPP
#define APP_IMPL_HPP

#include "AppInitStruct.h"
#include "DischFirmwareSH1106.h"

/// Application implementation.
class AppImpl
{
public:
    /// Default constructor.
    ///
    /// @param pAppInitStruct Pointer to application initialization structure.
    AppImpl(const AppInitStruct* const pAppInitStruct);

    /// Default destructor.
    ~AppImpl();

    /// Application tick.
    void Tick();

#ifdef DEBUG
    /// Application debug tick.
    void DebugTick();
#endif

private:

};

#endif
