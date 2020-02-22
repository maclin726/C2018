#include<stdio.h>

int checkbit(int bit[]){
    return (bit[1] && bit[2] && bit[3] && bit[4] && bit[5] && bit[6]);
}

int main(){
    int map[1024][1024];
    int R, C;
    scanf("%d%d", &R, &C);
    int count = 0;
    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            scanf("%d", &map[i][j]);
        }
    }
    for( int i = 1; i < R-1; i++ ){
        for( int j = 0; j < C-3; j++ ){
            int bit[8] = {0};
            if( map[i][j] + map[i][j+2] == 7 && map[i][j+1] + map[i][j+3] == 7 ){
                bit[map[i][j]]++;
                bit[map[i][j+1]]++;
                bit[map[i][j+2]]++;
                bit[map[i][j+3]]++;
                for( int up = j; up < j+4; up++ ){
                    for( int down = j; down < j+4; down++ ){
                        bit[map[i-1][up]]++;
                        bit[map[i+1][down]]++;
                        if( checkbit(bit) && map[i-1][up] + map[i+1][down] == 7 )
                            count++;
                        bit[map[i-1][up]]--;
                        bit[map[i+1][down]]--;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
}