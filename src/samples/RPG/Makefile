GCC = nspire-gcc
LD = nspire-ld
GCCFLAGS = -Os -nostdlib -I"../../include"
LDFLAGS = -L "../../lib"
OBJCOPY := "$(shell (which arm-elf-objcopy arm-none-eabi-objcopy arm-linux-gnueabi-objcopy | head -1) 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
OBJS = map.o main.o
#DISTDIR = bin/
DISTDIR = ../bin/rpg
vpath %.tns $(DISTDIR)

all: RPG.tns

%.o: %.c
	echo 'Building $<...'
	$(GCC) $(GCCFLAGS) -c $<

%.o: %.S
	echo 'Building $<...'
	$(GCC) $(GCCFLAGS) -c $<

RPG.tns: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf) -lRGB
	@mkdir -p $(DISTDIR)
	$(OBJCOPY) -O binary $(@:.tns=.elf) $(DISTDIR)/$@

clean:
	rm -f *.o *.elf
	rm -f $(DISTDIR)/RPG.tns
