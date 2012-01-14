#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

// Dis/enables the possibility of using the screen of 4 bpp Nspire 16bpp, but accelerates drawing
#define __FAST_SETPIXEL__ 0

typedef uint16_t Color;
#define RGB(r, g, b) (Color) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))

#define getR(c) ((((c) & 0xF800) >> 11) * 8)
#define getG(c) ((((c) & 0x7E0) >> 5) * 4)
#define getB(c) (((c) & 0x1F) * 2)
#define getBW(c) ((((getR(c)) / 16) + ((getG(c)) / 16) + ((getB(c)) / 16)) / 3)

/// Draw a pixel in color
void setPixel(int16_t x, int16_t y, Color c);

/// Clear screen with a color
void clearScreen(Color c);

#endif // NCOMMON_H_INCLUDED
