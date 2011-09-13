
#include <stdio.h>

#include <openssl/evp.h>

int ssl_evp_aes_encrypt_buffer(char *password, char *plaintext, int flags);
int ssl_evp_aes_decrypt_buffer(char *password, char *ciphertext, int flags);

int ssl_evp_aes_encrypt_file();
int ssl_evp_aes_decrypt_file();

