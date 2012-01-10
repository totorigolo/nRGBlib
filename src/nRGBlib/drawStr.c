#include "charmap.h"
#include <nGUI.h>
#include <os.h>

/// Ecris un texte aux positions donn�es en changeant la couleur de fond
///    - retour est un bool�en qui d�fini si le retour � la ligne est permis
void drawStrBckg(short x, short y, char* str, char size, char retour, Color *cT, Color *cB)
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
            drawCharBckg(x, y, str[i], f, cT, cB);
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

/// Ecris un texte aux positions donn�es
///    - endl est un bool�en qui d�fini si le retour � la ligne est permis
void drawStr(short x, short y, char* str, char size, char endl, Color *c)
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
            printf("--------------------------------------\n1\n");
            drawChar(x, y, str[i], f, c);
            printf("2\n--------------------------------------\n\n");
            x += (CHAR_WIDTH * f);
        }
        // Si on va d�passer de l'�cran
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
