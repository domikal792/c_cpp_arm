/// @file Sh1106If.h
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#ifndef SH1106_SH1106IF_HPP
#define SH1106_SH1106IF_HPP

#include <cstdint>
#include <cstddef>

namespace DisplayComm
{
    class DisplayCommIf;

    class DisplayResetIf;
}


namespace Sh1106
{

class Sh1106
{
public:
    Sh1106(DisplayComm::DisplayCommIf *pDisplayCommIf, DisplayComm::DisplayResetIf *pDisplayResetIf)
    {
        //init
    }




};

}



#endif
