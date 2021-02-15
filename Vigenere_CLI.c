/* Vigenere Cipher CLI Tool
 * zhaba.dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   as3 as

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
c_encode(char* message, int key){
        int msglen = strlen(message);

        for (int i = 0; i < msglen; ++i){
                if (isalpha(message[i])){
                        message[i] = caesarEncode(message[i], key);
                }
        }

        return message;
}

char*
c_decode(char* message, int key){
        int msglen = strlen(message);

        for (int i = 0; i < msglen; ++i){
                if (isalpha(message[i])){
                        message[i] = caesarDecode(message[i], key);
                }
        }

        return message;
}


char*
format(char* fileName)
{
        FILE *fp;
        fp = fopen(fileName, "r");

        if(fp == NULL){
                printf("Error: Could not open file\n");
                return 0;
        }

        fseek(fp, 0, SEEK_END);
        long int buffSize = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char* buffer = calloc(buffSize + 1, sizeof(char));

        if (buffer == NULL){
                printf("Error: Could not allocate buffer memory\n");
                return 0;
        }

        fread(buffer, sizeof(char), buffSize, fp);



        char* formatBuffer = calloc(buffSize + 1, sizeof(char));
        int fBufCounter = 0;


        for (int i = 0; i < strlen(buffer); ++i){
            if (buffer[i] >= 'a' && buffer[i] <= 'z'){
                    formatBuffer[fBufCounter] = buffer[i];
                    ++fBufCounter;
                    }
            }


        free(buffer);
        fclose(fp);

        return formatBuffer;
}

int
processFile(char* fileName, char* option, char* key)
{

        FILE *newFile;
        newFile = fopen("Vigenere_Output.txt", "w");

        if (newFile == NULL){
                printf("Error: Could not open file\n");
                return -1;
        } else {
                printf("File created successfully\n");
        }
        char* formatBuffer = format(fileName);

        if (strcmp("encode", option) == 0){
                printf("Encoding\n");
                fputs(encode(formatBuffer, key), newFile);
        } else if (strcmp("decode", option) == 0) {
                printf("Decoding\n");
                fputs(decode(formatBuffer, key), newFile);
        }


        free(formatBuffer);
        fclose(newFile);

        return 0;
}

int
main(int argc, char** argv){
        // Input format: Vigenere [-e/-d] "Message" key

        // Encode
        if (strcmp("-e", argv[1]) == 0){
                printf("Encoded: %s\n", encode(argv[2], argv[3]));

        }

        // Decode
        else if (strcmp("-d", argv[1]) == 0){
                printf("Decoded: %s\n", decode(argv[2], argv[3]));
        }

        // Vigenere -f file.txt [encode/decode] key
        else if ( strcmp("-f", argv[1]) == 0){
                processFile(argv[2], argv[3], argv[4]);

        }

        // Caesar encode/decode:
        else if (strcmp("-ce", argv[1]) == 0){
                printf("%s\n", c_encode(argv[2], atoi(argv[3])));
        }
        else if (strcmp("-cd", argv[1]) == 0){
                printf("%s\n", c_decode(argv[2], atoi(argv[3])));
        }

        return 0;
}
