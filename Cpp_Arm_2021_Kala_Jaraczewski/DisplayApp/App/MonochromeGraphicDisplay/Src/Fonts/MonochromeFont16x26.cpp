/// @file MonochromeFont26x16.cpp
///
/// @note Copyright (c) 2021 ArmCpp - Kala, Jaraczewski

#include "MonochromeView/ConstStorageView.hpp"

#include "MonochromeGraphicDisplay/Fonts/MonochromeFont16x26.hpp"

namespace MonochromeGraphicDisplay
{

static const MonochromeView::ConstStorageView<26U, 16U> font26x16Views[] = 
{
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [ ]
	{ 0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [!]
	{ 0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = ["]
	{ 0xCE,0xCE,0xDE,0x9E,0x9C,0x9C,0xFF,0xFF,0x38,0x38,0x78,0x78,0x78,0xFF,0xFF,0xF0,0xF0,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x03,0x03,0x07,0x3F,0x7F,0x07,0x0F,0x0F,0x0F,0x0E,0xFF,0xFF,0x1E,0x1C,0x1C,0x3C,0x3D,0x39,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [#]
	{ 0xFC,0xFE,0xEE,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xF0,0xFC,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFC,0xF0,0xE0,0xE0,0x00,0x00,0x00,0x03,0x0F,0x1F,0x1E,0x1E,0x1E,0x1E,0x1F,0x0F,0x07,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x3D,0x3F,0x0F,0x01,0x01,0x00,0x00,0x00 }, // Ascii = [$]
	{ 0x03,0x07,0x8F,0x8E,0x9E,0xBC,0xB8,0xF8,0xF0,0xE0,0xC0,0xFF,0xFF,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0x7F,0x3F,0x00,0x00,0x00,0x00,0x00,0x3E,0xF7,0xE7,0xE7,0xE3,0xE3,0xE7,0xE7,0xF7,0x3F,0x01,0x03,0x07,0x07,0x0F,0x1E,0x3C,0x38,0x78,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [%]
	{ 0xE0,0xF8,0x78,0x78,0x78,0x78,0x78,0xF0,0xE0,0x80,0xC3,0xC3,0xE7,0xF7,0xF7,0xFF,0x7F,0x3E,0x7F,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x0F,0x1F,0x1F,0x1F,0x0F,0x0F,0x0F,0x1F,0x7F,0xFB,0xF3,0xF1,0xF0,0xF0,0xF0,0xF8,0x7C,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [&]
	{ 0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [']
	{ 0x3F,0x7C,0xF0,0xE0,0xC0,0xC0,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0xC0,0xC0,0xE0,0xF0,0x7C,0x3F,0x0F,0x00,0x00,0x00,0x01,0x01,0x03,0x07,0x07,0x07,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x07,0x07,0x07,0x03,0x01,0x01,0x00,0x00,0x00,0x00 }, // Ascii = [(]
	{ 0x00,0x00,0xC0,0xC0,0xE0,0xF0,0xF0,0xF0,0xF8,0x78,0x78,0x78,0x78,0x78,0x78,0xF8,0xF0,0xF0,0xF0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x7E,0x1F,0x07,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x07,0x1F,0x7E,0x78,0x00 }, // Ascii = [)]
	{ 0xE0,0xC0,0xC0,0xCE,0xFF,0x7F,0x20,0x70,0xF8,0x78,0x3C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x01,0x39,0x3F,0x3F,0x03,0x03,0x07,0x0F,0x1F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [*]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [+]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x03 }, // Ascii = [,]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [-]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [.]
	{ 0x0F,0x0F,0x1E,0x1E,0x3C,0x3C,0x78,0x78,0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x07,0x07,0x0F,0x0F,0x1E,0x1E,0x3C,0x3C,0x78,0x78,0xF0,0x00 }, // Ascii = [/]
	{ 0xF0,0xF8,0x7C,0x3E,0x1E,0x1F,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1F,0x1E,0x3E,0x7C,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x3E,0x3C,0x7C,0x7C,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x7C,0x7C,0x3C,0x3E,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [0]
	{ 0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x3F,0x3F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [1]
	{ 0xE0,0xF8,0x7C,0x3C,0x3E,0x3E,0x3E,0x3C,0x3C,0x7C,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x0F,0x3F,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x0F,0x1E,0x3E,0x3C,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [2]
	{ 0xF0,0xF8,0x7C,0x3E,0x3E,0x3E,0x3C,0x3C,0xF8,0xF0,0xF8,0x7C,0x3E,0x1E,0x1E,0x1E,0x1E,0x3E,0x7C,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [3]
	{ 0x78,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0x78,0x78,0x78,0x78,0x78,0x78,0xFF,0xFF,0x78,0x78,0x78,0x78,0x78,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x0F,0x1E,0x1E,0x3C,0x78,0x78,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [4]
	{ 0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0xE0,0xF8,0xFC,0x7C,0x3E,0x3E,0x1E,0x3E,0x3E,0x3C,0x7C,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1E,0x1E,0x1E,0x1E,0x1E,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [5]
	{ 0xFC,0xFE,0x8E,0x00,0x00,0x00,0x00,0x00,0xF8,0xFC,0x3E,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x0F,0x1F,0x1E,0x3E,0x3C,0x3C,0x3D,0x3F,0x7F,0x7E,0x3C,0x3C,0x3C,0x3C,0x3E,0x1E,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [6]
	{ 0xFF,0xFF,0xFF,0x0F,0x1E,0x1E,0x3C,0x38,0x78,0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x07,0x0F,0x0F,0x0F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [7]
	{ 0xF8,0xFC,0x3E,0x1E,0x1E,0x1E,0x1E,0x3C,0xF8,0xF0,0xF8,0xFC,0x3E,0x1F,0x1F,0x0F,0x0F,0x1F,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x1E,0x3E,0x3E,0x1E,0x1F,0x0F,0x07,0x0F,0x1E,0x3E,0x3C,0x7C,0x7C,0x7C,0x3C,0x3F,0x1F,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [8]
	{ 0xF0,0xF8,0x7C,0x3E,0x1E,0x1F,0x1F,0x1F,0x1F,0x1F,0x3F,0xFF,0xEF,0x1F,0x1E,0x1E,0x3E,0x3C,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1E,0x3C,0x3C,0x7C,0x7C,0x7C,0x7C,0x3C,0x3E,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x38,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [9]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [:]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x03,0x03 }, // Ascii = [;]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3F,0xFC,0xF0,0xC0,0x00,0x00,0x00,0xC0,0xF0,0xFC,0x3F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3F,0xFE,0x3F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [<]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [=]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF8,0x7E,0x1F,0x7E,0xF8,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF8,0x7E,0x1F,0x07,0x01,0x00,0x00,0x00,0x01,0x07,0x1F,0x7E,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [>]
	{ 0xF0,0xFC,0x3E,0x1F,0x1F,0x1E,0x1E,0x3C,0x78,0xF0,0xE0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x38,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07,0x07,0x00,0x00,0x00,0x07,0x07,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [?]
	{ 0xF8,0xFE,0x1E,0x0F,0x7F,0xFF,0xEF,0xC7,0xC7,0x8F,0x8F,0x8F,0x9F,0x9F,0xFF,0xFF,0xF7,0x00,0x1C,0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x1F,0x3E,0x3C,0x78,0x79,0x73,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0x73,0x7B,0x79,0x3C,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [@]
	{ 0x00,0x00,0x00,0xE0,0xE0,0xF0,0xF0,0xF0,0x78,0x78,0x7C,0x3C,0x3C,0x3E,0xFE,0xFF,0x1F,0x0F,0x0F,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x07,0x07,0x0F,0x0F,0x0E,0x1E,0x1E,0x3C,0x3F,0x3F,0x78,0x78,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [A]
	{ 0x00,0x00,0x00,0xF8,0xFC,0x3E,0x1E,0x1E,0x1E,0x3E,0x7C,0xF0,0xF8,0x7E,0x1F,0x1F,0x0F,0x0F,0x1F,0xFE,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3F,0x3F,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [B]
	{ 0x00,0x00,0x00,0xFF,0xFF,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x1F,0x3E,0x3C,0x7C,0x78,0x78,0x78,0x78,0x78,0x7C,0x7C,0x3E,0x3F,0x1F,0x07,0x01,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [C]
	{ 0x00,0x00,0x00,0xF0,0xFC,0x7E,0x1F,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1E,0x7E,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [D]
	{ 0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3F,0x3F,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [E]
	{ 0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1F,0x1F,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [F]
	{ 0x00,0x00,0x00,0xFE,0xFF,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x0F,0x0F,0x0F,0x0F,0x8F,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x1F,0x3E,0x7C,0x7C,0x78,0xF8,0xF8,0xF8,0xF8,0x78,0x7C,0x7C,0x3E,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [G]
	{ 0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0xFF,0xFF,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7F,0x7F,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [H]
	{ 0x00,0x00,0x00,0xFF,0xFF,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [I]
	{ 0x00,0x00,0x00,0xFC,0xFC,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x78,0x78,0xF8,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [J]
	{ 0x00,0x00,0x00,0x1F,0x1E,0x3C,0x78,0xF0,0xE0,0xE0,0xC0,0x80,0xC0,0xE0,0xF0,0xF0,0x78,0x7C,0x3E,0x1F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x3C,0x3D,0x3F,0x3F,0x3F,0x3F,0x3F,0x3D,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [K]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [L]
	{ 0x00,0x00,0x00,0x1F,0x1F,0x1F,0x3F,0x3F,0x3F,0x7F,0x77,0x77,0xF7,0xE7,0xE7,0xE7,0xC7,0x07,0x07,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFC,0xFC,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,0xF7,0xF7,0xF3,0xF3,0xF3,0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [M]
	{ 0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x8F,0x8F,0xCF,0xEF,0xEF,0xFF,0xFF,0xFF,0x7F,0x3F,0x3F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x7C,0x7E,0x7F,0x7F,0x7F,0x7F,0x7F,0x7B,0x79,0x79,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [N]
	{ 0x00,0x00,0x00,0xF0,0xFC,0x3E,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x7C,0x78,0x78,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0x78,0x78,0x7C,0x3E,0x1F,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [O]
	{ 0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0F,0x0F,0x0F,0x0F,0x1F,0x3F,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3F,0x3F,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [P]
	{ 0x00,0x00,0x00,0xF0,0xFC,0x3E,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x3E,0xFC,0xF8,0x7C,0x3F,0x0F,0x03,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x7C,0x78,0x78,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0x78,0x78,0x7C,0x3E,0x1F,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [Q]
	{ 0x00,0x00,0x00,0xF0,0xFC,0x7E,0x3E,0x1E,0x1E,0x3E,0x3C,0xFC,0xF0,0xE0,0xF0,0xF8,0x7C,0x3E,0x1E,0x1F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3F,0x3F,0x3D,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [R]
	{ 0x00,0x00,0x00,0xFC,0xFE,0x0E,0x00,0x00,0x00,0x00,0xC0,0xF8,0xFE,0x7F,0x1F,0x0F,0x0F,0x1F,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x3C,0x3C,0x3C,0x3E,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x20,0x3C,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [S]
	{ 0x00,0x00,0x00,0xFF,0xFF,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [T]
	{ 0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1E,0x1E,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x3C,0x3C,0x3E,0x1F,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [U]
	{ 0x00,0x00,0x00,0x07,0x07,0x07,0x0F,0x0F,0x1E,0x1E,0x1E,0x3C,0x3C,0x78,0x78,0xF8,0xF0,0xF0,0xF0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xF8,0x78,0x7C,0x3C,0x3C,0x3E,0x1E,0x1F,0x1F,0x0F,0x0F,0x07,0x07,0x07,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [V]
	{ 0x00,0x00,0x00,0x03,0x03,0x03,0x07,0xE7,0xE7,0xE7,0xE7,0xF7,0xF7,0xFF,0x7F,0x7F,0x7E,0x7E,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF0,0xF0,0xF0,0xF3,0xF3,0xF3,0x73,0x7B,0x7F,0x7F,0x7F,0x7F,0x7F,0x3F,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [W]
	{ 0x00,0x00,0x00,0x07,0x0F,0x1E,0x3E,0x3C,0xF8,0xF0,0xE0,0xE0,0xE0,0xF0,0xF8,0x7C,0x7C,0x3E,0x1F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7C,0x3E,0x3E,0x1F,0x0F,0x07,0x07,0x03,0x03,0x07,0x0F,0x0F,0x1E,0x3C,0x78,0x78,0xF0,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [X]
	{ 0x00,0x00,0x00,0x07,0x07,0x0F,0x1E,0x1E,0x3C,0x78,0xF8,0xF0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x78,0x7C,0x3C,0x3E,0x1F,0x0F,0x0F,0x07,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [Y]
	{ 0x00,0x00,0x00,0xFF,0xFF,0x0F,0x1F,0x3E,0x7C,0xF8,0xF0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x0F,0x1E,0x3E,0x7C,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [Z]
	{ 0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0xFF,0x00,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00 }, // Ascii = [[]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0xC0,0xE0,0xE0,0xF0,0xF0,0x78,0x78,0x3C,0x3C,0x1E,0x1E,0x0F,0x0F,0x07,0x00,0x78,0x78,0x3C,0x3C,0x1E,0x1E,0x0F,0x0F,0x07,0x07,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [\]
	{ 0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x00 }, // Ascii = []]
	{ 0xC0,0xC0,0xC0,0xE0,0xE0,0xF0,0xF0,0x78,0x78,0x38,0x3C,0x3C,0x1E,0x1E,0x0F,0x0F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x07,0x07,0x07,0x0F,0x0F,0x1E,0x1E,0x3C,0x3C,0x38,0x78,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [^]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00 }, // Ascii = [_]
	{ 0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [`]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFC,0x7C,0x3E,0x3E,0x3E,0xFE,0xFE,0x3E,0x3E,0x3E,0x3E,0x7E,0xFF,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x3F,0x3C,0x00,0x00,0x00,0x07,0x1F,0x3E,0x7C,0x78,0x7C,0x7C,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [a]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFE,0x3E,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1E,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3D,0x3F,0x3F,0x3E,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3F,0x3F,0x3B,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [b]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x1F,0x3E,0x3E,0x3C,0x7C,0x7C,0x7C,0x3C,0x3E,0x3E,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [c]
	{ 0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0xFF,0xFF,0x3F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x3F,0x7F,0xFF,0xDF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x3C,0x7C,0x7C,0x7C,0x78,0x78,0x7C,0x7C,0x3C,0x3E,0x1F,0x0F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [d]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFC,0x3E,0x1E,0x1F,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x00,0x07,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x1F,0x3E,0x3C,0x7C,0x7F,0x7F,0x7C,0x7C,0x3C,0x3E,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [e]
	{ 0xFF,0xE1,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07,0x07,0x07,0x7F,0x7F,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [f]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xEF,0xFF,0x7F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x3F,0x7F,0xFF,0xDF,0x1E,0x1E,0x1E,0x7C,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x3C,0x7C,0x7C,0x78,0x78,0x78,0x7C,0x7C,0x3C,0x3E,0x1F,0x0F,0x00,0x00,0x00,0x38,0x3F }, // Ascii = [g]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0x9E,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3D,0x3F,0x3F,0x3F,0x3E,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [h]
	{ 0xF0,0xF0,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x7F,0x7F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [i]
	{ 0xF8,0xF8,0x00,0x00,0x00,0x00,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF0,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0x7F }, // Ascii = [j]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3E,0x7C,0xF8,0xF0,0xE0,0xC0,0xC0,0xE0,0xF0,0xF8,0x7C,0x3E,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3D,0x3D,0x3F,0x3F,0x3F,0x3D,0x3C,0x3C,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [k]
	{ 0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x7F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [l]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x9E,0xFF,0xFF,0xFF,0xE7,0xE7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF7,0xFF,0xFF,0xFF,0xFB,0xF9,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1,0xF1,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [m]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0x9E,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0x3F,0x3F,0x3F,0x3E,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [n]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFC,0x3E,0x1F,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1F,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x3C,0x7C,0x78,0x78,0x78,0x78,0x78,0x7C,0x3C,0x3E,0x1F,0x07,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [o]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFE,0x3E,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1E,0x3E,0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0x3F,0x3F,0x3E,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3E,0x3F,0x3F,0x3F,0x3C,0x3C,0x3C,0x3C,0x3C }, // Ascii = [p]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0xFE,0x7E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x3E,0x7E,0xFE,0xDE,0x1E,0x1E,0x1E,0x1E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3E,0x3C,0x7C,0x78,0x78,0x78,0x78,0x78,0x7C,0x7C,0x3E,0x1F,0x0F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [q]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xE7,0xC7,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [r]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0x0E,0x00,0x00,0x00,0xE0,0xFC,0xFE,0x3E,0x1E,0x1E,0x3E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x1E,0x3E,0x3E,0x3F,0x1F,0x07,0x00,0x00,0x00,0x00,0x3C,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [s]
	{ 0x00,0x00,0x00,0x80,0x80,0x80,0xFF,0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x07,0x7F,0x7F,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [t]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x3E,0x7E,0xFE,0xFE,0xDE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3E,0x1F,0x0F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [u]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x0F,0x1E,0x1E,0x1E,0x3C,0x3C,0x78,0x78,0xF0,0xF0,0xF0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x78,0x78,0x3C,0x3C,0x3E,0x1E,0x1E,0x0F,0x0F,0x0F,0x07,0x07,0x03,0x03,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [v]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE3,0xE3,0xE7,0xF7,0xF7,0xF7,0x77,0x7F,0x7F,0x7F,0x3E,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF1,0xF3,0xF3,0xF3,0xF3,0x7F,0x7F,0x7F,0x7F,0x7F,0x3E,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [w]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1E,0x3C,0x3C,0xF8,0xF0,0xF0,0xE0,0xF0,0xF8,0xF8,0x7C,0x3E,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x3E,0x3E,0x1F,0x0F,0x07,0x07,0x03,0x07,0x07,0x0F,0x1E,0x3E,0x3C,0x78,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [x]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x0F,0x1E,0x1E,0x3C,0x3C,0x3C,0x78,0xF8,0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x78,0x7C,0x3C,0x3C,0x1E,0x1E,0x1F,0x0F,0x0F,0x07,0x07,0x03,0x03,0x03,0x03,0x03,0x07,0x0F,0x7F }, // Ascii = [y]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x1F,0x3E,0x7C,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,0x1E,0x3C,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [z]
	{ 0xFE,0xE0,0xC0,0xC0,0xC0,0xC0,0xE0,0xE0,0xE0,0xC0,0xC0,0x80,0x80,0xC0,0xC0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xC0,0xE0,0xFE,0x7E,0x00,0x01,0x03,0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x03,0x3F,0x3F,0x03,0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x03,0x03,0x01,0x00,0x00 }, // Ascii = [{]
	{ 0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00 }, // Ascii = [|]
	{ 0xC0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xC0,0xE0,0xFE,0xFE,0xE0,0xC0,0xC0,0xC0,0xC0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0x00,0x00,0x3F,0x03,0x01,0x01,0x01,0x01,0x01,0x03,0x03,0x01,0x01,0x00,0x00,0x01,0x01,0x03,0x03,0x01,0x01,0x01,0x01,0x01,0x03,0x3F,0x3F,0x00 }, // Ascii = [}]
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xC7,0xE7,0xFF,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x73,0xF1,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }, // Ascii = [~]
};

MonochromeFont<26U, 16U> font26x16{ font26x16Views, static_cast<size_t>(' '), sizeof(font26x16Views)/sizeof(font26x16Views[0U]) };

}
