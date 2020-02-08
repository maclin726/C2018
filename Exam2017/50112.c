#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int compute( int friend[][2], int addr[], int N, int M ){
    int dis = 0;
    for( int i = 0; i < M; i++ ){
        if( friend[i][0] < N && friend[i][1] < N )
            dis += abs(addr[ friend[i][0] ] - addr[ friend[i][1] ]);
    }
    return dis;
}
 
void distance( int friend[][2], int M, int addr[], int record[], int N, int index, int *min){
    if( index == N ){
        (*min) = fmin( (*min), compute(friend, addr, N, M) );
        return;
    }
    for( int i = 0; i < N; i++ ){
        if( record[i] )
            continue;
        else{
            addr[index] = i;
            record[i] = 1;
            if( compute(friend, addr, index+1, M) > *min ){
                record[i] = 0;
                break;
            }
            distance( friend, M, addr, record, N, index+1, min);
            record[i] = 0;
        }
    }
    return;
}
 
int main(){
    int friend[100][2] = {0};
    int addr[20] = {0};
    int record[20] = {0};
    int N, M;
    scanf("%d%d", &N, &M);
    for( int i = 0; i < M; i++ )
        scanf("%d%d", &friend[i][0], &friend[i][1]);
    int min = 2147483647;
    distance(friend, M, addr, record, N, 0, &min);
    printf("%d\n", min);
}
