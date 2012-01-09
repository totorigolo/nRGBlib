#include "charmap.h"
#include <nGUI.h>
#include <os.h>

/// Ecris un texte aux positions données en changeant la couleur de fond
///    - retour est un booléen qui défini si le retour à la ligne est permis
void drawStrBckgRGB(short x, short y, char* str, char size, char retour, char Rt, char Gt, char Bt, char Rf, char Gf, char Bf)
{
    short i, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < strlen(str); i++)
    {
        // Si le caractère actuel est un '\n'
        if (str[i] == '\n') // 0x0A = '\n'
        {
            // Si on peut faire des retours à la ligne, on y va
            if (retour)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on fait comme si c'était un espace
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
        // Si on va dépasser de l'acran
        if (x > SCREEN_WIDTH - CHAR_WIDTH)
        {
            // Retour à la ligne activé, on saute
            if (retour)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on arrête la ligne
            else
                break;
        }
    }
}
inline void drawStrBckg(short x, short y, char* str, char size, char retour, Color colT, Color colF)
{
    drawStrBckgRGB(x, y, str, size, retour, colT.components.R, colT.components.G, colT.components.B, colF.components.R, colF.components.G, colF.components.B);
}

/// Ecris un texte aux positions données
///    - endl est un booléen qui défini si le retour à la ligne est permis
void drawStrRGB(short x, short y, char* str, char size, char endl, char R, char G, char B)
{
    short i, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < strlen(str); i++)
    {
        // Si le caractère actuel est un '\n'
        if (str[i] == '\n') // 0x0A = '\n'
        {
            // Si on peut faire des retours à la ligne, on y va
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on fait comme si c'était un espace
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
        // Si on va dépasser de l'acran
        if (x >= SCREEN_WIDTH - CHAR_WIDTH)
        {
            // Retour à la ligne activé, on saute
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Sinon on arrête la ligne
            else
                break;
        }
    }
}
inline void drawStr(short x, short y, char* str, char size, char endl, Color c)
{
    drawStrRGB(x, y, str, size, endl, c.components.R, c.components.G, c.components.B);
}
