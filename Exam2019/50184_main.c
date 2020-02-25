#include <stdio.h>
#include <stdbool.h>
#include "lock.h"
#define SENSORNUM 3
#define MAXM 128

int best_cnt, best_power;
bool best[32];
void findMax(bool lights[], Locks *locks, int m, int M){
    int tmp = numUnlocked(locks, lights, m), power = 0;
    for( int i = 0; i < m; i++ )
        if( lights[i] )
            power += (1 << i);
    /*for( int i = 0; i < M; i++ )
        printf("%d", lights[i]);
    printf(": tmp = %d\n", tmp);*/
    if( tmp > best_cnt || (tmp == best_cnt && power < best_power) ){
        for( int i = 0; i < m ; i++ )
            best[i] = lights[i];
        best_power = power;
        best_cnt = tmp;
    }
    if( m == M )
        return;
    lights[m] = 1;
    findMax(lights, locks, m+1, M);
    lights[m] = 0;
    findMax(lights, locks, m+1, M);
    return;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    bool lights[MAXM] = {0};
    int lockSeq[n][SENSORNUM];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < SENSORNUM; j++) 
            scanf("%d", &lockSeq[i][j]);
    Locks *locks = init(lockSeq, n);
    findMax(lights, locks, 0, m);
    int power = 0;
    for( int i = 0; i < m; i++ )
        printf("%d", best[i]);
    printf("\n%d\n%d\n", best_cnt, best_power);
    return 0;
}