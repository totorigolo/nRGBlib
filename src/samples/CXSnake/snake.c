#include <os.h>
#include <nRGBlib.h>
#include <nMATHS.h>
#include "snake.h"
#include "pos.h"
#include "tile_snake.h"

int Snake(ScreenBuffer *buffer)
{
    char tab[41][31]; // Game array
    int i,j; // for loops
    char* scoreTxt;
    unsigned char score = 0; // Final score (it should not be over 255)
    unsigned char size = 4; // Snake's size (idem)
    char loose = 0;
    int lvl = 0; // Level, for the difficulty -> every 10 apples
    char no_pop = 0; // When eating an apple -> add a block
    Square apple; // Apple
    char direction = RIGHT; // Snake direction
    Pos *Head = NULL; // Head position
    Pos *Bottom = NULL; // Last snake position
    Pos *Current = NULL; // Current drawed part position

    Color colScoreTxt = CYAN;
    Color colScoreFond = BLACK;
    Color colSerpent = GREEN;
    Color colFond = RGB(220, 220, 220); // Light grey
    Color colPomme = RED;

    // Clear the screen
    clearScreen(colFond, buffer);

    // Create the score area
    score = 0;
    scoreTxt = "Score = 0    ";
    drawBox_Sl(0, 0, SCREEN_WIDTH, 2 * 8, colScoreFond, buffer);
    drawStrBckg(0, 0, scoreTxt, 1, 0, colScoreTxt, colScoreFond, buffer);

    // Init game array to zero
    for (i = 0; i < 40+1; i++)
        for (j = 0; j < 30+1; j++)
            tab[i][j] = 0;

    // Create the string
    Bottom = malloc(sizeof(Pos*));
    Bottom->x = 0;
    Bottom->y = 8 * 2;
    Current = Bottom;

    // Create the snake (size == 4), and draw it
    for (i = 0; i < size; i++)
    {
        drawSquare_Sl(Head->x * 8, Head->y * 8, 8, colSerpent, buffer);
        tab[Current->x][Current->y] = 1;
        Current = Pos_add(Current, 1, 0); // Ajoute une case
    }

    // Create the head, and draw it
    drawSquare_Sl(Current->x * 8, Current->y * 8, 8, colSerpent, buffer);
    tab[Current->x][Current->y] = 1;
    Head = Current;

    // Choose random position for the applen and draw it
    apple.side = 8;
    apple.x = abs(randMinMax(1, 40-1)) * 8;
    apple.y = abs(randMinMax(4, 30-1)) * 8;
    drawSquareSl(&apple, colPomme, buffer);

    // Main loop
    while (loose == 0 && !isKeyPressed(KEY_NSPIRE_ESC))
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_UP) || isKeyPressed(KEY_NSPIRE_8))
        {
            if (direction != DOWN)
                direction = UP;
        }
        if (isKeyPressed(KEY_NSPIRE_DOWN) || isKeyPressed(KEY_NSPIRE_2))
        {
            if (direction != UP)
                direction = DOWN;
        }
        if (isKeyPressed(KEY_NSPIRE_LEFT) || isKeyPressed(KEY_NSPIRE_4))
        {
            if (direction != RIGHT)
                direction = LEFT;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHT) || isKeyPressed(KEY_NSPIRE_6))
        {
            if (direction != LEFT)
                direction = RIGHT;
        }

        // Manage the move
        switch (direction)
        {
        case LEFT:
            Head = Pos_add(Head, -1, 0);
            break;
        case RIGHT:
            Head = Pos_add(Head, 1, 0);
            break;
        case UP:
            Head = Pos_add(Head, 0, -1);
            break;
        case DOWN:
            Head = Pos_add(Head, 0, 1);
            break;
        }

        // Check that the head isn't out of the screen
        if ((Head->x < 0) || (Head->x > 40-1) || (Head->y < 2) || (Head->y > 30-1))
        {
            loose = 1;
            break;
        }

        // Append a block at the head and draw it
        if ( (Head->x > (-1)) && (Head->y > (-1)))
            drawSquare_Sl(Head->x * 8, Head->y * 8, 8, colSerpent, buffer);

        // Check that the head isn't touching the body
        if (tab[Head->x][Head->y] == 1)
        {
            loose = 1;
            break;
        }

        // Append the head to the game array
        tab[Head->x][Head->y] = 1;

        // If the head touch the apple
        if ((apple.x / 8 == Head->x) && (apple.y / 8 == Head->y))
        {
            // Increase the score and draw it
            score += 1;
            sprintf(scoreTxt, "Score = %d  ", score);
            drawStrBckg(0, 0, scoreTxt, 1, 0, colScoreTxt, colScoreFond, buffer);

            // Increase difficulty every 10 apples
            if (score % 6 == 0)
                lvl++;

            // Enlarge the snake
            size++;
            no_pop = 1; // Save that we don't have to remove the snake's last block (= add a block)

            // Change apple position and draw it
            do
            {
                apple.x = abs(randMinMax(1, 40-1)) * 8;
                apple.y = abs(randMinMax(4, 30-1)) * 8;
            }
            while (tab[apple.x / 8][apple.y / 8] == 1);
            drawSquareSl(&apple, colPomme, buffer);
        }

        // Remove the snake's last block
        if (no_pop == 1) // Except if we had eat an apple
            no_pop = 0;
        else
        {
            tab[Bottom->x][Bottom->y] = 0;
            drawSquare_Sl(Bottom->x * 8, Bottom->y * 8, 8, colFond, buffer);
            Bottom = Pos_pop(Bottom);
        }

        // Display the buffer on the screen
        display(buffer);

        // Manage the speed for the difficulty
        sleep(abs(70 - (lvl * 6)));
    }
    // Display the buffer
    display(buffer);

    return score;
}
