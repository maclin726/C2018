#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n%d",(a+b)*(b-a+1)/2,a+b+2*(b-a-1));
return 0;
}
