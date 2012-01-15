#include <os.h>
#include <nRGBlib.h>
#include <nMATHS.h>
#include "snake.h"

int main(void)
{
    int score = 0, jouer = 1;
    char boxstr[280];
    Color colTexte = RGB(0, 255, 255);
    Color couleurFond = RGB(0, 0, 0);

    // Message de bienvenue
    clearScreen(couleurFond);
	drawStr(0, 0  * CHAR_HEIGHT,    "             +----------+\n"
                                    "             | CX Snake |\n"
                                    "             +----------+\n"
                                    "by totorigolo  : CX code\n"
                                    "by Sam101      : Nspire classic code\n"
                                    "---------------------------------------\n"
                                    "Thanks to TI-Planet.org, critor,\n"
                                    "  ExtendeD & all others\n"
                                    "---------------------------------------\n"
                                    "Controls:\n"
                                    "   - Up    : Up & 8\n"
                                    "   - Down  : Down & 2\n"
                                    "   - Right : Right & 6\n"
                                    "   - Left  : Left & 4\n\n\n"
                                    "Ctrl to Start !", 1, 1, colTexte);

    //Initialise le genérateur
    while (!isKeyPressed(KEY_NSPIRE_CTRL))
    {
        rand();
    }

    while (jouer)
    {
        // Joue et récupère le score
        score = 0;
        score = Snake();

        if (score < 0) // Erreur durant l'exécution
            break;

        // Crée le message de fin
        sprintf(boxstr, "             +-----------+\n"
                        "             | Game Over |\n"
                        "             +-----------+\n\n"
                        "Be careful !\n"
                        "And try again :p\n\n"
                        "---------------------------------------\n"
                        "Score = %d\n\n"
                        "---------------------------------------\n"
                        "Press:\n"
                        "   - Ctrl to try again.\n"
                        "   - Esc to quit.", score);

        // Affiche le Game Over
        clearScreen(couleurFond);
        drawStr(0, 0  * CHAR_HEIGHT, boxstr, 1, 1, colTexte);

        while (1)
        {
            if (isKeyPressed(KEY_NSPIRE_CTRL))
                break;
            else if (isKeyPressed(KEY_NSPIRE_ESC))
            {
                jouer = 0;
                break;
            }
        }
    }

    // Rends la main à l'OS
    return 0;
}
