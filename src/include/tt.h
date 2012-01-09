/*#define RGB(r, g, b, bn) ((bn << 15) | (r << 11) | (g << 5) | b)
#define LINE(x1, y1, x2, y2) ((x1 << 25) | (y1 << 17) | (x2 << 8) | (y2))
#define SQUARE(x, y, c) ((x << 16) | (y << 8) | (c))

typedef unsigned int Color; // 20 bits -> 3 octets -> unsigned int (4 octets)
typedef unsigned long long Line; // 34 bits -> 5 octets -> unsigned long long (8 octets)
typedef unsigned int Square; // 25 bits -> 4 octets -> unsigned int (4 octets)

/// Dessine un pixel en couleur
void setPixel(short x, short y, Color);

/// Dessine une ligne quelconque en couleurs
inline void drawLine(Line l, Color col);

/// Dessine un carré en couleur
inline void drawSquare(Square s, Color col);

// Un p'tit exemple
SetPixel(20, 30, RGB(255, 128, 0, 5));
drawSquare(SQUARE(50, 60, 30), RGB(0, 255, 255, 6));
Color colApple = RGB(255, 0, 0, 5);
drawSquare(SQUARE(50, 60, 30), colApple);

// Style Lua (on rajoute le ", c")
Color c = RGB(255, 0, 0, 5);
drawSquare(SQUARE(0, 0, 5), c);
drawSquare(SQUARE(30, 0, 20), c);
drawSquare(SQUARE(20, 30, 40), c);
c = RGB(0, 255, 0);
drawLine(LINE(5, 6, 25, 26), c);
*/
