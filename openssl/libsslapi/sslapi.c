
#include "sslapi.h"

int main(int argc, const char *argv[])
{
	ssl_evp_aes_encrypt_buffer("abc\n", "a", 0);
	
	char *cipher = "";
	ssl_evp_aes_decrypt_buffer("password", cipher, 0);
	
	return 0;
}
