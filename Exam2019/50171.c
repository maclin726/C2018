#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numPtrArray 4
#define MAXLEN 400000

void splitAndMap(char*** ptr, char* str){
    int ptrArrayCnt = 0;
    while( ptr[ptrArrayCnt] != NULL )
        ptrArrayCnt++;
    int charCount[10] = {0}, wordCount[10] = {0};
    char *delimeter = "*", *tmp;
    tmp = strtok(str, delimeter);
    while( tmp != NULL ){
        // printf("%s\n", tmp);
        int candidate = 0;
        for( int i = 0; i < ptrArrayCnt; i++ )
            if( charCount[i] < charCount[candidate] )
                candidate = i;
        ptr[candidate][wordCount[candidate]] = tmp;
        wordCount[candidate]++;
        charCount[candidate] += strlen(tmp);
        tmp = strtok(NULL, delimeter);
    }
    return;
}

int main(){
    char*** ptr = malloc((numPtrArray+1) * sizeof(char**));
    for(int i=0; i<numPtrArray; i++){
        ptr[i] = malloc(MAXLEN * sizeof(char**));
    }
    ptr[numPtrArray] = NULL;
 
    char str[MAXLEN];
    scanf("%s", str);
 
    splitAndMap(ptr, str);
 
    for(int i=0; i<numPtrArray; i++){
        for(int j=0; ptr[i][j]!=NULL; j++)
            printf("%s ", ptr[i][j]);
        printf("\n");
    }
 
    for(int i=0; i<numPtrArray; i++) free(ptr[i]);
    free(ptr);
    return 0;
}