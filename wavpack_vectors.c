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

#include "wavpack_vectors.h"

STATIC uint32 VARARGS68K _WavPack_UNIMPLEMENTED(UNUSED struct WavPackIFace *iface UNUSED)
{
	return 0;
}

STATIC CONST APTR main_v1_vectors[] =
{
	_WavPack_Obtain,
	_WavPack_Release,
	_WavPack_UNIMPLEMENTED, /* Expunge */
	_WavPack_UNIMPLEMENTED, /* Clone */
	WavpackOpenFileInputEx64,
	WavpackOpenFileInputEx,
	WavpackOpenFileInput,
	WavpackGetMode,
	WavpackVerifySingleBlock,
	WavpackGetQualifyMode,
	WavpackGetErrorMessage,
	WavpackGetVersion,
	WavpackGetFileExtension,
	WavpackGetFileFormat,
	WavpackUnpackSamples,
	WavpackGetNumSamples,
	WavpackGetNumSamples64,
	WavpackGetNumSamplesInFrame,
	WavpackGetSampleIndex,
	WavpackGetSampleIndex64,
	WavpackGetNumErrors,
	WavpackLossyBlocks,
	WavpackSeekSample,
	WavpackSeekSample64,
	WavpackCloseFile,
	WavpackGetSampleRate,
	WavpackGetNativeSampleRate,
	WavpackGetBitsPerSample,
	WavpackGetBytesPerSample,
	WavpackGetNumChannels,
	WavpackGetChannelMask,
	WavpackGetReducedChannels,
	WavpackGetFloatNormExp,
	WavpackGetMD5Sum,
	WavpackGetChannelIdentities,
	WavpackGetChannelLayout,
	WavpackGetWrapperBytes,
	WavpackGetWrapperData,
	WavpackFreeWrapper,
	WavpackSeekTrailingWrapper,
	WavpackGetProgress,
	WavpackGetFileSize,
	WavpackGetFileSize64,
	WavpackGetRatio,
	WavpackGetAverageBitrate,
	WavpackGetInstantBitrate,
	WavpackGetNumTagItems,
	WavpackGetTagItem,
	WavpackGetTagItemIndexed,
	WavpackGetNumBinaryTagItems,
	WavpackGetBinaryTagItem,
	WavpackGetBinaryTagItemIndexed,
	WavpackAppendTagItem,
	WavpackAppendBinaryTagItem,
	WavpackDeleteTagItem,
	WavpackWriteTag,
	WavpackOpenFileOutput,
	WavpackSetFileInformation,
	WavpackSetConfiguration,
	WavpackSetConfiguration64,
	WavpackSetChannelLayout,
	WavpackAddWrapper,
	WavpackStoreMD5Sum,
	WavpackPackInit,
	WavpackPackSamples,
	WavpackFlushSamples,
	WavpackUpdateNumSamples,
	WavpackGetWrapperLocation,
	WavpackGetEncodedNoise,
	WavpackFloatNormalize,
	WavpackLittleEndianToNative,
	WavpackNativeToLittleEndian,
	WavpackBigEndianToNative,
	WavpackNativeToBigEndian,
	WavpackGetLibraryVersion,
	WavpackGetLibraryVersionString,
	(APTR)-1
};
