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

#ifndef WAVPACK_INTERFACE_DEF_H
#define WAVPACK_INTERFACE_DEF_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef LIBRARIES_WAVPACK_H
#include <libraries/wavpack.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct WavpackIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct WavpackIFace *Self);
	uint32 APICALL (*Release)(struct WavpackIFace *Self);
	APTR Expunge_UNIMPLEMENTED;
	APTR Clone_UNIMPLEMENTED;
	WavpackContext *(*WavpackOpenFileInputEx64)(WavpackStreamReader64 *reader, void *wv_id, void *wvc_id, char *error, int flags, int norm_offset);
	WavpackContext *(*WavpackOpenFileInputEx)(WavpackStreamReader *reader, void *wv_id, void *wvc_id, char *error, int flags, int norm_offset);
	WavpackContext *(*WavpackOpenFileInput)(const char *infilename, char *error, int flags, int norm_offset);
	int (*WavpackGetMode)(WavpackContext *wpc);
	int (*WavpackVerifySingleBlock)(unsigned char *buffer, int verify_checksum);
	int (*WavpackGetQualifyMode)(WavpackContext *wpc);
	char *(*WavpackGetErrorMessage)(WavpackContext *wpc);
	int (*WavpackGetVersion)(WavpackContext *wpc);
	char *(*WavpackGetFileExtension)(WavpackContext *wpc);
	unsigned char (*WavpackGetFileFormat)(WavpackContext *wpc);
	uint32_t (*WavpackUnpackSamples)(WavpackContext *wpc, int32_t *buffer, uint32_t samples);
	uint32_t (*WavpackGetNumSamples)(WavpackContext *wpc);
	int64_t (*WavpackGetNumSamples64)(WavpackContext *wpc);
	uint32_t (*WavpackGetNumSamplesInFrame)(WavpackContext *wpc);
	uint32_t (*WavpackGetSampleIndex)(WavpackContext *wpc);
	int64_t (*WavpackGetSampleIndex64)(WavpackContext *wpc);
	int (*WavpackGetNumErrors)(WavpackContext *wpc);
	int (*WavpackLossyBlocks)(WavpackContext *wpc);
	int (*WavpackSeekSample)(WavpackContext *wpc, uint32_t sample);
	int (*WavpackSeekSample64)(WavpackContext *wpc, int64_t sample);
	WavpackContext *(*WavpackCloseFile)(WavpackContext *wpc);
	uint32_t (*WavpackGetSampleRate)(WavpackContext *wpc);
	uint32_t (*WavpackGetNativeSampleRate)(WavpackContext *wpc);
	int (*WavpackGetBitsPerSample)(WavpackContext *wpc);
	int (*WavpackGetBytesPerSample)(WavpackContext *wpc);
	int (*WavpackGetNumChannels)(WavpackContext *wpc);
	int (*WavpackGetChannelMask)(WavpackContext *wpc);
	int (*WavpackGetReducedChannels)(WavpackContext *wpc);
	int (*WavpackGetFloatNormExp)(WavpackContext *wpc);
	int (*WavpackGetMD5Sum)(WavpackContext *wpc, unsigned char data [16]);
	void (*WavpackGetChannelIdentities)(WavpackContext *wpc, unsigned char *identities);
	uint32_t (*WavpackGetChannelLayout)(WavpackContext *wpc, unsigned char *reorder);
	uint32_t (*WavpackGetWrapperBytes)(WavpackContext *wpc);
	unsigned char *(*WavpackGetWrapperData)(WavpackContext *wpc);
	void (*WavpackFreeWrapper)(WavpackContext *wpc);
	void (*WavpackSeekTrailingWrapper)(WavpackContext *wpc);
	double (*WavpackGetProgress)(WavpackContext *wpc);
	uint32_t (*WavpackGetFileSize)(WavpackContext *wpc);
	int64_t (*WavpackGetFileSize64)(WavpackContext *wpc);
	double (*WavpackGetRatio)(WavpackContext *wpc);
	double (*WavpackGetAverageBitrate)(WavpackContext *wpc, int count_wvc);
	double (*WavpackGetInstantBitrate)(WavpackContext *wpc);
	int (*WavpackGetNumTagItems)(WavpackContext *wpc);
	int (*WavpackGetTagItem)(WavpackContext *wpc, const char *item, char *value, int size);
	int (*WavpackGetTagItemIndexed)(WavpackContext *wpc, int index, char *item, int size);
	int (*WavpackGetNumBinaryTagItems)(WavpackContext *wpc);
	int (*WavpackGetBinaryTagItem)(WavpackContext *wpc, const char *item, char *value, int size);
	int (*WavpackGetBinaryTagItemIndexed)(WavpackContext *wpc, int index, char *item, int size);
	int (*WavpackAppendTagItem)(WavpackContext *wpc, const char *item, const char *value, int vsize);
	int (*WavpackAppendBinaryTagItem)(WavpackContext *wpc, const char *item, const char *value, int vsize);
	int (*WavpackDeleteTagItem)(WavpackContext *wpc, const char *item);
	int (*WavpackWriteTag)(WavpackContext *wpc);
	WavpackContext *(*WavpackOpenFileOutput)(WavpackBlockOutput blockout, void *wv_id, void *wvc_id);
	void (*WavpackSetFileInformation)(WavpackContext *wpc, char *file_extension, unsigned char file_format);
	int (*WavpackSetConfiguration)(WavpackContext *wpc, WavpackConfig *config, uint32_t total_samples);
	int (*WavpackSetConfiguration64)(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, const unsigned char *chan_ids);
	int (*WavpackSetChannelLayout)(WavpackContext *wpc, uint32_t layout_tag, const unsigned char *reorder);
	int (*WavpackAddWrapper)(WavpackContext *wpc, void *data, uint32_t bcount);
	int (*WavpackStoreMD5Sum)(WavpackContext *wpc, unsigned char data [16]);
	int (*WavpackPackInit)(WavpackContext *wpc);
	int (*WavpackPackSamples)(WavpackContext *wpc, int32_t *sample_buffer, uint32_t sample_count);
	int (*WavpackFlushSamples)(WavpackContext *wpc);
	void (*WavpackUpdateNumSamples)(WavpackContext *wpc, void *first_block);
	void *(*WavpackGetWrapperLocation)(void *first_block, uint32_t *size);
	double (*WavpackGetEncodedNoise)(WavpackContext *wpc, double *peak);
	void (*WavpackFloatNormalize)(int32_t *values, int32_t num_values, int delta_exp);
	void (*WavpackLittleEndianToNative)(void *data, char *format);
	void (*WavpackNativeToLittleEndian)(void *data, char *format);
	void (*WavpackBigEndianToNative)(void *data, char *format);
	void (*WavpackNativeToBigEndian)(void *data, char *format);
	uint32_t (*WavpackGetLibraryVersion)(void);
	const char *(*WavpackGetLibraryVersionString)(void);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* WAVPACK_INTERFACE_DEF_H */
