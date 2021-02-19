/*  Caesar-Crack  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Caesar-Cipher.h"
#include "Crack-Lib.h"

static char*
loadFile(char* filePath){
        FILE* fp;
        fp = fopen(filePath, "r");
        if (fp == NULL){
                printf("Error opening file\n");
                exit(0);
        }

        fseek(fp, 0L, SEEK_END);
        size_t fsize = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        char* fileBuffer = (char*)malloc(sizeof(char) * fsize);
        fread(fileBuffer, sizeof(char), fsize,  fp);

        fclose(fp);
        return fileBuffer;
}

int
crack(char* string){
        float shiftTable[26];
        strclean(string);

        for (int i = 0; i < 26; ++i){
                shiftTable[i] = chiSqr(characterFrequency(decrypt(string, i)));
        }

        int shiftMin = findMin(shiftTable, 26);

        return shiftMin;
}

int main(int argc, char** argv){

        char* fileBuffer = loadFile("Crack_me.txt");

}
