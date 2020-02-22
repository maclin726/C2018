#include <stdio.h>
#define MAXN 4

int N;
int board[MAXN][MAXN];
int check(){
    int sum = 0;
    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++ )
            sum += board[i][j];
    return (sum == 0);
}

void press(int N, int x){
    int r = x/N, c = x%N;
    board[r][c] = !board[r][c];
    if( c > 0 ) board[r][c-1] = !board[r][c-1];
    if( c < N-1 ) board[r][c+1] = !board[r][c+1];
    if( r > 0 ) board[r-1][c] = !board[r-1][c];
    if( r < N-1 ) board[r+1][c] = !board[r+1][c];
    return;
}

int best_cnt;
int best_sol[MAXN*MAXN];
void light(int N, int x, int sol[16], int sol_cnt){
    if( sol_cnt < best_cnt && check() ){
        for( int i = 0; i < sol_cnt; i++ )
            best_sol[i] = sol[i];
        best_cnt = sol_cnt;
        return;
    }
    else if( sol_cnt >= best_cnt || x == N * N )
        return;
    press(N, x);
    sol[sol_cnt] = x;
    light(N, x+1, sol, sol_cnt+1);
    press(N, x);
    light(N, x+1, sol, sol_cnt);
    return;
}

int main(){
    scanf("%d", &N);
    best_cnt = (MAXN * MAXN) + 1;
    int x, sol[MAXN*MAXN] = {0};
    while( scanf("%d", &x) != EOF )
        board[x/N][x%N] = 1;
    light(N, 0, sol, 0);
    for( int i = 0; i < best_cnt; i++ )
        printf("%d%c", best_sol[i], (i != best_cnt-1)? ' ': '\n' );
    return 0;
}