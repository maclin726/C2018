#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define MAXLEN 1000
static int snake[MAXLEN*MAXLEN];
static int result[MAXLEN*MAXLEN];
int in_map( int N, int i, int r, int c ){
    int center = (N-1) / 2;
    return ( abs(r-center) <= (i-1)/2 && abs(c-center) <= (i-1)/2 );
}
void SpiralSnake(int N, int *snake, int *result){
    int center = (N - 1) / 2;
    int r = (N - 1) / 2, c = (N - 1) / 2;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    result[ r * N + c ] = snake[0];
    for( int i = 3; i <= N; i += 2 ){
        int dir = 0;
        c--;
        for( int j = (i-2)*(i-2); j < (i*i); j++ ){
            result[ r * N + c ] = snake[j];
            int newr = r + dr[dir];
            int newc = c + dc[dir];
            if( !in_map(N, i, newr, newc) )
                dir++;
            if( j != i*i-1){
                r += dr[dir];
                c += dc[dir];
            }
        }
    }
}
int main(){
    int N;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N*N; i++)
              assert(scanf("%d", &snake[i])==1);
        SpiralSnake(N, snake, result);
        for(int i=0; i<N*N; i++)
             printf("%d%c", result[i], " \n"[i==N*N-1]);
    }
    return 0;
}