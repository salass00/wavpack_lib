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

asm("\t.section\t\".text\"\n"
	"\t.align\t2\n"
	"\t.globl\t__CallWavpack\n"
	"\t.type\t__CallWavpack, @function\n"
	"__CallWavpack:\n"
	"\tlis\t%r11,IWavpack@ha\n"
	"\tlwz\t%r0,IWavpack@l(%r11)\n"
	"\tlwzx\t%r11,%r12,%r0\n"
	"\tmtctr\t%r11\n"
	"\tbctr\n"
	"\t.size\t__CallWavpack, .-__CallWavpack");

#define WavpackCall(function, offset) \
asm("\t.section\t\".text\"\n" \
	"\t.align\t2\n" \
	"\t.globl\t" #function "\n" \
	"\t.type\t" #function ", @function\n" \
	#function ":\n" \
	"\tli\t%r12," #offset "\n" \
	"\tb\t__CallWavpack\n" \
	"\t.size\t" #function ", .-" #function);

WavpackCall(WavpackOpenFileInputEx64, 76)
WavpackCall(WavpackOpenFileInputEx, 80)
WavpackCall(WavpackOpenFileInput, 84)
WavpackCall(WavpackGetMode, 88)
WavpackCall(WavpackVerifySingleBlock, 92)
WavpackCall(WavpackGetQualifyMode, 96)
WavpackCall(WavpackGetErrorMessage, 100)
WavpackCall(WavpackGetVersion, 104)
WavpackCall(WavpackGetFileExtension, 108)
WavpackCall(WavpackGetFileFormat, 112)
WavpackCall(WavpackUnpackSamples, 116)
WavpackCall(WavpackGetNumSamples, 120)
WavpackCall(WavpackGetNumSamples64, 124)
WavpackCall(WavpackGetNumSamplesInFrame, 128)
WavpackCall(WavpackGetSampleIndex, 132)
WavpackCall(WavpackGetSampleIndex64, 136)
WavpackCall(WavpackGetNumErrors, 140)
WavpackCall(WavpackLossyBlocks, 144)
WavpackCall(WavpackSeekSample, 148)
WavpackCall(WavpackSeekSample64, 152)
WavpackCall(WavpackCloseFile, 156)
WavpackCall(WavpackGetSampleRate, 160)
WavpackCall(WavpackGetNativeSampleRate, 164)
WavpackCall(WavpackGetBitsPerSample, 168)
WavpackCall(WavpackGetBytesPerSample, 172)
WavpackCall(WavpackGetNumChannels, 176)
WavpackCall(WavpackGetChannelMask, 180)
WavpackCall(WavpackGetReducedChannels, 184)
WavpackCall(WavpackGetFloatNormExp, 188)
WavpackCall(WavpackGetMD5Sum, 192)
WavpackCall(WavpackGetChannelIdentities, 196)
WavpackCall(WavpackGetChannelLayout, 200)
WavpackCall(WavpackGetWrapperBytes, 204)
WavpackCall(WavpackGetWrapperData, 208)
WavpackCall(WavpackFreeWrapper, 212)
WavpackCall(WavpackSeekTrailingWrapper, 216)
WavpackCall(WavpackGetProgress, 220)
WavpackCall(WavpackGetFileSize, 224)
WavpackCall(WavpackGetFileSize64, 228)
WavpackCall(WavpackGetRatio, 232)
WavpackCall(WavpackGetAverageBitrate, 236)
WavpackCall(WavpackGetInstantBitrate, 240)
WavpackCall(WavpackGetNumTagItems, 244)
WavpackCall(WavpackGetTagItem, 248)
WavpackCall(WavpackGetTagItemIndexed, 252)
WavpackCall(WavpackGetNumBinaryTagItems, 256)
WavpackCall(WavpackGetBinaryTagItem, 260)
WavpackCall(WavpackGetBinaryTagItemIndexed, 264)
WavpackCall(WavpackAppendTagItem, 268)
WavpackCall(WavpackAppendBinaryTagItem, 272)
WavpackCall(WavpackDeleteTagItem, 276)
WavpackCall(WavpackWriteTag, 280)
WavpackCall(WavpackOpenFileOutput, 284)
WavpackCall(WavpackSetFileInformation, 288)
WavpackCall(WavpackSetConfiguration, 292)
WavpackCall(WavpackSetConfiguration64, 296)
WavpackCall(WavpackSetChannelLayout, 300)
WavpackCall(WavpackAddWrapper, 304)
WavpackCall(WavpackStoreMD5Sum, 308)
WavpackCall(WavpackPackInit, 312)
WavpackCall(WavpackPackSamples, 316)
WavpackCall(WavpackFlushSamples, 320)
WavpackCall(WavpackUpdateNumSamples, 324)
WavpackCall(WavpackGetWrapperLocation, 328)
WavpackCall(WavpackGetEncodedNoise, 332)
WavpackCall(WavpackFloatNormalize, 336)
WavpackCall(WavpackLittleEndianToNative, 340)
WavpackCall(WavpackNativeToLittleEndian, 344)
WavpackCall(WavpackBigEndianToNative, 348)
WavpackCall(WavpackNativeToBigEndian, 352)
WavpackCall(WavpackGetLibraryVersion, 356)
WavpackCall(WavpackGetLibraryVersionString, 360)

