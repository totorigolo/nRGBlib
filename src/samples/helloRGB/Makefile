GCCFLAGS = -O3 -nostdlib -I"../../include"
LDFLAGS = -L "../../lib"
GCC = nspire-gcc
LD = nspire-ld
OBJCOPY := "$(shell (which arm-elf-objcopy arm-none-eabi-objcopy arm-linux-gnueabi-objcopy | head -1) 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
OBJS = main.o
#DISTDIR = bin/
DISTDIR = ../bin
vpath %.tns $(DISTDIR)

all: HelloRGB.tns

%.o: %.c
	echo 'Building $<...'
	$(GCC) $(GCCFLAGS) -c $<

%.o: %.S
	echo 'Building $<...'
	$(GCC) $(GCCFLAGS) -c $<

HelloRGB.tns: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf) -lRGB
	@mkdir -p $(DISTDIR)
	$(OBJCOPY) -O binary $(@:.tns=.elf) $(DISTDIR)/$@

clean:
	rm -f *.o *.elf
	rm -f $(DISTDIR)/HelloRGB.tns
