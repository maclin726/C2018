#include<stdlib.h>
#define MAXN 4
typedef struct _lights{
    int board[MAXN][MAXN];
    int total;
}Lights;
 
void init(Lights *l){
    for( int i = 0; i < MAXN; i++ )
        for( int j = 0; j < MAXN; j++ )
            l->board[i][j] = 0;
    l->total = 0;
    return;
}

int numOfLights(Lights *l,int N){
    return l->total;
}

void flip(Lights *l,int i,int N){
    int r = i / N, c = i % N;
    l->board[r][c] = (l->board[r][c] + 1)%2;
    l->total += (2*(l->board[r][c])-1);
    if( r < N-1 ){
        l->board[r+1][c] = (l->board[r+1][c] + 1)%2;
        l->total += (2*(l->board[r+1][c])-1);
    }
    if( r > 0 ){
        l->board[r-1][c] = (l->board[r-1][c] + 1)%2;
        l->total += (2*(l->board[r-1][c])-1);
    }
    if( c < N-1 ){
        l->board[r][c+1] = (l->board[r][c+1] + 1)%2;
        l->total += (2*(l->board[r][c+1])-1);
    }
    if( c > 0 ){
        l->board[r][c-1] = (l->board[r][c-1] + 1)%2;
        l->total += (2*(l->board[r][c-1])-1);
    }
    return;
}

void printLights(Lights *l,int N){
    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ )
            printf("%d%c", l->board[i][j], (j == N-1)? '\n': ' ');
    }
    return;
}