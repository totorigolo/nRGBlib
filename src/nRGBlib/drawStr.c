#include "charmap.h"
#include <nGUI.h>
#include <os.h>

/// Ecris un texte aux positions donn�es en changeant la couleur de fond
///    - retour est un bool�en qui d�fini si le retour � la ligne est permis
void drawStrBckgRGB(short x, short y, char* str, char size, char retour, char Rt, char Gt, char Bt, char Rf, char Gf, char Bf)
{
    short i, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < strlen(str); i++)
    {
        // Si le caract�re actuel est un '\n'
        if (str[i] == '\n') // 0x0A = '\n'
        {
            // Si on peut faire des retours � la ligne, on y va
            if (retour)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on fait comme si c'�tait un espace
            else
            {
                x += (CHAR_WIDTH * f);
            }
        }
        else
        {
            drawCharBckgRGB(x, y, str[i], f, Rt, Gt, Bt, Rf, Gf, Bf);
            x += (CHAR_WIDTH * f);
        }
        // Si on va d�passer de l'acran
        if (x > SCREEN_WIDTH - CHAR_WIDTH)
        {
            // Retour � la ligne activ�, on saute
            if (retour)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on arr�te la ligne
            else
                break;
        }
    }
}
inline void drawStrBckg(short x, short y, char* str, char size, char retour, Color colT, Color colF)
{
    drawStrBckgRGB(x, y, str, size, retour, colT.components.R, colT.components.G, colT.components.B, colF.components.R, colF.components.G, colF.components.B);
}

/// Ecris un texte aux positions donn�es
///    - endl est un bool�en qui d�fini si le retour � la ligne est permis
void drawStrRGB(short x, short y, char* str, char size, char endl, char R, char G, char B)
{
    short i, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < strlen(str); i++)
    {
        // Si le caract�re actuel est un '\n'
        if (str[i] == '\n') // 0x0A = '\n'
        {
            // Si on peut faire des retours � la ligne, on y va
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on fait comme si c'�tait un espace
            else
            {
                x += (CHAR_WIDTH * f);
            }
        }
        else
        {
            drawCharRGB(x, y, str[i], f, R, G, B);
            x += (CHAR_WIDTH * f);
        }
        // Si on va d�passer de l'acran
        if (x >= SCREEN_WIDTH - CHAR_WIDTH)
        {
            // Retour � la ligne activ�, on saute
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on arr�te la ligne
            else
                break;
        }
    }
}
inline void drawStr(short x, short y, char* str, char size, char endl, Color c)
{
    drawStrRGB(x, y, str, size, endl, c.components.R, c.components.G, c.components.B);
}
