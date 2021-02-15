/*  Caesar-Crack  */

/*  The main cracking program
 *  All resources used will be linked in the readme
 */

/*
Highest freqnecy character EIAS
1. Run the string through a function that returns an array of len 0-25
   where each entry is a letter of the alphabet.
   => for all chars in string, ++alphabet[char - 'a']
2. Take the highest frequency characters
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Caesar-Cipher.h"

// Frequency table of all the letters in the alphabet.  Data comes from google books
const float FREQ_TABLE[26] = {8.04, 1.48, 3.34, 3.82, 12.49, 2.40, 1.87, 5.05, 7.57, 0.16, 0.54, 4.07, 2.51,
                          7.23, 7.64, 2.14, 0.12, 6.28, 6.51, 9.28, 2.73, 1.05, 1.68, 0.23, 1.66, 0.09};


int
findMin(float* array, int len){
        int minIndex = 0;
        for (int i = 0; i < len; ++i){
                if (array[i] < array[minIndex]){
                        minIndex = i;
                }
        }
        return minIndex;
}

static float*
characterFrequency(char* string){

        float* charFreq = (float*)calloc(1, sizeof(float) * 26);
        int len = strlen(string);

        // First get the amount of a given character in the
        // string
        for (int i = 0; i < strlen(string); ++i){
                if (isalpha(string[i])){
                        ++charFreq[tolower(string[i]) - 'a'];
                } else {
                        continue;
                }
        }

        // then calculate the frequenct percentage of that letter
        // relative to the length of the string
        for (int i = 0; i < 26; ++i){
                charFreq[i] = (charFreq[i] / len) * 100;
        }

        return charFreq;
}

static float
chiSqr(float* os){
        float totalSum;

        for (int i = 0; i < 26; ++i){
                totalSum = totalSum + (pow(os[i] - FREQ_TABLE[i], 2.0) / FREQ_TABLE[i]);
        }

        return totalSum;
}

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

        for (int i = 0; i < 26; ++i){
                shiftTable[i] = chiSqr(characterFrequency(decrypt(string, i)));
        }

        return findMin(shiftTable, 26);
}

static void
printArray(float* array, int len){
        for (int i = 0; i < len; ++i){
                printf("%f ", array[i]);
        }
        putchar('\n');
}

int main(int argc, char** argv){

        char* fileBuffer = loadFile("test_letter.txt");
        char* enc = encrypt(fileBuffer, 7);
        printf("The shift used was : %i\n", crack(enc));
        printf("%s\n", decrypt(enc, crack(enc)));








}
