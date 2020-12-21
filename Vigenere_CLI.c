/* Vigenere Cipher CLI Tool
 * 
 * zhaba.dev
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
wrapMod(int a, int b)
{
        if (a >= 0){
                return (a % b);
        } else {
                return (a % b + b) % b;
        }
}

static inline char
caesarEncode(char message, int shift)
{

        return ((message + shift - 'a') % 26) + 'a';
}

static inline char
caesarDecode(char message, int shift)
{
        char decode = wrapMod((message - shift - 97), 26) + 97;
        return decode;
}

char*
encode(char* message, char* key)
{
        int msgLen = strlen(message);
        int keyLen = strlen(key);

        for (int i = 0; i < msgLen; ++i){
                message[i] = caesarEncode(message[i], key[i % keyLen] - 'a');
        }

        return message;
}

char*
decode(char* message, char* key)
{
        int msgLen = strlen(message);
        int keyLen = strlen(key);

        for (int i = 0; i < msgLen; ++i){
                message[i] = caesarDecode(message[i], (int)(key[i % keyLen]) - 97);
        }
        

        return message;
}


char*
format(char* fileBuffer)
{
        // Format incoming file buffer to remove all spaces and add newline char after every 80 characters
        return fileBuffer;
}

void
processFile(char* fileName, char* option, char* key)
{

        /* 1. Open fileName
         * 2. Read the contents into some buffer
         * 3. Format the buffer to remove all tabs, spaces, 
         *    uppercase characters, punctuation, etc
         * 4. Encode/Decode the buffer
         * 5. Write the buffer to a new file called <fileName>_[encode, decode].txt
         * 6. Return true if everything worked, false if something broke
         */
        
        FILE *fp;

        fseek(fp, 0, SEEK_END);
        int bufferSize = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        void* buffer = malloc(bufferSize);
        char* ch = buffer;

        
        
        

        
        

        
        fclose(fp);
}

int
main(int argc, char** argv){
        
        if (strcmp("encode", argv[1]) == 0){
                printf("Encoded: %s\n", encode(argv[2], argv[3]));

        }
        else if (strcmp("decode", argv[1]) == 0){
                printf("Decoded: %s\n", decode(argv[2], argv[3]));
        }
        // 0 Vigenere 1 -f 2 test.txt 3 decode 4 "nut"
        else if (strcmp("-f", argv[1] == 0)){
                processFile(argv[2], argv[3], argv[4])
        }

        return 0;
}

