#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

/** Two methods exist:
    - direct rendering
    - double buffering rendering
    Change the following define to try the two methods */

#define DIRECT_RENDERING 0

int main()
{
#if DIRECT_RENDERING == 0
    // Create a new screen buffer
    ScreenBuffer *buffer = GetNewScreenBuffer();
#else
    // Get the direct rendering buffer
    ScreenBuffer *buffer = GetDirectScreenBuffer();
#endif

    // Create a new color
    Color c1 = RGB(233, 0, 128); // Purple-gray

    // Two deffierents ways to create a line
    Line l1 = { SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5, SCREEN_WIDTH / 2 + CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5 };
    Line l2 = { .x1 = 76, .x2 = 244, .y1 = 140, .y2 = 140 };

#if DIRECT_RENDERING == 0
    // Copy current screen's pixels to our buffer
    copyScreenToBuffer(buffer);
#endif

    // Draw everything
    drawStr(SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 - CHAR_HEIGHT / 2, "Hello !", 2, 0, RGB(50, 205, 50), buffer); // Verdâtre
    drawLine(&l1, c1, buffer);
    drawLine(&l2, RED, buffer);

    // Display our buffer on the screen
    display(buffer);

    // Wait
    while (any_key_pressed());
    while (!any_key_pressed())
        sleep(100);

#if DIRECT_RENDERING == 0
    // Free our screen buffer
    free(buffer);
#else
    // Forget the buffer
    buffer = NULL;
#endif

    // And quit
    return 0;
}
