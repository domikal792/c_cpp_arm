/// @file DynamicStorageView.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef MONOCHROMEVIEW_DYNAMICSTORAGEVIEW_HPP
#define MONOCHROMEVIEW_DYNAMICSTORAGEVIEW_HPP

#include <cstdint>
#include <cstddef>

#include "MonochromeView/DynamicView.hpp"

namespace MonochromeView
{

/// Dynamic view with internal storage.
/// 
/// @tparam WIDTH Width of a view.
/// @tparam HEIGHT Height of a view.
template<size_t WIDTH, size_t HEIGHT>
class DynamicStorageView :
    public DynamicView
{
public:
    /// Construct a new dynamic storage view object.
    /// 
    /// @tparam ViewBytesTypes Types of view bytes.
    ///
    /// @param viewBytes List of bytes to store for a view. The first element is a left-top cell (1 column and 8 rows pixels). 
    ///                  The first column is repeated for each next 'width' pixels.
    template<typename... ViewBytesTypes>
    DynamicStorageView(ViewBytesTypes... viewBytes) :
        DynamicView(m_Buffer, WIDTH, HEIGHT),
        m_Buffer{static_cast<uint8_t>(viewBytes)...}
    {
    }

private:
    DynamicStorageView(const DynamicStorageView&) = delete;
    void operator=(const DynamicStorageView&) = delete;

    uint8_t m_Buffer[WIDTH * ((HEIGHT + ViewIf::PIXELS_PER_CELL - 1) / ViewIf::PIXELS_PER_CELL)];
};

}

#endif
