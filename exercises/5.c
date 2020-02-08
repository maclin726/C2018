#include<stdio.h>
int main(){
    int a,b,c;
    int w,v;
    scanf("%d%d%d",&a,&b,&c);
    w=2*a*b+2*b*c+2*a*c;
    v=a*b*c;
    printf("%d\n%d",w,v);
return 0;
}
