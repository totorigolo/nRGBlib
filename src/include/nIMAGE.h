#ifndef NIMAGE_H_INCLUDED
#define NIMAGE_H_INCLUDED

#include "nCOMMON.h"

typedef struct Image {
    int16_t x;
    int16_t y;
    uint16_t w;
    uint16_t h;
    Color *data;
} Image;

#define GET_IMG_PIXEL(x, y, img) img->data[y + x * img->h]

/// Load an image from a .h file
void loadImage(Image *img, char *path);

/// Draw the image on the given buffer
void drawImage(Image *img, ScreenBuffer buffer);

/// Delete an image
// Just define x, y, w, h to 0 and free data
void deleteImage(Image *img);

#endif // NIMAGE_H_INCLUDED
