#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(){
    int record[65536] = {0};

    char filename[256] = {'\0'};
    scanf("%s", filename);
    FILE *fp = fopen( filename, "r" );
    assert( fp != NULL );
    
    int n;
    fread(&n, sizeof(int), 1, fp);
    
    short number;
    for( int i = 0; i < n; i++ ){
        fread(&number, sizeof(short), 1, fp);
        record[number+32768]++;
    }
    int maxIndex, maxTimes = 0;
    for( int i = 0; i < 65536; i++ )
        if( record[i] >= maxTimes ){
            maxIndex = i;
            maxTimes = record[i];
        }
    printf("%d\n%d", maxIndex-32768, maxTimes);

    return 0;
}