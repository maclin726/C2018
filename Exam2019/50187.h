#include <stdbool.h>
#include <string.h>
#define MAXN 10

typedef struct mstTA {
    int N, edge_cnt, sum;
    int edge[MAXN][MAXN];
} MSTTA;
 
void init(MSTTA *mst, int N){
    mst->N = N;
    mst->edge_cnt = mst->sum = 0;
    memset(mst->edge, 0, sizeof(int) * MAXN * MAXN);
    return;
}
void addRoad(MSTTA *mst, int city1, int city2, int len){
    mst->edge[city1][city2] = mst->edge[city2][city1] = len;
    mst->edge_cnt++;
    return;
}
int removeRoad(MSTTA *mst, int city1, int city2){
    int returnVal = mst->edge[city1][city2];
    mst->edge[city1][city2] = mst->edge[city2][city1] = 0;
    return returnVal;
}
bool hasPath(MSTTA *mst, int city1, int city2){
    bool visited[MAXN] = {0};
    visited[city1] = 1;
    int list[MAXN] = {city1}, lst_cnt = 1, nowidx = 0;
    while( nowidx < lst_cnt ){
        int p = list[nowidx++];
        for( int i = 0; i < mst->N; i++ ){
            if( (!visited[i]) && (mst->edge[p][i] != 0) ){
                list[lst_cnt++] = i;
                visited[i] = 1;
            }
        }
    }
    return visited[city2];
}
bool connected(MSTTA *mst){
    bool ans = true;
    for( int i = 1; i < mst->N; i++ ){
        ans &= hasPath(mst, 0, i);
    }
    return ans;
}