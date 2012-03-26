SUBDIRS = RPG images helloRGB GeometriCX CXSnake
DISTDIR = ../../sdk/calcbin/samples

all: distdir
	@for i in $(SUBDIRS); do \
	echo "make all in $$i..."; \
  (cd $$i; make all) || exit 1; done
	echo 'Done! (samples)'

distdir:
	@mkdir -p $(DISTDIR)

clean:
	@for i in $(SUBDIRS); do \
	echo "Clearing in $$i..."; \
	(cd $$i; make clean) || exit 1; done
