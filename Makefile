TARGET  = wavpack.library
VERSION = 53

WAVPACKDIR = wavpack-5.1.0

CC     = ppc-amigaos-gcc
STRIP  = ppc-amigaos-strip
AR     = ppc-amigaos-ar
RANLIB = ppc-amigaos-ranlib

BUILDSYS = $(shell uname -s)

# Only use host argument if cross-compiling
ifneq ($(BUILDSYS),AmigaOS)
	HOSTARG = --host=ppc-amigaos
else
	HOSTARG = 
endif

OPTIMIZE = -O2 -fomit-frame-pointer
DEBUG    = -g
INCLUDES = -I./include -I./$(WAVPACKDIR)/include
WARNINGS = -Wall -Wwrite-strings -Werror

CFLAGS  = $(OPTIMIZE) $(DEBUG) $(INCLUDES) $(WARNINGS)
LDFLAGS = -static
LIBS    = 

STRIPFLAGS = -R.comment --strip-unneeded-rel-relocs

main_SRCS = main/Obtain.c main/Release.c
main_OBJS = $(main_SRCS:.c=.o)

OBJS = init.o $(main_OBJS)

STATIC_SRCS = $(wildcard static/*.c)
STATIC_OBJS = $(STATIC_SRCS:.c=.o)

.PHONY: all
all: $(TARGET)

init.o: $(TARGET)_rev.h wavpack_vectors.c wavpack_vectors.h

$(main_OBJS): wavpack_vectors.h

wavpack-build/Makefile: $(WAVPACKDIR)/configure
	mkdir -p wavpack-build
	rm -rf wavpack-build/*
	cd wavpack-build && ../$(WAVPACKDIR)/configure --prefix=/SDK/local/newlib $(HOSTARG) --disable-shared --disable-largefile

.PHONY: build-wavpack
build-wavpack: wavpack-build/Makefile
	$(MAKE) -C wavpack-build

$(TARGET): build-wavpack $(OBJS)
	$(CC) $(LDFLAGS) -nostartfiles -o $@.debug $(OBJS) wavpack-build/src/.libs/libwavpack.a $(LIBS)
	$(STRIP) -R.comment -o $@ $@.debug

.PHONY: clean
clean:
	rm -f *.o main/*.o
	rm -rf wavpack-build

.PHONY: revision
revision:
	bumprev $(VERSION) $(TARGET)

