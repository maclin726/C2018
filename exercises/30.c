#include<stdio.h>

int count = 0;
int r,c;
int map[12][12];
int in_map(int start_r, int start_c){
    return ( start_r < r && start_r >= 0 && start_c >= 0 && start_c < c && map[start_r][start_c]);
}
void go_map( int start_r, int start_c ){
    if( start_r == 0 && start_c == (c-1) ){
        count++;
        return;
    }
    if( in_map(start_r -1, start_c) )
        go_map( start_r - 1, start_c );
    if( in_map(start_r, start_c + 1) )
        go_map( start_r, start_c + 1);
    return;
}
int main(){
    int i,j;
    scanf("%d%d",&r ,&c);
    for( i = 0; i < r; i ++)
        for(j = 0; j < c; j++)
            scanf("%d", &map[i][j]);
    int start_r = r-1, start_c = 0;
    go_map(start_r, start_c);
    printf("%d",count);
}