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
#include <nIMAGE.h>

/// Load an image from a converted image file
BOOL loadImage(Image *img, char* path)
{
    uint32_t i;
    void* rawImg = NULL, *rawptr = NULL;
    uint8_t *img_ptr = NULL;
    FILE *file;
    file = fopen(path, "rb");

    // File doesn't exist
    if (file == NULL)
    {
        //printf("File doesn't exist! (%s)\n", path);
        return FALSE;
    }

    // (Re)init images values
    img->x = 0;
    img->y = 0;
    img->w = 0;
    img->h = 0;

    // Read the image dimensions
    fread(&img->w, 1, sizeof(unsigned int), file);
    fread(&img->h, 1, sizeof(unsigned int), file);
    //printf("Image size:\n - width = %d\n - height = %d\n", img->w, img->h);

    // Free old data
    free(img->data);
    img->data = NULL;

    // Alloc image data
    if (!has_colors || !lcd_isincolor())
    {
        img->data = (uint8_t*) calloc(img->w * img->h / 2, sizeof(uint8_t));
        rawImg = (Color*) calloc(img->w * img->h, sizeof(Color));
    }
    else
        img->data = (Color*) calloc(img->w * img->h, sizeof(Color));

    if (img->data == NULL)
    {
        //printf("Failed to alloc memory: the image is too big.\n");
        exit(0);
    }

    // Load image
    //printf("Loading image...\n");
    if (!has_colors || !lcd_isincolor())
    {
        fread(rawImg, sizeof(Color), img->w * img->h, file);

        img_ptr = (uint8_t*)img->data;
        rawptr = rawImg;

        for (i = 0; i < img->w * img->h / 2; rawptr += 2 * sizeof(Color), img_ptr += sizeof(uint8_t), i++)
            *img_ptr = (getBW(*(Color*)rawptr) << 4) | (getBW(*(Color*)(rawptr + sizeof(Color))));

        free(rawImg);
        rawptr = NULL;
    }
    else
        fread(img->data, sizeof(Color), img->w * img->h, file);

    // Close our file
    fclose(file);
    //printf("Image loaded successfully!\n");

    return TRUE;
}
