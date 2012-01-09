#include <os.h>
#include <nRGBlib.h>
#include <maths.h>
#include "snake.h"
#include "pos.h"
#include "tile_snake.h"

int Snake()
{
    char tab[41][31]; // Tableau de jeu
    int i,j; // for
    volatile int k; // for pour le hack
    char* scoreTxt;
    char score = 0; // Score final (improbable que le score dépasse 255)
    char size = 4; // Taille du serpent (idem)
    char loose = 0; // Jeu perdu
    char no_pop = 0; // Quand on mange une pomme -> ajouter une case
    int applex = 0, appley = 0; // Position de la pomme
    char direction = DROITE; // Direction du serpent
    Pos *Head = NULL; // Position de la tête
    Pos *Bottom = NULL; // de la dernière partie du serpent
    Pos *Current = NULL; // ?????

    Color colScoreTxt = { .raw = RGB(255, 255, 0)}; // Bleu
    Color colScoreFond = { .raw = RGB(0, 0, 0)}; // Noir
    Color colSerpent = { .raw = RGB(0, 255, 0)}; // Vert
    Color colFond = { .raw = RGB(222, 184, 135)}; // Marron
    Color colPomme = { .raw = RGB(255, 0, 0)}; // Rouge
        /*colScoreTxt.components.R = 0;
        colScoreTxt.components.G = 255;
        colScoreTxt.components.B = 255;
        colScoreFond.components.R = 0;
        colScoreFond.components.G = 0;
        colScoreFond.components.B = 0;
        colSerpent.components.R = 0;
        colSerpent.components.G = 255;
        colSerpent.components.B = 0;
        colFond.components.R = 222;
        colFond.components.G = 184;
        colFond.components.B = 135;
        colPomme.components.R = 255;
        colPomme.components.G = 0;
        colPomme.components.B = 0;*/

    // On efface l'écran
    clearScreen(colFond);

    // On crée la zone des scores
    score = 0;
    scoreTxt = "Score = 0";
    drawBox_(0, 0, SCREEN_WIDTH, 2 * 8, colScoreFond);
    drawStrBckg(0, 0, scoreTxt, 1, 0, colScoreTxt, colScoreFond);

    // On initialise le tableau à zéro
    for (i = 0; i < 40+1; i++)
    {
        for (j = 0; j < 30+1; j++)
        {
            tab[i][j] = 0;
        }
    }

    // On crée la chaine
    Bottom = malloc(sizeof(Pos*));
    Bottom->x = 0;
    Bottom->y = 8 * 2;
    Current = Bottom;

    // On crée le serpent (size = 4), et on l'affiche
    for (i = 0; i < size; i++)
    {
        drawSquare_(Current->x * 8, Current->y * 8, 8, colSerpent);
        tab[Current->x][Current->y] = 1;
        Current = Pos_add(Current, 1, 0); // Ajoute une case
    }

    // On crée la tête, et on la dessine
    drawTile8Unicolor(Current->x * 8, Current->y * 8, 1, tile_snake);
    tab[Current->x][Current->y] = 1;
    Head = Current;

    // On change la position de la pomme aléatoirement
    applex = abs(randMinMax(1, 40-1));
    appley = abs(randMinMax(4, 30-1));
    drawSquare_(applex * 8, appley * 8, 8, colPomme); // On dessine la pomme

    // Boucle de jeu
    while (loose == 0 && !isKeyPressed(KEY_NSPIRE_ESC))
    {
        // Gestion des touches
        if (isKeyPressed(KEY_NSPIRE_UP) || isKeyPressed(KEY_NSPIRE_8))
        {
            if (direction != BAS)
                direction = HAUT;
        }
        else if (isKeyPressed(KEY_NSPIRE_DOWN) || isKeyPressed(KEY_NSPIRE_2))
        {
            if (direction != HAUT)
                direction = BAS;
        }
        else if (isKeyPressed(KEY_NSPIRE_LEFT) || isKeyPressed(KEY_NSPIRE_4))
        {
            if (direction != DROITE)
                direction = GAUCHE;
        }
        else if (isKeyPressed(KEY_NSPIRE_RIGHT) || isKeyPressed(KEY_NSPIRE_6))
        {
            if (direction != GAUCHE)
                direction = DROITE;
        }

        // On gère le deplacement
        switch (direction)
        {
        case GAUCHE:
            Head = Pos_add(Head, -1, 0);
            break;
        case DROITE:
            Head = Pos_add(Head, 1, 0);
            break;
        case HAUT:
            Head = Pos_add(Head, 0, -1);
            break;
        case BAS:
            Head = Pos_add(Head, 0, 1);
            break;
        }

        // On verifie que la tête n'est pas hors du terrain
        if ((Head->x < 0) || (Head->x > 40-1) || (Head->y < 2) || (Head->y > 30-1))
        {
            loose = 1;
            break;
        }

        // On ajoute un element à la tête et on dessine la tête
        if ( (Head->x > (-1)) && (Head->y > (-1)))
        {
            drawTile8Unicolor(Head->x * 8, Head->y * 8, 1, tile_snake);
        }

        // On verifie que la tête ne touche pas le corps
        if (tab[Head->x][Head->y] == 1)
        {
            loose = 1;
        }

        // On ajoute la tête au tableau de jeu / colision
        tab[Head->x][Head->y] = 1;

        // Si la tête touche la pomme
        if ((applex == Head->x) && (appley == Head->y))
        {
            // Monte le score et le réaffiche
            score += 1;
            sprintf(scoreTxt, "Score = %d", score);
            drawStrBckg(0, 0, scoreTxt, 1, 0, colScoreTxt, colScoreFond);

            // On agrandit le serpent
            size++;
            no_pop = 1; // Retient qu'on ne doit pas enlever la dernière partie de la queue = ajoute une case

            // On change la position de la pomme
            do
            {
                applex = abs(randMinMax(1, 40-1));
                appley = abs(randMinMax(4, 30-1));
            }
            while (tab[applex][appley] == 1);
            drawSquare_(applex * 8, appley * 8, 8, colPomme); // On la dessine
        }

        // On enlève le dernier élément de la queue
        if (no_pop == 1) // Si on a mangé une pomme
        {
            no_pop = 0; // On enlève rien
        }
        else // On enlève la queue
        {
            tab[Bottom->x][Bottom->y] = 0;
            drawSquare_(Bottom->x * 8, Bottom->y * 8, 8, colFond); // Efface
            Bottom = Pos_pop(Bottom);
        }

        // Hack pour faire mouliner le processeur
        for (k = 0; k < 1000000; k++)
        {
            i = k / 2;
        }
    }

    clearScreen(colFond);
    return score;
}
