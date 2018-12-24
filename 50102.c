#include<stdio.h>
#include<assert.h>

int main(){
    char file1[32], file2[32], fileout[32];
    scanf("%s%s%s", file1, file2, fileout);

    FILE *FP1, *FP2, *FPout;
    FP1 = fopen(file1, "rb");
    FP2 = fopen(file2, "rb");
    FPout = fopen(fileout, "wb");

    fseek(FP1, 0, SEEK_END);
    fseek(FP2, 0, SEEK_END);
    long size1 = ftell(FP1), size2 = ftell(FP2);
    if( size1 < size2 ){
        long temp = size1;
        size1 = size2;
        size2 = temp;
        FILE *fptemp = FP1;
        FP1 = FP2;
        FP2 = fptemp;
    }
    int carry = 0;
    for( int i = 0; i < size1; i++ ){
        int a = 0, b = 0, sum = 0;
        fseek(FP1, size1 - i - 1, SEEK_SET);
        fread( &a, sizeof(unsigned char), 1, FP1 );
        if( size2 - i - 1 >= 0 ){
            fseek(FP2, size2 - i - 1, SEEK_SET);
            fread( &b, sizeof(unsigned char), 1, FP2 );
        }
        else
            b = 0;
        sum = a + b + carry;
        carry = (sum > 255) ? 1 : 0;
        sum = sum % 256;
        fseek( FPout, size1 - i- 1, SEEK_SET );
        fwrite( &sum, sizeof(unsigned char), 1, FPout );   
    }
    return 0;
}