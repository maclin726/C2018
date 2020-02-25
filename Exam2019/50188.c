#include <stdbool.h>
#include <stdio.h>
#include "mstTA.h"
#define MAXN 10

int edge[MAXN][MAXN];
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
bool hasPath(int city1, int city2, int N){
    bool visited[MAXN] = {0};
    visited[city1] = 1;
    int list[MAXN] = {city1}, lst_cnt = 1, nowidx = 0;
    while( nowidx < lst_cnt ){
        int p = list[nowidx++];
        for( int i = 0; i < N; i++ ){
            if( (!visited[i]) && (edge[p][i] != 0) ){
                list[lst_cnt++] = i;
                visited[i] = 1;
            }
        }
    }
    return visited[city2];
}
bool connected(int N){
    bool ans = true;
    for( int i = 1; i < N; i++ ){
        ans &= hasPath(0, i, N);
    }
    return ans;
}
int main(){
    int road[MAXN*MAXN/2][3];
    int N, M;
    scanf("%d%d", &N, &M);
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
            if( !hasPath(road[i][0], road[i][1], N) ){
                edge[road[i][0]][road[i][1]] = edge[road[i][1]][road[i][0]] = road[i][2];
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
            edge[road[i][0]][road[i][1]] = edge[road[i][1]][road[i][0]] = road[i][2];
        for( int i = 0; i < M; i++ ){
            edge[road[i][0]][road[i][1]] = edge[road[i][1]][road[i][0]] = 0;
            if( connected(N) ){
                if( road[i][0] > road[i][1] )
                    swap(&road[i][0], &road[i][1]);
                printf("%d %d %d\n", road[i][0], road[i][1], road[i][2]);
            }
            else
                edge[road[i][0]][road[i][1]] = edge[road[i][1]][road[i][0]] = road[i][2];
        }
    #endif
}