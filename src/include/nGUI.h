#ifndef NGUI_H_INCLUDED
#define NGUI_H_INCLUDED

// Contient les alphabets
#include "charmap.h"
#include "nCOMMON.h"

/// Dessine une lettre aux position données en changeant la couleur de fond
void drawCharBckg(int16_t x, int16_t y, char ch, int8_t size, Color cT, Color cB);

/// Dessine une lettre aux positions données
void drawChar(int16_t x, int16_t y, char ch, int8_t size, Color c);

/// Ecris un texte aux positions données en changeant la couleur de fond
///    - retour est un booléen qui défini si le retour à la ligne est permis
void drawStrBckg(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color cT, Color cB);

/// Ecris un texte aux positions données
///    - retour est un booléen qui défini si le retour à la ligne est permis
void drawStr(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color c);

#endif // NGUI_H_INCLUDED
