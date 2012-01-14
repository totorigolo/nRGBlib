#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

int main()
{
    // Create a new color
    Color c1 = RGB(233, 0, 128); // Purple-gray

    // Two deffierents ways to create a line
    Line l1 = { SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5, SCREEN_WIDTH / 2 + CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5 };
    Line l2 = { .x1 = 76, .x2 = 244, .y1 = 140, .y2 = 140 };

    // Draw everything
    drawStr(SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 - CHAR_HEIGHT / 2, "Hello !", 2, 0, RGB(50, 205, 50)); // Verdâtre
    drawLine(&l1, c1);
    drawLine(&l2, c1);

    // Wait
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(100);
    }

    // And quit
    return 0;
}
