#!/usr/bin/make -f

all: compile library test

compile: ssl_bio_base64.c ssl_bio_aes.c ssl_evp_aes.c
	$(CC) -Wall -lcrypto -lssl -fPIC -c ssl_bio_base64.c -o ssl_bio_base64.o
	$(CC) -Wall -lcrypto -lssl -fPIC -c ssl_bio_aes.c -o ssl_bio_aes.o
	$(CC) -Wall -lcrypto -lssl -fPIC -c ssl_evp_aes.c -o ssl_evp_aes.o

library: compile
	$(CC) -Wall ssl_bio_base64.o ssl_bio_aes.o ssl_evp_aes.o -shared -o libsslapi.so

test: compile library
	$(CC) -Wall -L. -lsslapi sslapi.c -o sslapi
	LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH} ./sslapi

clean:
	-rm -rf *.o
	-rm -rf *.so
	-rm -rf sslapi

.PHONY: all test clean
