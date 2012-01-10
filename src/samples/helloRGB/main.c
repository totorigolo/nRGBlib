#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

int main()
{
    // Sers à rien mais obligatoire pour le moment
    lcd_isincolor();
    lcd_ingray();
    lcd_incolor();
    _scrsize();
    Color cc = newRGB(123, 125, 174);

printf("########################################\n");
    drawSquare_(0, 30, 20, RGB(255, 0, 255)); // Rose
printf("########################################\n");
    //drawStr(short x, short y, char* str, char size, char endl, Color col);
    drawStr(0, 40, "Hello !", 2, 0, &cc); // Verdâtre
printf("########################################\n");
    drawStr(0, 0, "Hello !", 2, 0, RGB(137, 255, 137)); // Verdâtre
printf("########################################\n");
    Color c = getPixel(0, 35);//
printf("########################################\n");
    printf("R = %d, G = %d, B = %d\n", c.R, c.G, c.B);
printf("########################################\n");
//
    // On attends
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(50);
    }

    // Rends la main à l'OS
    return 0;
}

/*
Est-ce que ce code est censé fonctionner en C ? (code pondu tout frais, sans copié-collé ni test donc possible erreur de syntaxe)

[code]#define newRGB(r, g, b) (Color) (uint16_t) (((r % 32) << 11) | ((g % 64) << 5) | (b % 32))
#define RGB(r, g, b) (Color*) (uint16_t) (((r % 32) << 11) | ((g % 64) << 5) | (b % 32))

void setPixel(short x, short y, Color *c)
{
    // ...
    bar = c->raw;
}
void drawBox(short x, short y, Color *c)
{
    // ...
    setPixel(x, y, c); // Fonctionne pas ici (voir plus bas)
}

int main()
{
    Color cc = newRGB(123, 125, 174);

    drawBox(0, 40, &cc); // Fonctionne
    drawBox(0, 0, RGB(137, 255, 137)); // Fonctionne pas (voir plus haut)

    return 0;
}[/code]

Ça ne marche pas surement à cause du pointeur temporaire, mais existe-t-il un autre moyen ? Ou est-ce que le pointeur est utile ?

PS: Nouveau dépot Mercurial (volontairement pas en première page / présentation) : [url]https://bitbucket.org/totorigolo/nrgblib/overview[/url]
*/
