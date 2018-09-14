/*
 * Copyright (C) 2018 Fredrik Wikstrom <fredrik@a500.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS `AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <interfaces/wavpack.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <stdlib.h>

struct Library *WavpackBase;
struct WavpackIFace *IWavpack;

#define CONSTRUCTOR(name) USED __attribute__((section(".ctors.zzzy"))) static void (* name##_constructor_ptr)(void)
#define DESTRUCTOR(name) USED __attribute__((section(".dtors.zzzy"))) static void (* name##_destructor_ptr)(void)

void _INIT_5_IWavpack(void)
{
	WavpackBase = IExec->OpenLibrary("wavpack.library", 53);
	if (WavpackBase == NULL)
	{
		IDOS->PutErrStr("ERROR: Failed to open wavpack.library V53.\n");
		abort();
	}

	IWavpack = (struct WavpackIFace *)IExec->GetInterface(WavpackBase, "main", 1, NULL);
	if (IWavpack == NULL)
	{
		IDOS->PutErrStr("ERROR: Failed to get the interface for wavpack.library.\n");
		abort();
	}
}

CONSTRUCTOR(IWavpack) = _INIT_5_IWavpack;

void _EXIT_5_IWavpack(void)
{
	if (IWavpack != NULL)
	{
		IExec->DropInterface((struct Interface *)IWavpack);
	}

	if (WavpackBase != NULL)
	{
		IExec->CloseLibrary(WavpackBase);
	}
}

DESTRUCTOR(IWavpack) = _EXIT_5_IWavpack;

