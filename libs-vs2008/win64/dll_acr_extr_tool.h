#ifndef _Included_DLL_acr_extr_tool_H
#define _Included_DLL_acr_extr_tool_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ACRCLOUDEXTR_EXPORTS
#define ACRCLOUDEXTR_API __declspec(dllexport)
#else
#define ACRCLOUDEXTR_API __declspec(dllimport)
#endif

ACRCLOUDEXTR_API int __stdcall create_fingerprint(char *pcm_buffer, int pcm_buffer_len, char is_db_fingerprint, char **fps_buffer);
ACRCLOUDEXTR_API int __stdcall create_humming_fingerprint(char *pcm_buffer, int pcm_buffer_len, char **fps_buffer);
ACRCLOUDEXTR_API int __stdcall create_fingerprint_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char is_db_fingerprint, char **fps_buffer);
ACRCLOUDEXTR_API int __stdcall create_humming_fingerprint_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char **fps_buffer);
ACRCLOUDEXTR_API int __stdcall create_fingerprint_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char is_db_fingerprint, char **fps_buffer);
ACRCLOUDEXTR_API int __stdcall create_humming_fingerprint_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char **fps_buffer);
ACRCLOUDEXTR_API int __stdcall decode_audio_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char **audio_buffer);
ACRCLOUDEXTR_API int __stdcall decode_audio_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char **audio_buffer);
ACRCLOUDEXTR_API int __stdcall get_duration_ms_by_file(char *file_path);
ACRCLOUDEXTR_API void __stdcall acr_free(char *buffer);
ACRCLOUDEXTR_API void __stdcall acr_set_debug(char is_debug);
ACRCLOUDEXTR_API void __stdcall acr_init();

#ifdef __cplusplus
}
#endif

#endif