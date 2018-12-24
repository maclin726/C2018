#include<stdio.h>
    int record[1024][1024]={0};
void travel(int map[1024][1024], int N, int M, int A_r, int A_c,
            int B_r, int B_c, int directionA[], int directionB[]){
    int index_a = 0, index_b = 0, oka = 0, okb = 0;
    int dr[8] = {0,0,1,-1,1,-1,-1,1};
    int dc[8] = {1,-1,0,0,1,-1,1,-1};
    record[A_r][A_c]=1;
    record[B_r][B_c]=2;
    while( oka == 0 || okb == 0 ){
        int newDir = 0;
        if( oka == 0 ){
            directionA[index_a] = -1;
            int max = map[A_r][A_c];
            for( newDir = 0; newDir < 8; newDir++ ){
                if( A_r + dr[newDir] >= 0 && A_r + dr[newDir] < N && A_c + dc[newDir] >= 0 && A_c + dc[newDir] < M)
                    if( map[ A_r + dr[newDir] ][ A_c + dc[newDir] ] > max ){
                        directionA[index_a] = newDir;
                        max = map[A_r + dr[newDir]][ A_c + dc[newDir] ];
                    }
            }
            if( directionA[index_a] == (-1) )
                oka = 1;
            else{
                A_r += dr[ directionA[index_a] ];
                A_c += dc[ directionA[index_a] ];
                if (record[A_r][A_c] == 2){
                    oka = 1;
                    directionA[index_a + 1] = (-1);
                }
            }
        }
        if( okb == 0 ){
            directionB[index_b] = (-1);
            int mini = map[B_r][B_c];
            for( newDir = 0; newDir < 8; newDir++ ){
                if( B_r + dr[newDir] >= 0 && B_r + dr[newDir] < N && B_c + dc[newDir] >= 0 && B_c + dc[newDir] < M )
                    if( map[ B_r + dr[newDir] ][ B_c + dc[newDir] ] < mini ){
                        mini = map[ B_r + dr[newDir] ][ B_c + dc[newDir] ];
                        directionB[index_b] = newDir;
                    }
            }
            if( directionB[index_b] == (-1) )
                okb = 1;
            else{
                B_r += dr[ directionB[index_b] ];
                B_c += dc[ directionB[index_b] ];
                if (record[B_r][B_c] == 1){
                    okb = 1;
                    directionB[index_b + 1] = (-1);
                }
            }
        }
        if( A_r == B_r && A_c == B_c && oka == 0 && okb == 0 ){
            oka = 1;
            okb = 1;
            directionA[ index_a + 1 ] = (-1);
            directionB[ index_b + 1 ] = (-1);
        }
        if( oka == 0 ){
            record[A_r][A_c] = 1;
            index_a++;
        }
        if( okb == 0 ){
            record[B_r][B_c] = 2;
            index_b++;
        }
    }
}
int main() {
    int map[1024][1024];
    int N, M;
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);

    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);

    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");

    return 0;
}
