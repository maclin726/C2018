#include<stdio.h>
    int map[1000][1000] = {0};
int main(){
    int N, k, r, c;
    scanf("%d%d%d%d", &N, &k, &r, &c);
    int i,j;
    for ( i = 1; i < k; i++){
        int next_r = (r + 1) % N, next_c = (c - 1 + N) % N;
        if( map[next_r][next_c] != 0 )
                r = (r - 1 + N) % N;
        else{
            r = next_r;
            c = next_c;
        }
    }
    map[r][c] = 1;
    for ( i = 2; i <= N*N; i++){
        int next_r = (r - 1 + N) % N , next_c = (c + 1) % N;
        if( map[next_r][next_c] != 0 )
            r = (r + 1) % N;
        else{
            r = next_r;
            c = next_c;
        }
        map[r][c] = i;
    }
    for( i = 0 ; i < N ; i++){
        for( j = 0 ; j < N ; j++)
            if( j != N-1 )
            printf("%d ", map[i][j]);
            else
            printf("%d", map[i][j]);
        printf("\n");
    }
    return 0;
}