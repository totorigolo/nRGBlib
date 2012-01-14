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

/// Draw three red, green and blue strips
void RGBstrips();

/// Draw a line in color
//    - Note that for a vertical or horizontal line, utilisation of drawBox is faster
void drawLine_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, Color c);
inline void drawLine(Line *l, Color c);

/// Draw a box / rectangle in color
void drawBox_(int16_t x, int16_t y, int16_t w, int16_t h, Color c);
inline void drawBox(Box *box, Color c);

/// Draw a square in color
inline void drawSquare_(int16_t x, int16_t y, int16_t side, Color c);
inline void drawSquare(Square *s, Color c);

/// Draw a circle in color
void drawCircle_(int16_t x, int16_t y, int16_t radius, Color c);
inline void drawCircle(Circle *c, Color col);

/// Draw a disc in color
void drawDisc_(int16_t x, int16_t y, int16_t radius, Color c);
inline void drawDisc(Disc *d, Color c);

/// Draw an empty triangle in color
void drawTriangle_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3, Color c);
inline void drawTriangle(Triangle *t, Color c);

#endif // NGEO_H_INCLUDED
