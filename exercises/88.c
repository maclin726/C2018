#include<stdio.h>
int main(){
    int a,b,c,d,w,x,y,z;
    int m=0,n=0;
    int p,q; //abcd,wxyz each digit, while
    scanf("%d%d",&p,&q);
    a=p%10;
    b=(p%100)/10;
    c=(p%1000)/100;
    d=p/1000;
    w=q%10;
    x=(q%100)/10;
    y=(q%1000)/100;
    z=q/1000;
    if(a==w)
        m++;
    if(b==x)
        m++;
    if(c==y)
        m++;
    if(d==z)
        m++;
    if(a==x || a==y || a==z)
        n++;
    if(b==w || b==y || b==z)
        n++;
    if(c==w || c==x || c==z)
        n++;
    if(d==x || d==y || d==w)
        n++;
    printf("%dA%dB",m,n);
return 0;
}
