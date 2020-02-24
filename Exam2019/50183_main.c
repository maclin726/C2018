#include <stdio.h>
#include <stdlib.h>
#include "50183_lights.h"
#define MAXN 4
int best_cnt;
int best_sol[MAXN*MAXN];
void light(Lights *l, int n, int N, int sol[MAXN*MAXN], int sol_cnt){
    if( sol_cnt < best_cnt && numOfLights(l, N) == 0 ){
        for( int i = 0; i < sol_cnt; i++ )
            best_sol[i] = sol[i];
        best_cnt = sol_cnt;
        return;
    }
    else if( sol_cnt >= best_cnt || n == N * N )
        return;
    flip(l, n, N);
    sol[sol_cnt] = n;
    light(l, n+1, N, sol, sol_cnt+1);
    flip(l, n, N);
    light(l, n+1, N, sol, sol_cnt);
    return;
}

int main(){
    Lights l;
    init(&l);
    int N, n, sol[MAXN*MAXN] = {0};
    scanf("%d", &N);
    while( scanf("%d", &n) != EOF ){
        flip(&l, n, N);
    }
    best_cnt = N*N+1;
    light(&l, 0, N, sol, 0);
    for( int i = 0; i < best_cnt; i++ )
        printf("%d%c", best_sol[i], (i != best_cnt-1)? ' ': '\n' );
    return 0;
}