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
    Color *pdata;
    unsigned int i;
    FILE *file;
    file = fopen(path, "rb");
    if (file != NULL)
    {
        // Read the image dimensions
        fread(&img->w, 1, sizeof(unsigned int), file);
        fread(&img->h, 1, sizeof(unsigned int), file);

        // TODO: Free old image - loadImage.c
        /*/ Free old data
        if (img->data != NULL)
            free(img->data);*/

        // Malloc image data
        img->size = 0;
        img->data = malloc(img->w * img->h * sizeof(Color));
        if (img->data == NULL)
            exit(0);
        img->size = img->w * img->h * sizeof(Color);

        // Load image
        for (pdata = img->data; pdata < img->data + img->size; pdata += sizeof(Color))
        {
            fread(pdata, 1, sizeof(Color), file);
        }
        pdata = NULL;

        // Close our file
        fclose(file);
    }
}
