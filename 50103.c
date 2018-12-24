#include<stdio.h>

void mirror(FILE *FPin, FILE *FPout, int N, int size){
    fseek(FPin, 0, SEEK_SET);
    for( int i = 0; i < size; i++ ){            //if we want to read a file in order, we don't need fseek
        char a, s = 0;
        fseek(FPin, ( size - i - 1 - N + size ) % size, SEEK_SET);
        fread(&a, 1, 1, FPin);
        for( int j = 0; j < 8; j++ )
            if( a & (1<<j) )
                s = (s | 1 << (7-j));
        fwrite(&s, 1, 1, FPout);
    }
    return;
}

int main(){
    char file1[32], fileout[32];
    scanf("%s%s", file1, fileout);
    int N;
    scanf("%d", &N);

    FILE *FPin, *FPout;
    FPin = fopen(file1, "rb");
    FPout = fopen(fileout, "wb");

    fseek(FPin, 0, SEEK_END);
    int size = ftell(FPin);
    mirror(FPin, FPout, N, size);
    fclose(FPin);
    fclose(FPout);
    return 0;
}