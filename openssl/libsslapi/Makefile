#!/usr/bin/make -f

all: compile library test ssl_compability

compile: ssl_bio_base64.c ssl_bio_aes.c ssl_evp_aes.c
	$(CC) -Wall -fPIC -c ssl_bio_base64.c -o ssl_bio_base64.o
	$(CC) -Wall -fPIC -c ssl_bio_aes.c -o ssl_bio_aes.o
	$(CC) -Wall -fPIC -c ssl_evp_aes.c -o ssl_evp_aes.o

library: compile
	$(CC) -Wall ssl_bio_base64.o ssl_bio_aes.o ssl_evp_aes.o -shared -o libsslapi.so -lcrypto

test: compile library
	$(CC) -Wall -Wl,--no-as-needed -L. -lsslapi sslapi.c -o sslapi
	LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH} ./sslapi

ssl_compability:
	openssl enc -d -aes-256-cbc -nosalt -in file.enc -out file.txt && cat file.txt

clean:
	-rm -rf *.o
	-rm -rf *.so
	-rm -rf sslapi
	-rm -rf file.txt file.enc file.enc.txt

.PHONY: all test clean
