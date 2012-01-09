#ifndef NGUI_H_INCLUDED
#define NGUI_H_INCLUDED

// Contient les alphabets
#include "charmap.h"
#include "nCOMMON.h"

/// Dessine une lettre aux position donn�es en changeant la couleur de fond
void drawCharBckgRGB(short x, short y, char ch, char size, char R, char G, char B, char Rb, char Gb, char Bb);
inline void drawCharBckg(short x, short y, char ch, char size, Color colT, Color colB);

/// Dessine une lettre aux positions donn�es
void drawCharRGB(short x, short y, char ch, char size, char R, char G, char B);
inline void drawChar(short x, short y, char ch, char size, Color col);

/// Ecris un texte aux positions donn�es en changeant la couleur de fond
///    - retour est un bool�en qui d�fini si le retour � la ligne est permis
void drawStrBckgRGB(short x, short y, char* str, char size, char endl, char R, char G, char B, char Rb, char Gb, char Bb);
inline void drawStrBckg(short x, short y, char* str, char size, char endl, Color colT, Color colB);

/// Ecris un texte aux positions donn�es
///    - retour est un bool�en qui d�fini si le retour � la ligne est permis
void drawStrRGB(short x, short y, char* str, char size, char endl, char R, char G, char B);
inline void drawStr(short x, short y, char* str, char size, char endl, Color col);

#endif // NGUI_H_INCLUDED
