#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    char infile[64], outfilePrefix[64];
    int outCnt;
    scanf("%s", infile);
    scanf("%d", &outCnt);
    scanf("%s", outfilePrefix);
    FILE *input = fopen(infile, "rw");
    char outname[10][64];
    FILE *output[10];
    for( int i = 0; i < outCnt; i++ ){
        sprintf(outname[i], "%s%d", outfilePrefix, i+1);
        output[i] = fopen(outname[i], "w+");
    }
    int count[10] = {0};
    unsigned char buffer[8096];
    while( fscanf(,"%hhc", ) )
    unsigned char deli = (unsigned char)255, *str;
    str = strtok(buffer, &deli);
    while( str != NULL ){
        int toBePlaced = 0;
        for( int i = 1; i < outCnt; i++ )
            if( count[toBePlaced] > count[i] )
                toBePlaced = i;
        fprintf(output[toBePlaced], "%s", str);
        count[toBePlaced] += strlen(str);
        str = strtok(NULL, &deli);
    }
    return 0;
}