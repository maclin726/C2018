#include <stdio.h>
void fill_array(int *ptr[], int n){
    int i,j, *l, *maximum=ptr[0]  ;
    for(i = 1 ; i < n ; i++){
        if( ptr[i] - maximum > 0 )
            maximum = ptr[i];
    }
    for(i = 0 ; i < n ; i++){
        *ptr[i] = i;
    }
    for(l = ptr[0]+1 ; l < (maximum) ; l++){
        int *left=ptr[0], *right=maximum;
        for(j = 0 ; j < n-1 ; j++){
            if( l-ptr[j] > 0 && ptr[j]-left > 0)
                left = ptr[j];
            if( ptr[j]-l > 0 && right-ptr[j] > 0)
                right = ptr[j];
        }
        int check=0;
        for(j = 0 ; j < n-1 ; j++){
            if(ptr[j] == l)
                check = 1;
        }
        if(check == 0){
            *l = *left + *right;
        }
        check=0;
    }
}
int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}
