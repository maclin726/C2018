#include<stdio.h>
    int **first_level[100];
    int *second_level[100][100];
int ***constructTable(int A[], int B[]){
    int *bptr = &B[0];
    second_level[0][0] = &B[0];
    int i,j;
    for(int i = 0; A[i] != 0; i++){
        for(int j=0; j < A[i]; j++){
            second_level[i][j] = bptr;
            while( *bptr != 0 ){
                bptr++;
            }
            bptr++;
        }
        first_level[i] = &(second_level[i][0]);
    }
    return (&first_level[0]);
}
int main(){
    int N,M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N,&M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);

    int ***ptr;
    ptr = constructTable(A,B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
}
