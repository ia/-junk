
#include "sslapi.h"

int main(int argc, const char *argv[])
{
	/*
	ssl_evp_aes_encrypt_buffer("abc\n", "a", 0);
	
	ssl_bio_base64_encrypt_buffer("a\n");
	ssl_bio_base64_decrypt_buffer("YQo=\n");
	
	char *cipher = "";
	ssl_evp_aes_decrypt_buffer("password", cipher, 0);
	*/
	ssl_rsa_pem_encrypt_file("file.txt", "../rsa/pub.pem", "file.bin");
	ssl_rsa_pem_decrypt_file("file.bin", "../rsa/sec.pem", "file_.txt");
	
	return 0;
}

