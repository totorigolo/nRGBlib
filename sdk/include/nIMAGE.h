#ifndef NIMAGE_H_INCLUDED
#define NIMAGE_H_INCLUDED

#include "nCOMMON.h"

/* Images */

typedef struct Image {
    int16_t x;
    int16_t y;
    uint16_t w;
    uint16_t h;
    void *data;
} Image;

/// Init an image
void initImage(Image *img);

/// Delete an image
// Just define x, y, w, h to 0 and free data
void deleteImage(Image *img);

/// Load an image from a converted image file
BOOL loadImage(Image *img, char *path);

/// Draw the image on the given buffer
void drawImage(Image *img, ScreenBuffer buffer);

/// Get a pixel from any image
inline void* getImagePixel(uint16_t x, uint16_t y, Image *img);

/// Get a pixel from a 4bpp image
inline void* getImagePixel_4bpp(uint16_t x, uint16_t y, Image *img);

/// Get a pixel from a 16bpp image
inline void* getImagePixel_16bpp(uint16_t x, uint16_t y, Image *img);

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

/// Set the ImageSubrect's image
void setImage(ImageSubrect *imgsub, Image *img);

/// Draw the image's subrect on the given buffer
void drawImageSubrect(ImageSubrect *imgsub, ScreenBuffer buffer);

/// Get a pixel from any image subrect
inline void* getImageSubPixel(uint16_t x, uint16_t y, ImageSubrect *sub);

/// Get a pixel from a 4bpp image subrect
inline void* getImageSubPixel_4bpp(uint16_t x, uint16_t y, ImageSubrect *sub);

/// Get a pixel from a 16bpp image subrect
inline void* getImageSubPixel_16bpp(uint16_t x, uint16_t y, ImageSubrect *sub);

#endif // NIMAGE_H_INCLUDED
