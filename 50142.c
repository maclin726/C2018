#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXINPUT 20
#define MAXLENGTH 32
 
int compare( char word[][4], int k ){
    int smallest = 0;
    for( int i = 1; i < k; i++ ){
        if( strcmp(word[i], word[smallest]) < 0 )
            smallest = i;
    }
    return smallest;
}
 
void merge(FILE *FP[], FILE *Fout, char word[][4], int k, int complete){
    if( complete == k )
        return;
    int min = compare( word, k );
    fwrite(word[min], 1, 3, Fout);
    int byte = fread(word[min], 1, 3, FP[min]);
    if( !byte ){
        complete++;
        word[min][0] = 'z'+1;
    }
    merge(FP, Fout, word, k, complete);
    return;
}
 
int main(){
    int k;
    scanf("%d", &k);
    char input[MAXLENGTH] = {'\0'};
    char output[MAXLENGTH];
    FILE *FP[MAXINPUT];
    FILE *Fout;
    for( int i = 0; i < k; i++ ){
        scanf("%s", input);
        FP[i] = fopen( input, "r" );
        assert( FP[i] != NULL );
    }
    scanf("%s", output);
    Fout = fopen( output, "a" );

    char word[MAXINPUT][4] = {'\0'};
    for( int i = 0; i < k; i++ )
        fread(word[i], 1, 3, FP[i]);
    merge(FP, Fout, word, k, 0);

    for(int i = 0; i < k; i++)
        fclose(FP[i]);
    fclose(Fout);
}