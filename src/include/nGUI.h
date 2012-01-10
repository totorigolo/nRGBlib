#ifndef NGUI_H_INCLUDED
#define NGUI_H_INCLUDED

// Contient les alphabets
#include "charmap.h"
#include "nCOMMON.h"

/// Dessine une lettre aux position données en changeant la couleur de fond
void drawCharBckg(short x, short y, char ch, char size, Color *cT, Color *cB);

/// Dessine une lettre aux positions données
void drawChar(short x, short y, char ch, char size, Color *c);

/// Ecris un texte aux positions données en changeant la couleur de fond
///    - retour est un booléen qui défini si le retour à la ligne est permis
void drawStrBckg(short x, short y, char* str, char size, char endl, Color *cT, Color *cB);

/// Ecris un texte aux positions données
///    - retour est un booléen qui défini si le retour à la ligne est permis
void drawStr(short x, short y, char* str, char size, char endl, Color *c);

#endif // NGUI_H_INCLUDED
