#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
    int *tail[100000] = {NULL};
    int index = 0, check = 1;
    while( check ){
        if( tail[ A[index] % k ] != NULL ){
            int count = tail[ A[index] % k ] - &A[0];
            a[count] = &A[index];
        }
        else
            head[ A[index]%k ] = &A[index];
        tail[ A[index] % k ] = &A[index];
        if( a[index] == NULL )
            check = 0;
        index++;
    }
    for( int i = 0; i < k; i++ )
        if( tail[i] != NULL ){
            int count = tail[i] - &A[0];
            a[count] = NULL;
        }
}
int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    int *a[N], *head[k];
    for (int i = 0; i < N-1; ++i)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for (int i = 0; i < k; ++i)
        head[i] = NULL;
    split(A, a, head, k);
    for (int i = 0; i < k; ++i) {
        if (head[i] == NULL)
            printf("NULL\n");
        else {
            int *tmp = head[i];
            printf("%d", *tmp);
            tmp = *(tmp-A+a);
            while (tmp != NULL) {
                printf(" %d", *tmp);
                tmp = *(tmp-A+a);
            }
            printf("\n");
        }
    }
    return 0;
}