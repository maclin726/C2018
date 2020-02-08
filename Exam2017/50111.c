#include <stdio.h>
#include <stdlib.h>
 
int first = 0;
 
int compare( const void *data1, const void *data2 ){
    int *ptr1 = (int *)data1;
    int *ptr2 = (int *)data2;
    if( *ptr1 > *ptr2 )
        return 1;
    else if( *ptr1 < *ptr2 )
        return -1;
    else
        return 0;
}
 
void cycle( int road[][1000], int *visited, int *route, int count[], int N, int index ){
    if( index == N ){
        int circle = 0;
        for( int i = 0; i < count[route[N-1]]; i++ ){
            if( road[route[N-1]][i] == route[0] )
                circle = 1;
        }
        if( circle ){
            for( int i = 0; i < N; i++ )
                printf("%d ", route[i]);
            printf("%d\n", route[0]);
            first = 1;
        }
        return;
    }
 
    if( index == 0 ){
        for( int i = 0; i < N && !first; i++ ){
            route[0] = i;
            visited[i] = 1;
            cycle( road, visited, route, count, N, index+1 );
            visited[i] = 0;
        }
    }
    else{
        for( int i = 0; i < count[ route[index-1] ] && !first; i++ ){
            if( !visited[road[ route[index-1] ][i]] ){
                route[index] = road[ route[index-1] ][i];
                visited[road[ route[index-1] ][i]] = 1;
                cycle( road, visited, route, count, N, index+1 );
                visited[road[ route[index-1] ][i]] = 0;
            }
        }
    }
    return;
}
 
int road[1000][1000] = {0};
 
int main(){
    int N, E;
    scanf("%d%d", &N, &E);
 
    int visited[1000] = {0};
    int count[1000] = {0};
    int route[1000] = {500};
    route[N-1] = -1;
    for( int i = 0; i < E; i++ ){
        int x, y;
        scanf("%d%d", &x, &y);
        road[x][count[x]] = y;
        road[y][count[y]] = x;
        count[x]++;
        count[y]++;
    }
    for( int i = 0; i < N; i++ )
        qsort( road[i], count[i], sizeof(int), compare );
    cycle( road, visited, route, count, N, 0 );
    if( route[N-1] == (-1) )
        printf("NO SOLUTION\n");
    return 0;
}
