#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

int *set[MAXN];
int size[MAXN] = {0};

int compare1(const void *a, const void *b){
    int *inta = (int *)a, *intb = (int *)b;
    if( (*inta) > (*intb) )
        return -1;
    else if( (*inta) == (*intb) )
        return 0;
    else
        return 1;
}

int compare2(const void *a, const void *b){
    int *inta = *(int **)a, *intb = *(int **)b;
    int idx = 1;
    while( idx <= inta[0] && idx <= intb[0] ){
        if( inta[idx] > intb[idx] )
            return 1;
        else if( inta[idx] < intb[idx] )
            return -1;
        else
            idx++;
    }
    if( idx > inta[0] && idx > intb[0] )
        return 0;
    else if( idx > inta[0] )
        return -1;
    else
        return 1;
}

int main(){
    int N, data;
    scanf("%d", &N);
    for( int i = 0; i < N; i++ ){
        scanf("%d", &size[i]);
        set[i] = (int *)malloc(sizeof(int) * (size[i]+1));
        set[i][0] = size[i];
        for( int s = 1; s <= size[i]; s++ ){
            scanf("%d", &set[i][s]);
        }
        qsort(&set[i][1], set[i][0], sizeof(int), compare1);
    }

    qsort(set, N, sizeof(int *), compare2);
    
    int M, S, s;
    int *ptr;
    scanf("%d", &M);
    for( int i = 0; i < M; i++ ){
        scanf("%d", &S);
        ptr = (int *)malloc(sizeof(int) * (S + 1));
        ptr[0] = S;
        for( int j = 1; j <= S; j++ )
            scanf("%d", &ptr[j] );
        qsort(&ptr[1], ptr[0], sizeof(int), compare1);
        int upper = 0, lower = N-1, nowCompareIdx = 1;
        while( upper < lower ){
            int mid = (upper + lower) / 2;
            int comp = compare2(&set[mid], &ptr);
            if( comp == 1 )
                lower = mid-1 <= 0? 0: mid-1;
            else if( comp == -1 )
                upper = mid+1 >= N-1? N-1: mid+1;
            else
                upper = lower = mid;
        }
        int same = 1;
        if( ptr[0] != set[upper][0] )
            same = 0;
        else{
            for( int j = 1; j <= ptr[0]; j++ )
                if( set[upper][j] != ptr[j] ){
                    same = 0;
                    break;
                }
        }
        if( !same )
            printf("%d\n", -1);
        else
            printf("%d\n", upper);
        free(ptr);
    }
    return 0;
}