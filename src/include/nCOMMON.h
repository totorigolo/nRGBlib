#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

typedef uint16_t Color;

#define RGB(r, g, b) (Color) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))

#define getR(c) ((((c) & 0xF800) >> 11) * 8)
#define getG(c) ((((c) & 0x7E0) >> 5) * 4)
#define getB(c) (((c) & 0x1F) * 2)
#define getBW(c) ((((getR(c)) / 16) + ((getG(c)) / 16) + ((getB(c)) / 16)) / 3)

// BLACK and WHITE are defined yet by libndls
#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)

typedef Color ScreenBuffer;

/// Charge un nouveau buffer d'écran
#define NewScreenBuffer() malloc(sizeof(Color) * 76800)
/**
   \Example:
   ScreenBuffer *buffer = NewScreenBuffer();
   //...
   free(buffer);
**/

/// Display the buffer on the screen
void display(ScreenBuffer buffer[76800]);

/// Copy the displayed screen buffer in the given buffer
void copyScreenToBuffer(ScreenBuffer buffer[76800]);

/// Draw a pixel in color
void setPixel(int16_t x, int16_t y, Color c, ScreenBuffer buffer[76800]);

/// Clear screen with a color
void clearScreen(Color c, ScreenBuffer buffer[76800]);

#endif // NCOMMON_H_INCLUDED
