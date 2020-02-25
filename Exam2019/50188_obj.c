#include <stdbool.h>
#include <stdio.h>
#define MAXN 10
#include "mstTA.h"

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int main(){
    int road[MAXN*MAXN/2][3];
    int N, M;
    MSTTA mst;
    scanf("%d%d", &N, &M);
    initTA(&mst, N);
    for( int i = 0; i < M; i++ )
        scanf("%d%d%d", &road[i][0], &road[i][1], &road[i][2]);
    #ifdef ADD
        for( int i = 0; i < M; i++ ){
            for( int j = 0; j < M-i-1; j++ ){
                if( road[j][2] > road[j+1][2] ){
                    swap(&road[j][0], &road[j+1][0]);
                    swap(&road[j][1], &road[j+1][1]);
                    swap(&road[j][2], &road[j+1][2]);
                }
            }
        }
        for( int i = 0; i < M; i++ ){
            if( !hasPathTA(&mst, road[i][0], road[i][1]) ){
                addRoadTA(&mst, road[i][0], road[i][1], road[i][2]);
                if( road[i][0] > road[i][1] )
                    swap(&road[i][0], &road[i][1]);
                printf("%d %d %d\n", road[i][0], road[i][1], road[i][2]);
            }
        }
    #endif
    #ifdef REMOVE
        for( int i = 0; i < M; i++ ){
            for( int j = 0; j < M-i-1; j++ ){
                if( road[j][2] < road[j+1][2] ){
                    swap(&road[j][0], &road[j+1][0]);
                    swap(&road[j][1], &road[j+1][1]);
                    swap(&road[j][2], &road[j+1][2]);
                }
            }
        }
        for( int i = 0; i < M; i++ )
            addRoadTA(&mst, road[i][0], road[i][1], road[i][2]);
        for( int i = 0; i < M; i++ ){
            removeRoadTA(&mst, road[i][0], road[i][1]);
            if( connectedTA(&mst) ){
                if( road[i][0] > road[i][1] )
                    swap(&road[i][0], &road[i][1]);
                printf("%d %d %d\n", road[i][0], road[i][1], road[i][2]);
            }
            else
                addRoadTA(&mst, road[i][0], road[i][1], road[i][2]);
        }
    #endif
}