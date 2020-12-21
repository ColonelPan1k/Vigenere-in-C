/* Vigenere Cipher CLI Tool
 * 
 * zhaba.dev
 *  
 */

// TODO: Add format function to remove spaces
//       Format all encode/decode input so full sentences can be used
//       Finish file I/O portion
//       See if formatting can extend to punctuation, uppercase, etc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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

        /* This is exactly the place where I would need find(char, char*) to search for
         * a char in a string but looping through a string of n length for each char in 
         * a file buffer doesn't seem like the best idea for efficiency.
         */
      
        for (int i = 0; i < strlen(buffer); ++i){
                if (buffer[i] != ' '){
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
        newFile = fopen("Newtest.txt", "w");
        if (newFile == NULL){
                printf("Error: Could not open file\n");
                return -1;
        }
        char* formatBuffer = format(fileName);

        if (strcmp("encode", option) == 0){
                fputs(encode(formatBuffer, key), newFile);
        } else if (strcmp("decode", option) == 0) {
                fputs(decode(formatBuffer, key), newFile);
        }
        
        free(formatBuffer);
        fclose(newFile);
        
        return 0;
}

int
main(int argc, char** argv){
        
        if (strcmp("encode", argv[1]) == 0){
                printf("Encoded: %s\n", encode(argv[2], argv[3]));

        }
        else if (strcmp("decode", argv[1]) == 0){
                printf("Decoded: %s\n", decode(argv[2], argv[3]));
        }
        //0 Vigenere 1 -f 2 test.txt 3 encode 4 key
        else if ( strcmp("-f", argv[1]) == 0){
                processFile(argv[2], argv[3], argv[4]);
                
        }
        return 0;
}

