#ifndef NIMAGE_H_INCLUDED
#define NIMAGE_H_INCLUDED

#include "nCOMMON.h"

/* Images */

typedef struct Image {
    int16_t x;
    int16_t y;
    uint16_t w;
    uint16_t h;
    Color *data;
} Image;

#define GET_IMG_PIXEL(x, y, img) img->data[((x) + ((y) * (img->w)))]

/// Init an image
void initImage(Image *img);

/// Delete an image
// Just define x, y, w, h to 0 and free data
void deleteImage(Image *img);

/// Load an image from a converted image file
BOOL loadImage(Image *img, char *path);

/// Draw the image on the given buffer
void drawImage(Image *img, ScreenBuffer buffer);

/* Image sub-rect */

typedef struct ImageSubrect {
    int16_t x;
    int16_t y;
    int16_t offset_x;
    int16_t offset_y;
    uint16_t w;
    uint16_t h;
    Image *image;
} ImageSubrect;

#define GET_SUBRECT_PIXEL(x, y, subrect) GET_IMG_PIXEL(((x) + (subrect->offset_x)), ((y) + (subrect->offset_y)), (subrect->image))

/// Set the ImageSubrect's image
void setImage(ImageSubrect *imgsub, Image *img);

/// Draw the image's subrect on the given buffer
void drawImageSubrect(ImageSubrect *imgsub, ScreenBuffer buffer);

#endif // NIMAGE_H_INCLUDED
