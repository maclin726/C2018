#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int intersection(int x1,int y1,int x2,int y2,int x3,int y3, int x4, int y4){
    int X=0,Y=0;
    if(x1<=x3 && x3<x2){
        if(x4>=x2){
            X=x2-x3;
        }
        else
            X=x4-x3;
    }
    else if(x3<=x1 && x1<x4){
        if(x2>=x4){
            X=x4-x1;
        }
        else
            X=x2-x1;
    }
    if(y1<=y3 && y3<y2){
        if(y4>=y2){
            Y=y2-y3;
        }
        else
            Y=y4-y3;
    }
    else if(y3<=y1 && y1<y4){
        if(y2>=y4){
            Y=y4-y1;
        }
        else
            Y=y2-y1;
    }
    return (X*Y);
}

int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    int area=0;
    int inter1,inter2,inter3,inter4;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5,&x6,&y6);
    inter1=intersection(x1,y1,x2,y2,x3,y3,x4,y4);
    inter2=intersection(x1,y1,x2,y2,x5,y5,x6,y6);
    inter3=intersection(x3,y3,x4,y4,x5,y5,x6,y6);
    int X1=0,X2=0,Y1=0,Y2=0;
    if(x1<=x3 && x3<x2){
        if(x4>=x2){
            X1=x3;
            X2=x2;
        }
        else{
            X1=x3;
            X2=x4;
        }
    }
    else if(x3<=x1 && x1<x4){
        if(x2>=x4){
            X1=x1;
            X2=x4;
        }
        else{
            X1=x1;
            X2=x2;
        }
    }
    if(y1<=y3 && y3<y2){
        if(y4>=y2){
            Y1=y3;
            Y2=y2;
        }
        else{
            Y1=y3;
            Y2=y4;
        }
    }
    else if(y3<=y1 && y1<y4){
        if(y2>=y4){
            Y1=y1;
            Y2=y4;
        }
        else{
            Y1=y1;
            Y2=y2;
        }
    }
    inter4=intersection(X1,Y1,X2,Y2,x5,y5,x6,y6);
    area=abs((y2-y1)*(x2-x1))+abs((y4-y3)*(x4-x3))+abs((y6-y5)*(x6-x5))-inter1-inter2-inter3+inter4;
    printf("%d",area);
    return 0;
}
