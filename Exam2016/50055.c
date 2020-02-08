#include<stdio.h>
 
int T[1000000];
int S[1000000];
 
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    unsigned long long int wait = 0;
    unsigned long long int counter[1024] = {0};
    for( int i = 0; i < M; i++ )
        scanf("%d%d", &T[i], &S[i]);
    for( int i = 0; i < M; i++ ){
        int fastCounter = 0;
        unsigned long long int fastTime = 18446744073709551615;
        for( int j = 0; j < N; j++ ){
            int ReadyTime = ( counter[j] < T[i] )? T[i]: counter[j];
            if( ReadyTime < fastTime  ){
                fastTime = ReadyTime;
                fastCounter = j;
            }
        }
        wait += fastTime - T[i];
        counter[fastCounter] = fastTime + S[i];
    }
    printf("%llu\n", wait);
}
