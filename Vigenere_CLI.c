/*
 * Format: 0- vignere 1-[encode, decode] 2-[message] 3-[key]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* formatInput(char* message);
//inline char* test(char* message, int shift);
//inline char* caesarDecode (char* message, int shift);
//char* encode(char* message, char* key);
//char* decode(char* message, char* key);



static inline void
caesarEncode(char* message, int shift)
{
        int len = strlen(message);
        
        for (int i = 0; i < len; ++i){
                message[i] = (((message[i] + shift - 97) % 26) + 97);                
        }

        printf("%s\n", message);
}

int
main(int argc, char** argv){
        
        if (strcmp("encode", argv[1]) == 0){
                caesarEncode(argv[2], atoi(argv[3]));

        }
        else if (argv[0] == "decode"){
                //caesarDecode(argv[1], (int)argv[2]);
        }

        return 0;
}

