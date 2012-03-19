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

/// Load an image from a .h file
void loadImage(Image *img, char* path)
{
    unsigned int i, j;
    FILE *file;
    file = fopen(path, "rb");

    // File doesn't exist
    if (file == NULL)
    {
        printf("File doesn't exist!\n");
        return;
    }

    // Read the image dimensions
    fread(&img->w, 1, sizeof(unsigned int), file);
    fread(&img->h, 1, sizeof(unsigned int), file);
    printf("Image size:\n - width = %d\n - height = %d\n", img->w, img->h);

    // TODO: Free old image - loadImage.c
    /*/ Free old data
    if (img->data != NULL)
        free(img->data);*/

    // Alloc image data
    img->data = calloc(img->w * img->h, sizeof(Color));
    if (img->data == NULL)
        exit(0);

    // Load image
    printf("Loading image...\n");
    for (i = 0; i < img->w; i++)
    {
        //printf("%d/%d... ", i, img->w);
        for (j = 0; j < img->h; j++)
        {
            fread(&img->data[i * img->w + j], 1, sizeof(Color), file);
        }
    }

    // Close our file
    fclose(file);
    printf("Image loaded successfully!\n");
}
