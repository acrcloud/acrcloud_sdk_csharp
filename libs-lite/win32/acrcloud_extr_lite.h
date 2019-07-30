#ifndef _Included_DLL_acrcloud_extr_lite_H
#define _Included_DLL_acrcloud_extr_lite_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ACRCLOUDEXTR_EXPORTS
#define ACRCLOUDEXTR_API __declspec(dllexport)
#else
#define ACRCLOUDEXTR_API __declspec(dllimport)
#endif

/**
 *
 *  create audio fingerprint by wav audio buffer(RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit) 
 *
 *  @param pcm_buffer: query audio buffer[ (little-endian) data, WAVE audio, Microsoft PCM, 16 bit]
 *  @param pcm_buffer_len: the length of pcm_buffer 
 *  @param sample_rate: sample rate of pcm_buffer
 *  @param nchannels:  channels
 *  @param is_db_fingerprint: 0[query fingerprint]; 1[db fingerprint];
 *  @param fps_buffer: fingerprint of pcm_buffer, you must free this buffer by acr_free.
 *
 *  @return the length of fps_buffer
 *
**/
ACRCLOUDEXTR_API int create_fingerprint(char *pcm_buffer, int pcm_buffer_len, int sample_rate, int nchannels, char is_db_fingerprint, char **fps_buffer);

/**
 *
 *  create audio fingerprint by wav audio buffer(RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit) 
 *
 *  @param pcm_buffer: query audio buffer[ (little-endian) data, WAVE audio, Microsoft PCM, 16 bit]
 *  @param pcm_buffer_len: the length of pcm_buffer 
 *  @param sample_rate: sample rate of pcm_buffer
 *  @param nchannels:  channels
 *  @param fps_buffer: fingerprint of pcm_buffer, you must free this buffer by acr_free.
 *
 *  @return the length of fps_buffer
 *
**/
ACRCLOUDEXTR_API int create_humming_fingerprint(char *pcm_buffer, int pcm_buffer_len, int sample_rate, int nchannels, char **fps_buffer);

/**
 * free buffer that other function return.
**/
ACRCLOUDEXTR_API void acr_free(char *buffer);

#ifdef __cplusplus
}
#endif

#endif

