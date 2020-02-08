#include<stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    printf("%d\n",x/100);
    x=x%100;
    printf("%d\n",x/10);
    x=x%10;
    printf("%d",x);
return 0;
}
