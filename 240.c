#include<stdio.h>
int main(){
    int n,i;
    int x1,y1,x2,y2,x3,y3,x4,y4,x,y,w,z;
    int p,q,r;
    int a,b,c,d;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        p=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);  //point 2 to 3
        q=(x3-x1)*(y4-y1)-(y3-y1)*(x4-x1);  //point 3 to 4
        r=(x2-x1)*(y4-y1)-(y2-y1)*(x4-x1);  //point 2 to 4
        if(p>0 && q<0 && r>0){
            x=x3;
            y=y3;
            x3=x4;
            y3=y4;
            x4=x;
            y4=y;
        }
        if(p<0 && q>0 && r>0){
            x=x2;
            y=y2;
            x2=x3;
            y2=y3;
            x3=x;
            y3=y;
        }
        if(p<0 && q>0 && r<0){
            x=x2;
            y=y2;
            w=x4;
            z=y4;
            x2=x3;
            y2=y3;
            x4=x;
            y4=y;
            x3=w;
            y3=z;
        }
        if(p>0 && q<0 && r<0){
            x=x2;
            y=y2;
            w=x3;
            z=y3;
            x2=x4;
            y2=y4;
            x3=x;
            y3=y;
            x4=w;
            y4=z;
        }
        if(p<0 && q<0 && r<0){
            x=x2;
            y=y2;
            x2=x4;
            y2=y4;
            x4=x;
            y4=y;
        }
        a=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        b=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
        c=(x4-x3)*(x4-x3)+(y4-y3)*(y4-y3);
        d=(x4-x1)*(x4-x1)+(y4-y1)*(y4-y1);
        if(a==b && b==c && c==d){
            if((x2-x1)*(x3-x2)+(y2-y1)*(y3-y2)==0)
                printf("square\n");
            else
                printf("diamond\n");
        }
        else if(a==c && b==d && (x2-x1)*(x3-x2)+(y2-y1)*(y3-y2)==0)
            printf("rectangle\n");
        else
            printf("other\n");
    }
return 0;
}
