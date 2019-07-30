#include <stdio.h>
#include <stdlib.h>
#include "acrcloud_recognizer.h"

int main(int argc, char **argv)
{
    FILE* fp_wav = fopen(argv[1], "rb");
    if (fp_wav == NULL)
        return 1;

    fseek(fp_wav,0L,SEEK_END);
    int size = ftell(fp_wav);
    fseek(fp_wav,44,SEEK_SET); // If have wav header.

    if (size <= 0) {
        return 1;
    }

    char *pcm_buffer = (char*)malloc(size);
    int nres = fread(pcm_buffer, 1, size, fp_wav);

    fclose(fp_wav);


    // Create audio fingerprint;
    char *audio_fp = NULL;
    int audio_fp_len = 0;
    audio_fp_len = create_fingerprint(pcm_buffer, nres, 8000, 1, 0, &audio_fp);
    if (audio_fp != NULL) {
        printf("fp len: %d\n", audio_fp_len);
        acr_free(audio_fp);
    }

    // Create humming fingerprint
    char *humming_fp = NULL;
    int humming_fp_len = 0;
    humming_fp_len = create_humming_fingerprint(pcm_buffer, nres, 8000, 1, &humming_fp);
    if (humming_fp != NULL) {
        printf("fp len: %d\n", humming_fp_len);
        acr_free(humming_fp);
    }
}
