CC     = ppc-amigaos-gcc
STRIP  = ppc-amigaos-strip

OPTIMIZE = -O2
DEBUG    = -g
INCLUDES = -I../$(WAVPACKDIR)/include
WARNINGS = -Wall -Wno-stringop-truncation
DEFINES  = -DPACKAGE_VERSION=\"5.1.0\" -DVERSION_OS=\"AmigaOS\"

CFLAGS  = $(OPTIMIZE) $(DEBUG) $(INCLUDES) $(WARNINGS) $(DEFINES)
LDFLAGS = -static
LIBS    = -lunix

STRIPFLAGS = -R.comment --strip-unneeded-rel-relocs

.PHONY: all
all: wavpack wvgain wvtag wvunpack

wavpack: wavpack.o caff.o dsdiff.o dsf.o import_id3.o md5.o riff.o utils.o wave64.o ../libwavpack.a
	$(CC) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

wvgain: wvgain.o utils.o ../libwavpack.a
	$(CC) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

wvtag: wvtag.o import_id3.o utils.o ../libwavpack.a
	$(CC) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

wvunpack: wvunpack.o caff.o dsdiff.o dsf.o md5.o riff.o utils.o wave64.o ../libwavpack.a
	$(CC) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

.PHONY: clean
clean:
	rm -f wavpack wavpack.debug
	rm -f wvgain wvgain.debug
	rm -f wvtag wvtag.debug
	rm -f wvunpack wvunpack.debug
	rm -f *.o

