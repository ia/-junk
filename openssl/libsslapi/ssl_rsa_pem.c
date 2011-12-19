
#include "ssl_rsa_pem.h"

int ssl_rsa_pem_encrypt_buffer(char *plaintext, char *keyfile, int flags)
{
	return 0;
}

int ssl_rsa_pem_decrypt_buffer(char *ciphertext, char *keyfile, int flags)
{
	return 0;
}

int ssl_rsa_pem_encrypt_file(char *plainfile, char *keyfile, char *output)
{
	int size = 0, len = 0, ks = 0, clen = 0;
	unsigned char *cipher = NULL, *plain = NULL;
	FILE *fpkey = NULL, *fpin = NULL, *fpout = NULL;
	RSA *key = NULL;
	
	if ((fpkey = fopen(keyfile, "r")) == NULL) {
		fprintf(stderr, "Error: Public Key file doesn't exists.\n");
		return -1;
	}
	
	if ((key = PEM_read_RSAPublicKey(fpkey, NULL, NULL, NULL)) == NULL) {
		fprintf(stderr, "Error: problems while reading Public Key.\n");
		return -1;
	}
	fclose(fpkey);
	
	if (!(fpin = fopen(plainfile, "r"))) {
		fprintf(stderr, "Error: Cannot locate input file.\n");
		return -1;
	}
	
	fpout = fopen(output, "w");
	ks = RSA_size(key);
	plain = (unsigned char *) malloc(ks * sizeof(unsigned char));
	cipher = (unsigned char*) malloc(ks * sizeof(unsigned char));
	
	while (!feof(fpin)) {
		memset(plain, '\0', ks + 1);
		memset(cipher, '\0', ks + 1);
		len = fread(plain, 1, ks - 11, fpin);
		//size = rsa_encrypt(key, plain, len, &cipher);
		clen = 0;
		srand(time(NULL));
		if ((clen = RSA_public_encrypt(len, plain, cipher, key, RSA_PKCS1_PADDING)) == -1) {
			fprintf(stderr, "%s\n", ERR_error_string(ERR_get_error(), NULL));
			return -1;
		}
		fwrite(cipher, 1, clen, fpout);
	}
	
	fclose(fpout);
	fclose(fpin);
	free(cipher);
	free(plain);
	RSA_free(key);
	printf("%s\n", __func__);
	
	return 0;
}

int ssl_rsa_pem_decrypt_file(char *cipherfile, char *keyfile, char *output)
{
	printf("%s\n", __func__);
	return 0;
}

