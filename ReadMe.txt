=========================================
= nRGBlib for Ndless v3.1 for TI-Nspire =
=========================================

nRGBlib v0.3

What is it ?
============

nRGBlib is a librairy which contains basic displaying routines for TI-Nspire.
It needs to work Ndless 3.1. It allows you to draw multiple shapes in color and
easily allowing the user not to waste time on the creation of these basic functions.

nRGBlib can be used on 4 bpp Nspire (ClickPad, TouchPad) and on 16 bpp Nspire (CX, CM).
Executables created with nRGBlib can be used on any Nspire without rebuilding.
nRGBlib allows to use the screen in 4bpp on CX.

The official Mercurial repository is available at:
https://bitbucket.org/totorigolo/nrgblib

What are the features of nRGBlib?
=============================================

nRGBlib is organized into several modules. In addition to static compilation, this allows
use only the modules relevant to the project to develop, and avoid needlessly executable.

For the moment, nRGBlib is organized as follows:

nCOMMON:
    - Color, RGB <-> BW conversion, precomputed colors.
    - Screen buffer, creation, drawing, screen shootinh, clearing.
    - setPixel(), clearScreen().
nGEO:
    - Shapes: Discus, Circle, Line, Rectangle, Square, Triangle.
    - Display functions of these shapes.
nTILE:
    - Tile 8x8 in one color or in multicolors.
    - Display functions of tiles.
    -> Tiles are saved INSIDE of the program.
nIMAGE:
    - Image, initializing, loading, drawing, getPixel().
    - Sub-image, initializing, loading, drawing, getPixel().
    -> Images are saved OUTSIDE of the program.
nGUI:
    - Structures: Letter, Text.
    - Display functions of these structures.
nMATHS:
    - rand() and randMinMax() functions.

To be kept informed of progress and updates, here is the official topic:
- FR: http://tiplanet.org/forum/viewtopic.php?t=8597
- IN: http://www.omnimaga.org/index.php?topic=12134

What do I need to use nRGBlib?
==============================================

- A TI-Nspire CAS and non-CAS ClickPad, Touchpad or CX.
- The OS v3.1.0.
- Ndless 3.1 installed (the last version).
- A program for sending files to the calculator like TI-Nspire Student Software.

How to use nRGBlib?
==========================

Simple method:
1. Copy the headers in "C:/Users/<Votre nom>/.ndless/include" and the .a files
   in "C:/Users/<Votre nom>/.ndless/lib".
2. Include <nRGBlib.h> in the program which use nRGBlib to access
   to the entire library, or include only the headers you need.
3. Indicate to GCC where are the .a and .h files
4. Link "libRGB.a" to your project using the "-LRGB" to Nspire-gcc.

Complicated method:
1. Copy the headers and .a files in the directory of your wish.
2. Include <nRGBlib.h> in the program which use nRGBlib to access
   to the entire library, or include only the headers you need.
3. Indicate to GCC where are the .a and .h files
4. Link "libRGB.a" to your project using the "-LRGB" to Nspire-gcc.

For 3 and 4, here is a sample Makefile:
#-- Only for the complicated method --
GCCFLAGS = -O3 -nostdlib -I"path/to/nRGBlib/sdk/include/"
LDFLAGS = -L "path/to/nRGBlib/sdk/lib/"
#---------------
GCC = nspire-gcc
LD = nspire-ld
OBJCOPY := "$(shell (which arm-elf-objcopy arm-none-eabi-objcopy arm-linux-gnueabi-objcopy | head -1) 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
OBJS = main.o bar.o -> One .o file for each .c file
DISTDIR = directory/for/the/tns/file
vpath %.tns $(DISTDIR)

all: <name_of_tns_file>.tns

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $<

%.o: %.S
	$(GCC) $(GCCFLAGS) -c $<

<name_of_tns_file>.tns: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf) -lRGB
	@mkdir -p $(DISTDIR)
	$(OBJCOPY) -O binary $(@:.tns=.elf) $(DISTDIR)/$@

clean:
	rm -f *.o *.elf
	rm -f $(DISTDIR)/<name_of_tns_file>.tns
#---------------

What about the compatibility between the Nspire?
================================================

- You can freely send files created with nRGBlib between
   any Nspire is compatible as long as Ndless 3.1 is installed :)

Troubleshooting:
================

- Nothing yet

The official bug tracker is available at:
https://bitbucket.org/totorigolo/nrgblib/issues

Many thanks to:
================

ExtendeD (Ndless, help), Lionel Debroux (continual help), Goplat (his TI-Nspire
Emulator that allowed me to test more effectively), TI-Planet (data hosting,
active community for help), and those I forgot :)

Creator and main developper:
============================

  Thomas Lacroix aka totorigolo  -  toto.rigolo@free.fr


Legal stuff:
============

Most of the work is covered by the Mozilla Public License, version 2.0 (MPL).
Please read careful the file "Mozilla-Public-License-v1.1.html" before
distributing of any part of Ndless, with or without modification.

Some parts are covered by other licenses. Others are in the public domain. These
parts are identified by the files LICENSE.txt or LICENSE.html in the sub-
directory.
