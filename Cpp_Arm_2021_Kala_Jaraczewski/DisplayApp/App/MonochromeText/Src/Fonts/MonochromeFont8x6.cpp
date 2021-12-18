/// @file MonochromeFont8x6.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski


#include "MonochromeText/Fonts/MonochromeFont8x6.hpp"

namespace MonochromeText
{

static const uint8_t font8x6Bytes [] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // sp
	0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00, // !
	0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00, // "
	0x50,0x50,0xf8,0x50,0xf8,0x50,0x50,0x00, // #
	0x20,0x78,0xa0,0x70,0x28,0xf0,0x20,0x00, // $
	0xc0,0xc8,0x10,0x20,0x40,0x98,0x18,0x00, // %
	0x40,0xa0,0xa0,0x40,0xa8,0x90,0x68,0x00, // &
	0x30,0x30,0x20,0x40,0x00,0x00,0x00,0x00, // '
	0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00, // (
	0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00, // )
	0x20,0xa8,0x70,0xf8,0x70,0xa8,0x20,0x00, // *
	0x00,0x20,0x20,0xf8,0x20,0x20,0x00,0x00, // +
	0x00,0x00,0x00,0x00,0x30,0x30,0x20,0x00, // ,
	0x00,0x00,0x00,0xf8,0x00,0x00,0x00,0x00, // -
	0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00, // .
	0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00, // /
	0x70,0x88,0x98,0xa8,0xc8,0x88,0x70,0x00, // 0
	0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00, // 1
	0x70,0x88,0x08,0x70,0x80,0x80,0xf8,0x00, // 2
	0xf8,0x08,0x10,0x30,0x08,0x88,0x70,0x00, // 3
	0x10,0x30,0x50,0x90,0xf8,0x10,0x10,0x00, // 4
	0xf8,0x80,0xf0,0x08,0x08,0x88,0x70,0x00, // 5
	0x38,0x40,0x80,0xf0,0x88,0x88,0x70,0x00, // 6
	0xf8,0x08,0x08,0x10,0x20,0x40,0x80,0x00, // 7
	0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00, // 8
	0x70,0x88,0x88,0x78,0x08,0x10,0xe0,0x00, // 9
	0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00, // :
	0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00, // ;
	0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00, // <
	0x00,0x00,0xf8,0x00,0xf8,0x00,0x00,0x00, // =
	0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00, // >
	0x70,0x88,0x08,0x30,0x20,0x00,0x20,0x00, // ?
	0x70,0x88,0xa8,0xb8,0xb0,0x80,0x78,0x00, // @
	0x20,0x50,0x88,0x88,0xf8,0x88,0x88,0x00, // A
	0xf0,0x88,0x88,0xf0,0x88,0x88,0xf0,0x00, // B
	0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00, // C
	0xf0,0x88,0x88,0x88,0x88,0x88,0xf0,0x00, // D
	0xf8,0x80,0x80,0xf0,0x80,0x80,0xf8,0x00, // E
	0xf8,0x80,0x80,0xf0,0x80,0x80,0x80,0x00, // F
	0x78,0x88,0x80,0x80,0x98,0x88,0x78,0x00, // G
	0x88,0x88,0x88,0xf8,0x88,0x88,0x88,0x00, // H
	0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00, // I
	0x38,0x10,0x10,0x10,0x10,0x90,0x60,0x00, // J
	0x88,0x90,0xa0,0xc0,0xa0,0x90,0x88,0x00, // K
	0x80,0x80,0x80,0x80,0x80,0x80,0xf8,0x00, // L
	0x88,0xd8,0xa8,0xa8,0xa8,0x88,0x88,0x00, // M
	0x88,0x88,0xc8,0xa8,0x98,0x88,0x88,0x00, // N
	0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00, // O
	0xf0,0x88,0x88,0xf0,0x80,0x80,0x80,0x00, // P
	0x70,0x88,0x88,0x88,0xa8,0x90,0x68,0x00, // Q
	0xf0,0x88,0x88,0xf0,0xa0,0x90,0x88,0x00, // R
	0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00, // S
	0xf8,0xa8,0x20,0x20,0x20,0x20,0x20,0x00, // T
	0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00, // U
	0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00, // V
	0x88,0x88,0x88,0xa8,0xa8,0xa8,0x50,0x00, // W
	0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00, // X
	0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00, // Y
	0xf8,0x08,0x10,0x70,0x40,0x80,0xf8,0x00, // Z
	0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00, // [
	0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00, /* \ */
	0x78,0x08,0x08,0x08,0x08,0x08,0x78,0x00, // ]
	0x20,0x50,0x88,0x00,0x00,0x00,0x00,0x00, // ^
	0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00, // _
	0x60,0x60,0x20,0x10,0x00,0x00,0x00,0x00, // `
	0x00,0x00,0x60,0x10,0x70,0x90,0x78,0x00, // a
	0x80,0x80,0xb0,0xc8,0x88,0xc8,0xb0,0x00, // b
	0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00, // c
	0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00, // d
	0x00,0x00,0x70,0x88,0xf8,0x80,0x70,0x00, // e
	0x10,0x28,0x20,0x70,0x20,0x20,0x20,0x00, // f
	0x00,0x00,0x70,0x98,0x98,0x68,0x08,0x00, // g
	0x80,0x80,0xb0,0xc8,0x88,0x88,0x88,0x00, // h
	0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00, // i
	0x10,0x00,0x10,0x10,0x10,0x90,0x60,0x00, // j
	0x80,0x80,0x90,0xa0,0xc0,0xa0,0x90,0x00, // k
	0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00, // l
	0x00,0x00,0xd0,0xa8,0xa8,0xa8,0xa8,0x00, // m
	0x00,0x00,0xb0,0xc8,0x88,0x88,0x88,0x00, // n
	0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00, // o
	0x00,0x00,0xb0,0xc8,0xc8,0xb0,0x80,0x00, // p
	0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x00, // q
	0x00,0x00,0xb0,0xc8,0x80,0x80,0x80,0x00, // r
	0x00,0x00,0x78,0x80,0x70,0x08,0xf0,0x00, // s
	0x20,0x20,0xf8,0x20,0x20,0x28,0x10,0x00, // t
	0x00,0x00,0x88,0x88,0x88,0x98,0x68,0x00, // u
	0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00, // v
	0x00,0x00,0x88,0x88,0xa8,0xa8,0x50,0x00, // w
	0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00, // x
	0x00,0x00,0x88,0x88,0x78,0x08,0x88,0x00, // y
	0x00,0x00,0xf8,0x10,0x20,0x40,0xf8,0x00, // z
	0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00, // {
	0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00, // |
	0x40,0x20,0x20,0x10,0x20,0x20,0x40,0x00, // }
	0x40,0xa8,0x10,0x00,0x00,0x00,0x00,0x00, // ~
};

// TODO: Test if displays correctly.
const MonochromeFont font8x6{ font8x6Bytes, 8U, 8U, static_cast<size_t>(' '), (sizeof(font8x6Bytes) / 8U) };

}
