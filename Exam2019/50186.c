#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ta_set.h"

int comp(const void *a, const void *b){
    int **ptr1 = (int **)a, **ptr2 = (int **)b;
    if( (*ptr1)[(*ptr1)[0]] < (*ptr2)[(*ptr2)[0]] )
        return -1;
    else if( (*ptr1)[(*ptr1)[0]] > (*ptr2)[(*ptr2)[0]] )
        return 1;
    else
        return 0;
}
int best_count;
ta_Set best_set;
void findSet(int *head[], ta_Set sets[], ta_Set *nowSet, int x, int n, int k, int cnt){
    //printf("%lld\n", nowSet->x);
    int idx = 0;
    while( idx < k && head[idx][head[idx][0]] < x ){          //pruning
        if( !intersect(sets[idx], *nowSet) )
            return;
        idx++;
    }
    if( idx == k && cnt < best_count ){
        best_set = *nowSet;
        best_count = cnt;
    }
    if( x == n+1 )
        return;
    #ifdef LARGESTDICTIONARYORDER
    findSet(head, sets, nowSet, x+1, n, k, cnt);
    addElement(nowSet, x);
    findSet(head, sets, nowSet, x+1, n, k, cnt+1);
    removeElement(nowSet, x);
    #endif
    
    #ifdef SMALLESTDICTIONARYORDER
    addElement(nowSet, x);
    findSet(head, sets, nowSet, x+1, n, k, cnt+1);
    removeElement(nowSet, x);
    findSet(head, sets, nowSet, x+1, n, k, cnt);
    #endif
    return;
}

int main(){
    int n, k, T[128][65];
    int *head[128] = {NULL};
    ta_Set sets[128];
    scanf("%d%d", &n, &k);
    for( int i = 0; i < k; i++ ){
        head[i] = &T[i][0];
        scanf("%d", &T[i][0]);
        for( int j = 1; j <= T[i][0]; j++ )
            scanf("%d", &T[i][j]);
    }
    qsort(head, k, sizeof(int *), comp);
    for( int i = 0; i < k; i++ ){
        initializeSet(&sets[i], n);
        for( int j = 1; j <= head[i][0]; j++ )
            addElement(&sets[i], T[i][j]);
    }
    best_count = n+1;
    ta_Set nowset;
    initializeSet(&nowset, n);
    findSet(head, sets, &nowset, 1, n, k, 0); 
    printSet(best_set);
    return 0;
}