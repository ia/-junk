
#include "ssl_rsa_pem.h"

int ssl_rsa_pem_encrypt_buffer(char *plaintext, char *key, int flags)
{
	return 0;
}

int ssl_rsa_pem_decrypt_buffer(char *ciphertext, char *key, int flags)
{
	return 0;
}

int ssl_rsa_pem_encrypt_file(char *plainfile, char *key, char *output)
{
	printf("%s\n", __func__);
	return 0;
}

int ssl_rsa_pem_decrypt_file(char *cipherfile, char *key, char *output)
{
	printf("%s\n", __func__);
	return 0;
}

