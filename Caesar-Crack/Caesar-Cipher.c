/* Caesar-Cipher */

/* Small implementation of the Caesar Cipher
 * for testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void
strclean(char* src){
        char* dst = src;

        while(*src){
                if(islower(*src)) *dst++ = *src;
                else if (isupper(*src)) *dst++ = tolower(*src);
                src++;
        }
        *dst = '\0';
}

static int
wrapMod(int a, int b){
        if (a >= 0){
                return (a % b);
        } else {
                return (a % b + b) % b;
        }
}

char*
encrypt(char* message, int shift){
        char* newString = (char*)malloc(strlen(message) + 1);
        memset(newString, 0, strlen(message) + 1);

        for (int i = 0; i < strlen(message); ++i){
                newString[i] = ((message[i] + shift - 'a') % 26) + 97;
        }
        strclean(newString);
        return newString;
}


char*
decrypt(char* message, int shift){
        char* newString = (char*)malloc(strlen(message) + 1);
        memset(newString, 0, strlen(message) + 1);

        for (int i = 0; i < strlen(message); ++i){

                newString[i] = wrapMod((message[i] - shift - 97), 26) + 97;
        }
        strclean(newString);
        return newString;
}
