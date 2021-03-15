#ifndef _Included_DLL_acr_extr_tool_H
#define _Included_DLL_acr_extr_tool_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32 //windows platform
 
#ifdef ACR_USER_MODULE_EXPORTS
#define ACR_API __declspec(dllexport)
#else
#define ACR_API __declspec(dllimport)
#endif
 
#ifndef ACR_CALL_TYPE
#define ACR_CALL_TYPE  	__stdcall  
#endif
 
#else //linux platform
 
#ifndef ACR_API
#define ACR_API __attribute__ ((visibility ("default")))
#endif
 
#ifndef ACR_CALL_TYPE
#define ACR_CALL_TYPE
#endif
 
#endif

ACR_API int create_fingerprint(char *pcm_buffer, int pcm_buffer_len, char is_db_fingerprint, int filter_energy_min, int silence_energy_threshold, float silence_rate_threshold, char **fps_buffer);
ACR_API int create_fingerprint_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char is_db_fingerprint, int filter_energy_min, int silence_energy_threshold, float silence_rate_threshold, char **fps_buffer);
ACR_API int create_fingerprint_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char is_db_fingerprint, int filter_energy_min, int silence_energy_threshold, float silence_rate_threshold, char **fps_buffer);
ACR_API int create_humming_fingerprint(char *pcm_buffer, int pcm_buffer_len, char **fps_buffer);
ACR_API int create_humming_fingerprint_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char **fps_buffer);
ACR_API int create_humming_fingerprint_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char **fps_buffer);
ACR_API int decode_audio_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char **audio_buffer);
ACR_API int decode_audio_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char **audio_buffer);
ACR_API int get_duration_ms_by_file(char *file_path);
ACR_API void acr_free(char *buffer);
ACR_API void acr_set_debug();
ACR_API void acr_init();

#ifdef __cplusplus
}
#endif

#endif
