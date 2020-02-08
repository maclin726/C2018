#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a)
    if( a % 2 == 0 && a > 0 && (a > 10000 || a < 1000) )
        printf("1");
    else
        printf("0");
return 0;
}
