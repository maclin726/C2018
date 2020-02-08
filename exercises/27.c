#include<stdio.h>
int main(){
    int a,b,c,d,e;
    int s,v;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    s=2*a*b+2*a*c+2*b*c+8*d*(a+b+c-6*e);
    v=a*b*c-((a-2*e)*(b-2*e)+(a-2*e)*(c-2*e)+(b-2*e)*(c-2*e))*d*2;
    printf("%d\n%d",s,v);
return 0;
}
