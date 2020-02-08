#include<stdio.h>
int main(){
    int n;
    int i;
    int x1,y1,x2,y2,x3,y3;
    int a,b,c;
    int d[10];
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        b=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        c=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        if(a==b||b==c||a==c)
            d[i]=0;
        else if(a+b>c && a+c>b && b+c>a)
            d[i]=1;
        else if(a+b==c  || b+c==a || a+c==b)
            d[i]=2;
        else if(a+b<c || b+c<a || a+c<b)
            d[i]=3;
    }
    for (i=0; i<n; i++){
        if(i!=0)
            printf("\n");
        if(d[i]==0)
            printf("isosceles");
        if(d[i]==1)
            printf("acute");
        if(d[i]==2)
            printf("right");
        if(d[i]==3)
            printf("obtuse");
    }
return 0;
}
