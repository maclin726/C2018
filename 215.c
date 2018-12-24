#include<stdio.h>
int main(){
    int a,b,c;
    int d,e,f;
    scanf("%d%d%d",&a,&b,&c);
    d=-(4*c+b-8*a);
    e=-(8*a-b-6*c);
    f=-(2*c-2*a);
    if(d%2==0 && e%2==0 && f%2==0 && d>=0 && e>=0 && f>=0){
        printf("%d\n",d/2);
        printf("%d\n",e/2);
        printf("%d",f/2);
    }
    else
        printf("0");
return 0;
}
