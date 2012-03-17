/****************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The Original Code is nRGBlib code.
 *
 * The Initial Developer of the Original Code is Thomas LACROIX aka totorigolo
 * <toto.rigolo@free.fr>.
 * Portions created by the Initial Developer are Copyright (C) 2011-2012
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 ****************************************************************************/

#include <os.h>
#include <nRGBlib.h>
#include <nMATHS.h>
#include "snake.h"

int main(void)
{
    // Create a new screen buffer
    ScreenBuffer *buffer = GetNewScreenBuffer();

    int score = 0, play = 1;
    char boxstr[280];
    Color colTexte = CYAN;
    Color couleurFond = BLACK;

    // Draw a wellcoming message
    clearScreen(couleurFond, buffer);
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
                                    "Ctrl to Start !\n"
                                    "                      Or Esc to quit...", 1, 1, colTexte, buffer);
    display(buffer);

    // Wait and init rand
    while (!isKeyPressed(KEY_NSPIRE_CTRL) && !(play == isKeyPressed(KEY_NSPIRE_ESC)))
        rand();

    // Main loop
    while (play)
    {
        // Plays and gets the score
        score = 0;
        score = Snake(buffer);

        // Check if there were not any error
        if (score < 0)
            break;

        // Create the end message
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

        // Draw the message
        clearScreen(couleurFond, buffer);
        drawStr(0, 0  * CHAR_HEIGHT, boxstr, 1, 1, colTexte, buffer);

        // Display the buffer on the screen
        display(buffer);

        // Wait
        while (1)
        {
            rand();
            if (isKeyPressed(KEY_NSPIRE_CTRL))
                break;
            else if (isKeyPressed(KEY_NSPIRE_ESC))
            {
                play = 0;
                break;
            }
        }
    }

    // Free our screen buffer
    free(buffer);

    return 0;
}
