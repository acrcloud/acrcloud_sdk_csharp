#ifndef _Included_DLL_acr_extr_tool_H
#define _Included_DLL_acr_extr_tool_H

#ifdef __cplusplus
extern "C" {
#endif

int create_fingerprint(char *pcm_buffer, int pcm_buffer_len, char is_db_fingerprint, char **fps_buffer);
int create_fingerprint_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char is_db_fingerprint, char **fps_buffer);
int create_fingerprint_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char is_db_fingerprint, char **fps_buffer);
int decode_audio_by_file(char *file_path, int start_time_seconds, int audio_len_seconds, char **audio_buffer);
int decode_audio_by_filebuffer(char *file_buffer, int file_buffer_len, int start_time_seconds, int audio_len_seconds, char **audio_buffer);
void acr_free(char *buffer);
void acr_set_debug();
void acr_init();

#ifdef __cplusplus
}
#endif

#endif
