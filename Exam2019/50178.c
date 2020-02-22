#include <stdio.h>
#define MAXN 8
int N;
int graph[MAXN][MAXN];
int longest[8], long_cnt;

void walk(int now, int record[8], int path[8], int cnt){
    if( graph[now][0] && cnt > long_cnt ){
        for( int i = 0; i < cnt; i++ )
            longest[i] = path[i];
        long_cnt = cnt;
    }
    for( int i = 1; i < N; i++ )
        if( graph[now][i] && record[i] == 0 ){
            path[cnt] = i;
            record[i] = 1;
            walk(i, record, path, cnt+1);
            record[i] = 0;
        }
    return;
}

int main(){
    scanf("%d", &N);
    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++ )
             scanf("%d", &graph[i][j]);
    int path[8], record[8] = {0};
    walk(0, record, path, 0);
    for( int i = 0; i < long_cnt; i++ )
        printf("%d%c", longest[i], (i == long_cnt-1)? '\n': ' ');
    return 0;
}