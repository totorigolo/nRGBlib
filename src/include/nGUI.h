#ifndef NGUI_H_INCLUDED
#define NGUI_H_INCLUDED

// Contient les alphabets
#include "charmap.h"
#include "nCOMMON.h"

/// Dessine une lettre aux position donn�es en changeant la couleur de fond
void drawCharBckg(int16_t x, int16_t y, char ch, int8_t size, Color cT, Color cB);

/// Dessine une lettre aux positions donn�es
void drawChar(int16_t x, int16_t y, char ch, int8_t size, Color c);

/// Ecris un texte aux positions donn�es en changeant la couleur de fond
///    - retour est un bool�en qui d�fini si le retour � la ligne est permis
void drawStrBckg(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color cT, Color cB);

/// Ecris un texte aux positions donn�es
///    - retour est un bool�en qui d�fini si le retour � la ligne est permis
void drawStr(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color c);

#endif // NGUI_H_INCLUDED
