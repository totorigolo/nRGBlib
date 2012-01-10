#include "charmap.h"
#include <nGUI.h>
#include <os.h>

/// Ecris un texte aux positions données en changeant la couleur de fond
///    - retour est un booléen qui défini si le retour à la ligne est permis
void drawStrBckg(short x, short y, char* str, char size, char retour, Color *cT, Color *cB)
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
            drawCharBckg(x, y, str[i], f, cT, cB);
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

/// Ecris un texte aux positions données
///    - endl est un booléen qui défini si le retour à la ligne est permis
void drawStr(short x, short y, char* str, char size, char endl, Color *c)
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
            printf("--------------------------------------\n1\n");
            drawChar(x, y, str[i], f, c);
            printf("2\n--------------------------------------\n\n");
            x += (CHAR_WIDTH * f);
        }
        // Si on va dépasser de l'écran
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
