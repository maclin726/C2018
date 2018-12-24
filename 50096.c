#include<stdio.h>
int main(){
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    unsigned long long int ui[3] = {0};
    unsigned long long int p = 255;
    unsigned char code[32];
    for( int i = 0; i < M; i++ ){
        scanf("%llu", &ui[i]);
        for( int j = 7; j >= 0; j-- )
            code[8 * i + (7 - j)] = (ui[i] >> (8*j)) & p;
    }
    unsigned char uc;
    for( int i = 0; i < P; i++){
        scanf("%hhu", &uc);
        for( int j = 0; j < N; j++ ){
            int distance = 0;
            unsigned char s = 1;
            for( int k = 0; k < 8; k++ )
                if( ((uc >> k) & s) != ((code[j] >> k) & s) )
                    distance++;
            if( distance <= 1 ){
                printf("%hhu\n", code[j]);
                break;
            }
        }
    }
    return 0;
}