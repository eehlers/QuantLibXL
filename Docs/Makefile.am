
EXTRA_DIST = \
    docs.vcproj \
    Doxyfile \
    Makefile.vc

DOXYGEN_INPUT := $(wildcard pages/*.dox) \
                 $(wildcard pages_auto/*.dox)

all: docs-html

clean: docs-clean

.PHONY: docs-html docs-clean

docs-html: .time-stamp

docs-clean:
	rm -rf html
	rm -f .time-stamp

#	mkdir -p html/images
#	cp -p images/* html/images
.time-stamp: Doxyfile $(DOXYGEN_INPUT)
	$(DOXYGEN) Doxyfile
	touch .time-stamp

