#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXM 10000
#define MAXQ 200
typedef struct _road{
    int from;
    int to;
} Road;
typedef struct _map{
    int cnt;
    int key[MAXM*2];
    Road *ptr[MAXM*2];
} Map;
typedef struct _graph {
    int cnt;
    Road road[MAXM*2];
} Graph;

void init(Graph *graph, int M){ // initialize graph
    graph->cnt = 0;
    return;
}

void addRoad(Graph *graph, int city1, int city2){ // add roads into graph
    graph->road[graph->cnt].from = city1;
    graph->road[graph->cnt].to = city2;
    graph->cnt++;
    graph->road[graph->cnt].from = city2;
    graph->road[graph->cnt].to = city1;
    graph->cnt++;
    return;
}

int comp(const void *a, const void *b){
    Road *ptr1 = (Road *)a, *ptr2 = (Road *)b;
    if( ptr1->from > ptr2->from )
        return 1;
    else if( ptr1->from < ptr2->from )
        return -1;
    else if( ptr1->to > ptr2->to )
        return 1;
    else if( ptr1->to < ptr2->to )
        return -1;
    else
        return 0;
}

int b_comp(const void *a, const void *b){
    int *ptr1 = (int *)a, *ptr2 = (int *)b;
    if( *ptr1 < *ptr2 )
        return -1;
    else if( *ptr1 > *ptr2 )
        return 1;
    else
        return 0;
}

void normalized(Graph *graph, Map *map){  // sort the roads by indices and build the map. 
    qsort(graph->road, graph->cnt, sizeof(Road), comp);
    map->cnt = 0;
    int prev = -1;
    for( int i = 0; i < (graph->cnt); i++ ){
        if( graph->road[i].from != prev ){
            map->key[map->cnt] = graph->road[i].from;
            map->ptr[map->cnt] = &(graph->road[i]);
            map->cnt++;
            prev = graph->road[i].from;
        }
    }
    return;
}

bool hasPath(Graph *graph, Map *map, int city1, int city2){// check if two cities are connected
    bool visited[MAXM] = {0};
    int queue[MAXM] = {city1}, now = 0, cnt = 1;
    visited[city1] = 1;
    while( now < cnt ){
        int pop = queue[now++], *addr;
        addr = bsearch(&pop, map->key, map->cnt, sizeof(int), b_comp);
        if( addr != NULL ){
            Road *r_ptr = map->ptr[(addr-(map->key))];
            while( r_ptr->from == pop ){
                if( !visited[r_ptr->to] ){
                    visited[r_ptr->to] = 1;
                    queue[cnt++] = r_ptr->to;
                }
                r_ptr = &r_ptr[1];
            }
        }
        else{
            return false;
        }
    }
    return visited[city2];
}

int main(){
    int M, Q, city1, city2;
    scanf("%d", &M);
    Graph graph;
    Map map;
    init(&graph, M);
    for( int i = 0; i < M; i++ ){
        scanf("%d%d", &city1, &city2);
        addRoad(&graph, city1, city2);
    }
    normalized(&graph, &map);
    scanf("%d", &Q);
    for( int i = 0; i < Q; i++ ){
        scanf("%d%d", &city1, &city2);
        if( hasPath(&graph, &map, city1, city2) )
            printf("There is a path.\n");
        else
            printf("There is no path.\n");
    }
    return 0;
}