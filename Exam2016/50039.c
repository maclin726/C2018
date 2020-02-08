#include<stdio.h>
int main(){
    int a1,b1,a2,b2,a3,b3;
    scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
    printf("%d\n",a1*b1+a2*b2+a3*b3);
    printf("%d %d %d",a2*b3-a3*b2,a3*b1-a1*b3,a1*b2-a2*b1);
return 0;
}
