#include <os.h>
#include <nRGBlib.h>
#include <maths.h>
#include "snake.h"

int main(void)
{
    // Nécessaire pour le printf()
    //unsigned intmask = TCT_Local_Control_Interrupts(0);

// Link, quand je te tient...
lcd_ingray();
lcd_isincolor();
lcd_incolor();
_scrsize();

    int score = 0, jouer = 1;
    char boxstr[280];
    Color colTexte = newRGB(0, 255, 255); //colTexte.raw = RGB(0, 255, 255);
    Color couleurFond = newRGB(0, 0, 0); //couleurFond.raw = RGB(0, 0, 0);
/*        colTexte.R = 0;
        colTexte.G = 255;
        colTexte.B = 255;
        couleurFond.R = 0;
        couleurFond.G = 0;
        couleurFond.B = 0;*/

    // Message de bienvenue
    clearScreen(&couleurFond);
	drawStr(0, 0  * CHAR_HEIGHT, "             +----------+\n"
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
                                      "Ctrl to Start !", 1, 1, &colTexte);

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

        if (score < 0) // Erreur durant l'execution
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
        clearScreen(&couleurFond);
        drawStr(0, 0  * CHAR_HEIGHT, boxstr, 1, 1, &colTexte);

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
    //TCT_Local_Control_Interrupts(intmask);
    return 0;
}
