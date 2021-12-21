/// @file AppImpl.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef APP_IMPL_HPP
#define APP_IMPL_HPP

#include <memory>
#include <cstddef>
#include <cstdint>

#include "AppInitStruct.h"

#include "MonochromeView/DynamicStorageView.hpp"
#include "Pages/LogoPage.hpp"
#include "Pages/AboutPage.hpp"
#include "Pages/StatusPage.hpp"
#include "Pages/EmptyPage.hpp"

namespace DisplayComm
{

class DisplayResetIf;
class DisplayDataCmdIf;
class DisplayCommIf;

}

namespace MonochromeGraphicDisplay
{

class DisplayDriverIf;

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
    static constexpr const size_t SCREEN_WIDTH = 128U;
    static constexpr const size_t SCREEN_HEIGHT = 64U;
    static constexpr const uint32_t SCREEN_REFRESH_MS = 100U;
    static constexpr const uint32_t AUTOSCROLL_MS = 2500U;

    static constexpr const size_t PAGES_NUM = 4U;

    static constexpr const size_t VERT_SCROLLBAR_FRAME_WIDTH = 4U;
    static constexpr const size_t VERT_SCROLLBAR_FRAME_HEIGHT = SCREEN_HEIGHT;
    static constexpr const int32_t VERT_SCROLLBAR_FRAME_X_COORD = SCREEN_WIDTH - VERT_SCROLLBAR_FRAME_WIDTH;
    static constexpr const int32_t VERT_SCROLLBAR_FRAME_Y_COORD = 0;
    static constexpr const size_t VERT_SCROLLBAR_WIDTH = 2U;
    static constexpr const size_t VERT_SCROLLBAR_HEIGHT = (VERT_SCROLLBAR_FRAME_HEIGHT / PAGES_NUM);

    static constexpr const size_t PAGE_WIDTH = SCREEN_WIDTH - VERT_SCROLLBAR_FRAME_WIDTH;
    static constexpr const size_t PAGE_HEIGHT = SCREEN_HEIGHT;
    static constexpr const int32_t PAGE_X_COORD = 0;
    static constexpr const int32_t PAGE_Y_COORD = 0;

    struct PageData
    {
        MonochromeView::DynamicStorageView<PAGE_WIDTH, PAGE_HEIGHT> m_View;
        PageIf* m_pPageIf = nullptr;
    };

    void RefreshScreen();

    void RefreshScrollbar();

    size_t m_ActivePage;
    uint32_t m_LastScreenRefreshMs;
    uint32_t m_LastAutoscrollMs;
    PageData m_Pages[PAGES_NUM];

    MonochromeView::DynamicStorageView<VERT_SCROLLBAR_FRAME_WIDTH, VERT_SCROLLBAR_FRAME_HEIGHT> m_VertScrollbarFrameView;
    MonochromeView::DynamicStorageView<VERT_SCROLLBAR_WIDTH, VERT_SCROLLBAR_HEIGHT> m_VertScrollbarView;

    LogoPage m_LogPage;
    AboutPage m_AboutPage;
    StatusPage m_StatusPage;
    EmptyPage m_EmptyPage;

    std::unique_ptr<DisplayComm::DisplayResetIf> m_pDisplayReset;
    std::unique_ptr<DisplayComm::DisplayDataCmdIf> m_pDisplayDataCmd;
    std::unique_ptr<DisplayComm::DisplayCommIf> m_pDisplayComm;
    std::unique_ptr<MonochromeGraphicDisplay::DisplayDriverIf> m_pDisplayDriver;
};

#endif
