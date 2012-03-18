#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

typedef uint16_t Color;

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer
#define RGB(r, g, b) (Color) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))

#define getR(c) ((((c) & 0xF800) >> 11) * 8)
#define getG(c) ((((c) & 0x7E0) >> 5) * 4)
#define getB(c) (((c) & 0x1F) * 2)
#define getBW(c) ((((getR(c)) / 16) + ((getG(c)) / 16) + ((getB(c)) / 16)) / 3)

// BLACK and WHITE are already defined by libndls
#undef WHITE
#undef BLACK
#define BLACK RGB(0, 0, 0)
#define WHITE RGB(255, 255, 255)
#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define YELLOW RGB(255, 255, 0)
#define CYAN RGB(0, 255, 255)
#define FUCHSIA RGB(255, 0, 255)
#define BROWN RGB(91, 59, 17)

typedef void* ScreenBuffer;

/// Create a new buffer for rendering
#define GetNewScreenBuffer() malloc(SCREEN_BYTES_SIZE)

/// Load the direct screen buffer -> display is useless
/// \Warning : Don't free() this buffer !!! Just define your NULL to delete !!!
#define GetDirectScreenBuffer() SCREEN_BASE_ADDRESS

/// Display the buffer on the screen
void display(ScreenBuffer buffer);

/// Copy the displayed screen buffer in the given buffer
void copyScreenToBuffer(ScreenBuffer buffer);

/// Draw a pixel in color
void setPixel(int16_t x, int16_t y, Color c, ScreenBuffer buffer);

/// Clear screen with a color
void clearScreen(Color c, ScreenBuffer buffer);

#endif // NCOMMON_H_INCLUDED
