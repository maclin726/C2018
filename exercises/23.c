#include <stdio.h>
int max(int *iptr[], int n){
    int i;
    int *maximum = iptr[0];
    for(i=0 ; i<n; i++){
#ifdef DEBUG
        printf("*ptr=%d\n*maximum=%d\n",*iptr[i],*maximum);
#endif // DEBUG
        if( (*iptr[i]) > (*maximum) )
            maximum = iptr[i];
    }
    return (*maximum);
}

int main() {
    int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
    return 0;
}
