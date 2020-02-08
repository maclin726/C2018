#include <stdio.h>
#define MAXN 100005
int A[MAXN];
int main() {
    int n, i;
    while (scanf("%d", &n) == 1) {
        int k=n-1;
        for (i = 0; i <= k; i++){
            scanf("%d", &A[i]);
            if(A[i]==0){
                A[i]=A[k];
                k--;
                i--;
            }
        }
        for (i = 0; i < n; i++)
            printf("%d%c", A[i], " \n"[i==n-1]);
    }
    return 0;
}
