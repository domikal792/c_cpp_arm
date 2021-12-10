/// @file AppImpl.hpp

#ifndef APP_IMPL_HPP
#define APP_IMPL_HPP

#include "AppInitStruct.h"
#include "DischFirmwareSH1106.h"

#include <memory>

namespace DisplayComm
{

class DisplayResetIf;
class DisplayDataCmdIf;
class DisplayCommIf;

}

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
    std::unique_ptr<DisplayComm::DisplayResetIf> m_pDisplayReset;
    std::unique_ptr<DisplayComm::DisplayDataCmdIf> m_pDisplayDataCmd;
    std::unique_ptr<DisplayComm::DisplayCommIf> m_pDisplayComm;
};

#endif
