/*
   These are some functions that are common between different
   cipher cracking methods.  I thought I'd combine them all into
   one file just to clean things up a bit.
 */



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

float*
characterFrequency(char* string){

        float* charFreq = (float*)calloc(1, sizeof(float) * 26);
        int len = strlen(string);

        strclean(string);

        // First get the amount of a given character in the
        // string
        for (int i = 0; i < strlen(string); ++i){
                if (isalpha(string[i])){
                        ++charFreq[tolower(string[i]) - 'a'];
                }
        }

        // then calculate the frequenct percentage of that letter
        // relative to the length of the string
        for (int i = 0; i < 26; ++i){
                charFreq[i] = (charFreq[i] / len) * 100;
        }

        return charFreq;
}

float
chiSqr(float* es, float* os){
        float totalSum;

        for (int i = 0; i < 26; ++i){
                totalSum = totalSum + (pow(os[i] - es[i], 2.0) / es[i]);
        }

        return totalSum;
}
