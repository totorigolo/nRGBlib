AS = nspire-as
AR := "$(shell (which arm-elf-ar arm-none-eabi-ar arm-linux-gnueabi-ar | head -1) 2>/dev/null)"
GCC = nspire-gcc
GCCFLAGS = -Os -nostdlib -I"../include"
LD = nspire-ld
LDFLAGS = s -nostdlib
OBJCOPY := "$(shell (which arm-elf-objcopy arm-none-eabi-objcopy arm-linux-gnueabi-objcopy | head -1) 2>/dev/null)"
LIB = libRGB.a
#DISTDIR = ../lib
DISTDIR = ../../../ndless-v3.1/sdk/lib
vpath %.a $(DISTDIR)
OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

all: static $(LIB)
	echo 'Done...'

%.o: %.c
	echo 'Building $<...'
	$(GCC) $(GCCFLAGS) -c $<

%.o: %.S
	echo 'Building $<...'
	$(AS) $(GCCFLAGS) -c $<

%.elf: %.o
	echo 'Building .elf file...'
	$(LD) $(LDFLAGS) $^ -o $@ -lndls

static:
	@mkdir -p $(DISTDIR)

$(LIB): $(OBJS)
	$(AR) rcs $(DISTDIR)/$(LIB) $^

clean:
	echo 'Deleting all .o, .elf and .a...'
	rm -rf *.o *.elf *.a
	echo 'Deleting lib...'
	rm -f $(DISTDIR)/$(LIB)

.PHONY: samples
samples:
	(cd ../samples && make)
rsamples:
	(cd ../samples && make clean all)

all_sam: all
	(cd ../samples && make)
all_rsam: all
	(cd ../samples && make clean all)
clr_all_rsam: clean all
	(cd ../samples && make clean all)







