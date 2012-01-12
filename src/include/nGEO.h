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

/// Dessine trois bandes RGB qui font chacunes 1 / 3 de l'écran
void RGBstrips();

/// Dessine une ligne quelconque en couleurs
void drawLine_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, Color c);
inline void drawLine(Line *l, Color c);

/// Dessine un rectangle en couleur
void drawBox_(int16_t x, int16_t y, int16_t w, int16_t h, Color c);
inline void drawBox(Box *box, Color c);

/// Dessine un carré en couleur
inline void drawSquare_(int16_t x, int16_t y, int16_t side, Color c);
inline void drawSquare(Square *s, Color c);

/// Dessine un cercle en couleur
void drawCircle_(int16_t x, int16_t y, int16_t radius, Color c);
inline void drawCircle(Circle *c, Color col);

/// Dessine un disque en couleur
void drawDisc_(int16_t x, int16_t y, int16_t radius, Color c);
inline void drawDisc(Disc *d, Color c);

/// Dessine un triangle vide en couleur
void drawTriangle_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3, Color c);
inline void drawTriangle(Triangle *t, Color c);

#endif // NGEO_H_INCLUDED
