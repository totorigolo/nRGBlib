#ifndef NGEO_H_INCLUDED
#define NGEO_H_INCLUDED

#include "nCOMMON.h"

typedef struct Line {
    short x1;
    short y1;
    short x2;
    short y2;
} Line;

typedef struct Box {
    short x;
    short y;
    short w;
    short h;
} Box;

typedef struct Square {
    short x;
    short y;
    short side;
} Square;

typedef struct Circle {
    short x;
    short y;
    short radius;
} Circle;

typedef struct Disc {
    short x;
    short y;
    short radius;
} Disc;

typedef struct Triangle {
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
} Triangle;

/// Dessine trois bandes RGB qui font chacunes 1 / 3 de l'écran
void RGBstrips();

/// Dessine une ligne quelconque en couleurs
void drawLine_(short x1, short y1, short x2, short y2, Color c);
inline void drawLine(Line *l, Color c);

/// Dessine un rectangle en couleur
void drawBox_(short x, short y, short w, short h, Color c);
inline void drawBox(Box *box, Color c);

/// Dessine un carré en couleur
inline void drawSquare_(short x, short y, short side, Color c);
inline void drawSquare(Square *s, Color c);

/// Dessine un cercle en couleur
void drawCircle_(short x, short y, short radius, Color c);
inline void drawCircle(Circle *c, Color col);

/// Dessine un disque en couleur
void drawDisc_(short x, short y, short radius, Color c);
inline void drawDisc(Disc *d, Color c);

/// Dessine un triangle vide en couleur
void drawTriangle_(short x1, short y1, short x2, short y2, short x3, short y3, Color c);
inline void drawTriangle(Triangle *t, Color c);

#endif // NGEO_H_INCLUDED
