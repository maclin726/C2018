#include<stdio.h>
int main(){
    int xa,ya,xb,yb,xc,yc;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
    printf("%d\n%d\n",xb+xc-xa,yb+yc-ya);
    printf("%d\n%d\n",xa+xc-xb,ya+yc-yb);
    printf("%d\n%d",xa+xb-xc,ya+yb-yc);
return 0;
}
