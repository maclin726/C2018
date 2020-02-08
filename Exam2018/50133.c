#include<stdio.h>
#include<ctype.h>
#include<string.h>
void merge( char *wordA , char *wordB ){
    int indexA = 0, indexB = 0;
    while( wordA[indexA] != '\0' && wordB[indexB] != '\0' ){
        int compare = strncmp( &wordA[indexA], &wordB[indexB], 3 );
        if( compare >= 0 ){
            char temp[100001] = {'\0'};
            strcpy( temp, wordA + indexA );
            strcpy( wordA + indexA + 3, temp );
            strncpy( wordA + indexA, wordB + indexB, 3 );
            indexB += 3;
        }
        indexA += 3;
    }
    strcat( wordA, wordB + indexB );
    printf("%s\n", wordA);
    return;
}
 
int main(){
    char wordA[100001], wordB[100001];
    scanf("%s", wordA);
    while( scanf("%s", wordB) != EOF ){
        merge( wordA, wordB );
        wordB[0] = '\0';
    }
    return 0;
}