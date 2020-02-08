#include<stdio.h>
int draw( int color[20], int N, int adj[][2], int P, int C, int index ){
    if( index == N )
        return 1;
    int conflict = 0;
    for( int i = 1; i <= C; i++ ){
        int conflict = 0;
        for ( int j = 0; j < P; j++){
            if( (adj[j][0] == index && color[adj[j][1]] == i) || (adj[j][1] == index && color[adj[j][0]] == i) ){
                conflict = 1;
                break;
            }
        }
        if( !conflict ){
            color[index] = i;
            if(draw(color, N, adj, P, C, index+1) )
                return 1;
        }
    }
    return 0;
}
int main(){
    int adj[256][2] = {0};
    int color[20] = {0};
    int N, C, P;
    scanf("%d%d%d", &N, &C, &P);
    for( int i = 0; i < P; i++)
        scanf("%d%d", &adj[i][0], &adj[i][1]);
    if( draw( color, N, adj, P, C, 0 ) )
        for( int i = 0; i < N; i++)
            printf("%d\n", color[i]);
    else
        printf("no solution.\n");
}