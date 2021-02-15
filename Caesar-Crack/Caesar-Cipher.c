/* Caesar-Cipher */

/* Small implementation of the Caesar Cipher
 * for testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void
removeWhitespace(char* string){

}

static int
wrapMod(int a, int b){
        if (a >= 0){
                return (a % b);
        } else {
                return (a % b + b) % b;
        }
}

static inline char
c_encrypt(char letter, int shift){
        return ((letter + shift - 97) % 26) + 97;
}

static inline char
c_decrypt (char letter, int shift){
        char decode = wrapMod((letter - shift - 'a'), 26) + 'a';
        return decode;
}
