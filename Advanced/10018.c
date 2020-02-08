#include<stdio.h>
    int array[100000] = {0};
int main(){
    int n,s;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &s);
        if( array[s] ){
            printf("%d", s);
            break;
        }
        array[s] = 1;
    }
return 0;
}