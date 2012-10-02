#include <os.h>
#include <nIMAGE.h>
#include <nGUI.h>

int main(int argc, char* argv[])
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Create the image
    int speed = 1;
    Image image;

    // Get the image path from argv
    char *path;
    if (argc > 1)
    {
        strcpy(path, argv[1]);
    }
    // Or ask for the image
    else
    {
        show_msgbox("Ouvrir une image", "Rentrez le chemin de l'image a ouvrir, ou pressez Esc.\nOuvre uniquement les images converties.");
        if (show_msg_user_input("Ouvrir une image", "", "/documents/ndless/img.nif.tns", &path) < 0)
            return 0;
    }

    // Load the image
    initImage(&image);
    loadImage(&image, path);

    clearScreen(RGB(200, 200, 200), buffer);
    while (1)
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_ESC))
            break;

        // Up and down
        if (isKeyPressed(KEY_NSPIRE_UP) || isKeyPressed(KEY_NSPIRE_8))
            image.y += speed;
        if (isKeyPressed(KEY_NSPIRE_DOWN) || isKeyPressed(KEY_NSPIRE_2))
            image.y -= speed;

        // Left and right
        if (isKeyPressed(KEY_NSPIRE_LEFT) || isKeyPressed(KEY_NSPIRE_4))
            image.x += speed;
        if (isKeyPressed(KEY_NSPIRE_RIGHT) || isKeyPressed(KEY_NSPIRE_6))
            image.x -= speed;

        // Up left/right
        if (isKeyPressed(KEY_NSPIRE_LEFTUP) || isKeyPressed(KEY_NSPIRE_7))
        {
            image.y += speed;
            image.x += speed;
        }
        if (isKeyPressed(KEY_NSPIRE_UPRIGHT) || isKeyPressed(KEY_NSPIRE_9))
        {
            image.y += speed;
            image.x -= speed;
        }

        // Down left/right
        if (isKeyPressed(KEY_NSPIRE_DOWNLEFT) || isKeyPressed(KEY_NSPIRE_1))
        {
            image.y -= speed;
            image.x += speed;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHTDOWN) || isKeyPressed(KEY_NSPIRE_3))
        {
            image.y -= speed;
            image.x -= speed;
        }

        if (isKeyPressed(KEY_NSPIRE_PLUS))
            speed += 1;
        if (isKeyPressed(KEY_NSPIRE_MINUS))
            speed -= 1;

        if (isKeyPressed(KEY_NSPIRE_DEL) || isKeyPressed(KEY_NSPIRE_5))
        {
            image.x = 0;
            image.y = 0;
            speed = 1;
        }

        // Draw the image
        clearBuffer(RGB(200, 200, 200), buffer);
        drawImage(&image, buffer);

        // Draw the speed
        if (speed < 0)
            drawChar(0, 0, '-', 1, RED, buffer);
        else
            drawChar(0, 0, '+', 1, RED, buffer);
        drawChar(8, 0, '0' + abs(speed) / 10, 1, RED, buffer);
        drawChar(16, 0, '0' + abs(speed) % 10, 1, RED, buffer);

        // Display our buffer on the screen
        display(buffer);

        if (!has_colors || !lcd_isincolor())
        {
            //sleep(20);

            /** Doesn't work with CX !! **/
            // Wait to save the battery
            idle();
            while (!any_key_pressed());
            idle();
        }
    }

    // Delete our image
    deleteImage(&image);

    // Free our screen buffer
    free(buffer);

    // And quit
    return 0;
}
