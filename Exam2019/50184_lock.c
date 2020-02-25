#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct locks {
    int cond[3];
    int end;
} Locks;
 
Locks* init(int lockSeq[][3], int n){
    Locks *ptr = (Locks*)malloc(sizeof(Locks) * (n + 1));
    for( int i = 0; i < n; i++ ){
        ptr[i].cond[0] = lockSeq[i][0], ptr[i].cond[1] = lockSeq[i][1], ptr[i].cond[2] = lockSeq[i][2];
        ptr[i].end = 0;
    }
    ptr[n].end = 1;
    return ptr;
}

int sign(int a){
    return 2 * a - 1;
}

int numUnlocked(Locks *locks, bool lights[], int m){
    int sum = 0;
    for( int i = 0; locks[i].end != 1; i++ ){
        int a = locks[i].cond[0], b = locks[i].cond[1], c = locks[i].cond[2];
        if( sign(lights[abs(a)-1]) * a > 0 || sign(lights[abs(b)-1]) * b > 0 || sign(lights[abs(c)-1]) * c > 0 )
            sum++;
    }
    return sum;
}