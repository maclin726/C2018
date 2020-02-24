#include <stdio.h>
#include <string.h>

int main(){
    char infile[64], outfilePrefix[64];
    int outCnt;
    scanf("%s%d%s", infile, &outCnt, outfilePrefix);
    
    char outname[10][64];
    FILE *input = fopen(infile, "rw");
    FILE *output[10];
    for( int i = 0; i < outCnt; i++ ){
        sprintf(outname[i], "%s%d", outfilePrefix, i+1);
        output[i] = fopen(outname[i], "w+");
    }
    
    int count[10] = {0}, nowToplace = 0;
    unsigned char c;
    while( fscanf(input, "%c", &c) != EOF ){
        if( c != 255 ){
            fprintf(output[nowToplace], "%c", c);
            count[nowToplace]++;
        }
        else{
            nowToplace = 0;
            for( int i = 1; i < outCnt; i++ )
                if( count[i] < count[nowToplace] )
                    nowToplace = i;
        }
    }
    return 0;
}