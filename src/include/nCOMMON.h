#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

#define RGB(

typedef unsigned short Color_16;

typedef struct Color Color;
struct Color
{
    char R;
    char G;
    char B;
    char BW;
};
Color new_Color(char R, char G, char B, char BW);
void init_Color(Color *c, char R, char G, char B, char BW);

// Default colors
Color C_White  = new_Color(255, 255, 255, 16);
Color C_Black  = new_Color(  0,   0,   0,  0);
Color C_Red    = new_Color(255,   0,   0,  6);
Color C_Green  = new_Color(  0, 255,   0,  6);
Color C_Blue   = new_Color(  0,   0, 255,  6);
Color C_Yellow = new_Color(255, 255,   0,  2);
Color C_Cyan   = new_Color(  0, 255, 255,  4);
Color C_Fushia = new_Color(255,   0, 255,  5);
Color C_Orange = new_Color(255, 165,   0,  8);
Color C_Brown  = new_Color(139,  69,  19, 15);
Color C_Purple = new_Color(128,   0, 128, 13);
Color C_Pink   = new_Color(255, 192, 203,  1);

/// Récupère la valeur du pixel
short getPixelRGB(short x, short y);
inline Color getPixel(short x, short y);

/// Dessine un pixel en couleur
void setPixelRGB(short x, short y, char R, char G, char B);
inline void setPixelColor(short x, short y, Color color);

/// Dessine l'écran entier avec la couleur
void clearScreenRGB(char R, char G, char B);
inline void clearScreenColor(Color color);


#endif // NCOMMON_H_INCLUDED
