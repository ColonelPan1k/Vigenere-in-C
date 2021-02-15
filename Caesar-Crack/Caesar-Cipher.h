#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

void
strclean(char* string);

char*
encrypt(char* string, int key);

char*
decrypt(char* string, int key);

#endif
