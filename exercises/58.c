#include<stdio.h>
#define MAXSIZE 400
int map[MAXSIZE][MAXSIZE] = {0};                
int record[MAXSIZE][MAXSIZE] = {0};             //record whether the cell has been considered or not
int in_map( int r, int c, int N, int M ){
    return ( r < N && r >= 0 && c < M && c >= 0 );
}
int lake(int map[MAXSIZE][MAXSIZE], int record[MAXSIZE][MAXSIZE], int N, int M, int r, int c){
    if( record[r][c] )
        return 0;
    record[r][c] = 1;
    if( !map[r][c] )
        return 0;
    int dr[4] = {0, 0, 1 ,-1};
    int dc[4] = {1, -1, 0, 0};
    int sum = 1;                               //record the lake size 
    for(int i = 0; i < 4; i++){
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if( in_map(next_r, next_c, N ,M) && !record[next_r][next_c] && map[next_r][next_c] )
            sum += lake( map, record, N, M, next_r, next_c);
    }
    return sum;
}
int main(){
    int N,M;
    int lake_count = 0;
    int size[65536] = {0};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i ++)
        for(int j = 0 ; j < M; j++)
            scanf("%d", &map[i][j]);
    for(int i = 0; i < N; i++ )
        for(int j = 0; j < M; j++)
            if( map[i][j] && !record[i][j] ){
                size[lake_count] = lake(map, record, N, M, i, j);
                lake_count++;
            }
    for(int i = lake_count - 1 ; i >= 1; i-- )
        for(int j = 0; j < i; j++)
            if( size[j] < size[j+1] ){
                int temp = size[j];
                size[j] = size[j+1];
                size[j+1] = temp;
            }
    for(int i = 0; i < lake_count; i++)
        printf("%d\n", size[i]);
}