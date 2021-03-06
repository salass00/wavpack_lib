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

STATIC_SRCS = static/autoinit.c static/stubs.c
STATIC_OBJS = $(STATIC_SRCS:.c=.o)

.PHONY: all
all: $(TARGET) libwavpack.a compile-cli-tools

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

libwavpack.a: $(STATIC_OBJS)
	$(AR) -crv $@ $^
	$(RANLIB) $@

.PHONY: compile-cli-tools
compile-cli-tools: libwavpack.a
	$(MAKE) -C cli WAVPACKDIR=$(WAVPACKDIR)

.PHONY: clean
clean:
	$(MAKE) -C cli clean
	rm -f $(TARGET) $(TARGET).debug *.o main/*.o
	rm -f libwavpack.a static/*.o
	rm -rf wavpack-build

.PHONY: revision
revision:
	bumprev $(VERSION) $(TARGET)

