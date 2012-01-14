#ifndef NGUI_H_INCLUDED
#define NGUI_H_INCLUDED

// Contient les alphabets
#include "charmap.h"
#include "nCOMMON.h"

/// Draw a letter to the given position and change the background color
void drawCharBckg(int16_t x, int16_t y, char ch, int8_t size, Color cT, Color cB);

/// Draw a letter to the given position
void drawChar(int16_t x, int16_t y, char ch, int8_t size, Color c);

/// Write a text to the given position and change background color
//    - endl is a boolean which define if the line break is allowed
void drawStrBckg(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color cT, Color cB);

/// Write a text to the given position and change background color
//    - endl is a boolean which define if the line break is allowed
void drawStr(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color c);

#endif // NGUI_H_INCLUDED
