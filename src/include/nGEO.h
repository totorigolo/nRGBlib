#ifndef NGEO_H_INCLUDED
#define NGEO_H_INCLUDED

#include "nCOMMON.h"

typedef struct Line
{
    short x1;
    short y1;
    short x2;
    short y2;
} Line;
Line new_Line(short x1, short y1, short x2, short y2);
void init_Line(Line *l, short x1, short y1, short x2, short y2);

typedef struct Box
{
    short x;
    short y;
    short w;
    short h;
} Box;
Box new_Box(short x, short y, short w, short h);
void init_Box(Box *b, short x, short y, short w, short h);

typedef struct Square Square;
struct Square
{
    short x;
    short y;
    short c;
};
Square new_Square(short x, short y, short c);
void init_Square(Square *d, short x, short y, short c);

typedef struct Circle Circle;
struct Circle
{
    short x;
    short y;
    short radius;
};
Circle new_Circle(short x, short y, short radius);
void init_Circle(Circle *d, short x, short y, short radius);

typedef struct Disc Disc;
struct Disc
{
    short x;
    short y;
    short radius;
};
Disc new_Disc(short x, short y, short radius);
void init_Disc(Disc *d, short x, short y, short radius);

typedef struct Triangle Triangle;
struct Triangle
{
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
};
Triangle new_Triangle(short x1, short y1, short x2, short y2, short x3, short y3);
void init_Triangle(Triangle *t, short x1, short y1, short x2, short y2, short x3, short y3);

/// Dessine trois bandes RGB qui font chacunes 1 / 3 de l'écran
void RGBstrips();

/// Dessine une ligne quelconque en couleurs
void drawLineRGB_(short x1, short y1, short x2, short y2, char R, char G, char B);
inline void drawLine_(short x1, short y1, short x2, short y2, Color col);
inline void drawLineRGB(Line *l, char R, char G, char B);
inline void drawLine(Line *l, Color col);

/// Dessine un carré en couleur
inline void drawSquareRGB_(short x, short y, short c, char R, char G, char B);
inline void drawSquare_(short x, short y, short c, Color col);
inline void drawSquareRGB(Square *s, char R, char G, char B);
inline void drawSquare(Square *s, Color col);

/// Dessine un rectangle en couleur
void drawBoxRGB_(short x, short y, short w, short h, char R, char G, char B);
inline void drawBox_(short x, short y, short w, short h, Color col);
inline void drawBoxRGB(Box *box, char R, char G, char B);
inline void drawBox(Box *box, Color col);

/// Dessine un cercle en couleur
void drawCircleRGB_(short x, short y, short radius, char R, char G, char B);
void drawCircle_(short x, short y, short radius, Color col);
void drawCircleRGB(Circle *c, char R, char G, char B);
void drawCircle(Circle *c, Color col);

/// Dessine un disque en couleur
void drawDiscRGB_(short x, short y, short radius, char R, char G, char B);
void drawDisc_(short x, short y, short radius, Color col);
void drawDiscRGB(Disc *d, char R, char G, char B);
void drawDisc(Disc *d, Color col);

/// Dessine un triangle vide en couleur
void drawTriangleRGB_(short x1, short y1, short x2, short y2, short x3, short y3, char R, char G, char B);
void drawTriangle_(short x1, short y1, short x2, short y2, short x3, short y3, Color col);
void drawTriangleRGB(Triangle *t, char R, char G, char B);
void drawTriangle(Triangle *t, Color col);

#endif // NGEO_H_INCLUDED
