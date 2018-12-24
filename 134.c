#include<stdio.h>
#include<stdlib.h>

int level[1024][512] = {0};
int levelCount[1024] = {0};
int maxLevel = 0;

int findLevel( int number ){
    for( int i = 1; i <= maxLevel; i++ ){
        if( number < level[i][0] || number > level[i][levelCount[i]-1] )
            continue;
        for( int j = 0; j < levelCount[i]; j++ )
            if( level[i][j] == number )
                return i;
    }
}

int differentSide( int p, int q, int base ){
    return( (p > base && q < base) || (p < base && q > base) || (p == base) || (q == base) );
}

int commonParentLevel(int p, int q){
    for( int i = 1; i <= maxLevel; i++ ){
        if( (p < level[i][0] && q < level[i][0] ) || (p > level[i][levelCount[i]-1] && q > level[i][levelCount[i]-1]) )
            continue;
        for( int j = 0; j < levelCount[i]; j++ )
            if( differentSide(p, q, level[i][j]) )
                return i;
    }
}

int compare(const void *a, const void *b){
    if( *(int*)a > *(int*)b )
        return 1;
    else if( *(int*)a == *(int*)b )
        return 0;
    else
        return -1;
}

int main(){
    int N,P;
    scanf("%d", &N);
    for( int i = 0; i < N; i++ ){
        int n, d;
        scanf("%d%d", &n, &d);
        if( d > maxLevel )
            maxLevel = d;
        level[d][levelCount[d]] = n;
        levelCount[d]++;
    }
    for( int i = 1; i <= maxLevel; i++ )
        qsort( &level[i], levelCount[i], 4, compare);
    scanf("%d",&P);
    for( int i = 0; i < P; i++ ){
        int p,q;
        scanf("%d%d", &p, &q);
        printf("%d\n", findLevel(p) + findLevel(q) - 2*commonParentLevel(p,q));
    }
    return 0;
}