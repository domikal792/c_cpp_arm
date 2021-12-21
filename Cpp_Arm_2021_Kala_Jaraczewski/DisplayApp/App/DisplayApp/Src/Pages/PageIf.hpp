/// @file PageIf.hpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef DISPLAYAPP_PAGEIF_HPP
#define DISPLAYAPP_PAGEIF_HPP

/// Page interface.
class PageIf
{
public:
    /// Method called on create.
    virtual void OnCreate() = 0;

    /// Method called to refresh page view.
    virtual void Refresh() = 0;
};

#endif
