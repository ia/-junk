#!/usr/bin/make -f

all: encrypt decrypt test

encrypt: ssl_aes_encrypt.c
	$(CC) -Wall -lssl ssl_aes_encrypt.c -o encrypt

decrypt: ssl_aes_decrypt.c
	$(CC) -Wall -lssl ssl_aes_decrypt.c -o decrypt

test:
	./encrypt a a
	./decrypt a a

clean:
	-rm -rf encrypt decrypt
	-rm -rf file.enc

.PHONY: all test clean
