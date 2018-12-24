#include<stdio.h>
int outside( int r, int c, int n ){
    if( r >= n || r < 0 || c >= n || c <0 )
        return 1;
    else
        return 0;
}

int main(){
    int dr[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    int dc[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    int n, m;
    int map[100][100] = {0};    //the board
    int knight[10001][2];       //the coordinates of knights
    int step[10001] = {0};      //how many steps a knight has gone
    int stop[10001] = {0};      //whether the knight stop(1) or not(0)
    int terminate = 0;          //numbers of knights that have stopped their steps
    scanf("%d%d",&n, &m);
    int k, r, c;
    for( k = 1; k <= m; k++ ){
        int r, c;
        scanf("%d%d", &r, &c);
        knight[k][0] = r;
        knight[k][1] = c;
        map[r][c] = 10000 * k;
    }
    k = 0;
    while( terminate != m ){
        ( k == m )? k = 1 : k++; 
        if( stop[k] )
            continue;
        else{
            int Dir = 0, d, min_count = 9;
            for( d = 1; d < 9; d++ ){
                int next_r = knight[k][0] + dr[d];
                int next_c = knight[k][1] + dc[d];
                if( outside( next_r, next_c, n) == 1 || map[next_r][next_c] != 0 )
                    continue;
                else{
                    int next_d;
                    int count = 0;
                    for( next_d = 1; next_d < 9; next_d++ ){
                        int next2_r = next_r + dr[next_d];
                        int next2_c = next_c + dc[next_d];
                        if( outside(next2_r, next2_c, n) == 1 || map[next2_r][next2_c] != 0 )
                            continue;
                        else
                            count++;
                    }
                    if( count < min_count ){
                        min_count = count;
                        Dir = d;
                    }
                }
            }
            if( Dir == 0 ){
                stop[k] = 1;
                terminate++;
            }
            else{
                knight[k][0] += dr[Dir];
                knight[k][1] += dc[Dir];
                step[k]++;
                map[ knight[k][0] ][ knight[k][1] ] = k * 10000 + step[k];
#ifdef DEBUG
                for( r = 0; r < n; r++){
                    for( c = 0; c < n; c++){
                        if( c == n-1 )
                            printf("%d",map[r][c]);
                        else
                            printf("%d ",map[r][c]);
                    }
                    printf("\n");
                }
#endif
            }
        }
    } 
    for( r = 0; r < n; r++){
        for( c = 0; c < n; c++){
            if( c == n-1 )
                printf("%d",map[r][c]);
            else
                printf("%d ",map[r][c]);
        }
        printf("\n");
    }
return 0;
}