#ifndef NGEO_H_INCLUDED
#define NGEO_H_INCLUDED

#include "nCOMMON.h"

typedef struct Line {
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
} Line;

typedef struct Box {
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
} Box;
typedef Box Rect;

typedef struct Square {
    int16_t x;
    int16_t y;
    int16_t side;
} Square;

typedef struct Circle {
    int16_t x;
    int16_t y;
    int16_t radius;
} Circle;

typedef struct Disc {
    int16_t x;
    int16_t y;
    int16_t radius;
} Disc;

typedef struct Triangle {
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
    int16_t x3;
    int16_t y3;
} Triangle;

/// Draw a line in color
// - Note that for a vertical or horizontal line, use of drawBox is faster
void drawLine_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, Color c, ScreenBuffer buffer);
inline void drawLine(Line *l, Color c, ScreenBuffer buffer);

/// Draw a box / rectangle in color
inline void drawBox_(int16_t x, int16_t y, int16_t w, int16_t h, Color c, ScreenBuffer buffer);
inline void drawBox(Box *box, Color c, ScreenBuffer buffer);

/// Draw a square in color
inline void drawSquare_(int16_t x, int16_t y, int16_t side, Color c, ScreenBuffer buffer);
inline void drawSquare(Square *s, Color c, ScreenBuffer buffer);

/// Draw a circle in color
void drawCircle_(int16_t x, int16_t y, int16_t radius, Color c, ScreenBuffer buffer);
inline void drawCircle(Circle *c, Color col, ScreenBuffer buffer);

/// Draw a disc in color
void drawDisc_(int16_t x, int16_t y, int16_t radius, Color c, ScreenBuffer buffer);
inline void drawDisc(Disc *d, Color c, ScreenBuffer buffer);

/// Draw an empty triangle in color
void drawTriangle_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3, Color c, ScreenBuffer buffer);
inline void drawTriangle(Triangle *t, Color c, ScreenBuffer buffer);

#endif // NGEO_H_INCLUDED
