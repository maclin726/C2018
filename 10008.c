#include<stdio.h>
int main(){
    int n,a,b,c,d,e,f,g;
    while(scanf("%d",&n)!=EOF){
        a=n/1000;
        n=n%1000;
        b=n/500;
        n=n%500;
        c=n/100;
        n=n%100;
        d=n/50;
        n=n%50;
        e=n/10;
        n=n%10;
        f=n/5;
        n=n%5;
        g=n;
        printf("%d %d %d %d %d %d %d\n",a,b,c,d,e,f,g);
    }
return 0;
}
