#include<stdio.h>
#define MAXSIZE 1048576
void transmission(long long int belt[], int N, int T){
    int count = T / 64;
    if( count > 0 ){
        long long int temp = belt[0];
        int visited = 0, index = 0;
        while( visited != N ){
            if( (index + count) % N != 0 ){
                belt[index] = belt[(index + count) % N];
                index = (index + count) % N;
            }
            else{
                belt[index] = temp;
                index = 0;
            }
            visited++;
        }
        T = T % 64;
    }
    if( T != 0 ){
        long long int p = 1;
        long long int save = ( (belt[0] >> (64 - T)) & ( (p<<T) - 1) );
        for( int i = 0; i < N-1; i++ ){
            belt[i] = belt[i] << T;
            long long int shift = ( (belt[i+1] >> (64-T)) & ((p<<T)-1) );
            belt[i] += shift;
        }
        belt[N-1] = belt[N-1] << T;
        belt[N-1] += save;
    }
    return;
}
long long int belt[MAXSIZE];
int main(){
    int N,T;
    scanf("%d%d",&N,&T);
    for(int i = 0; i < N; i++)
        scanf("%lld",&belt[i]);
    transmission(belt,N,T);
    for(int i=0;i<N;i++)
        printf("%lld%s",belt[i],i==N-1?"":" ");
    return 0;
}