#include<stdio.h>
#include<math.h>
int main(){
    int x1,y1,x2,y2,x3,y3,count=0;
    int product1,product2,product3,x,y;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    int max_x=x1,max_y=y1,min_x=x1,min_y=y1,p,q,flag=0;
    product1=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(product1<0){
        x=x2;
        x2=x3;
        x3=x;
        y=y2;
        y2=y3;
        y3=y;
    }
    max_x=fmax(x1,x2);
    max_x=fmax(max_x,x3);
    min_x=fmin(x1,x2);
    min_x=fmin(min_x,x3);
    max_y=fmax(y1,y2);
    max_y=fmax(max_y,y3);
    min_y=fmin(y1,y2);
    min_y=fmin(min_y,y3);
    for(x=min_x; x<=max_x; x++){
        for(y=min_y; y<=max_y; y++){
            p=x;
            q=y;
            product1=(x1-p)*(y2-q)-(y1-q)*(x2-p);
            product2=(x2-p)*(y3-q)-(y2-q)*(x3-p);
            product3=(x3-p)*(y1-q)-(y3-q)*(x1-p);
            if(product1>=0 && product2>=0 && product3>=0)
                flag++;
            p++;
            product1=(x1-p)*(y2-q)-(y1-q)*(x2-p);
            product2=(x2-p)*(y3-q)-(y2-q)*(x3-p);
            product3=(x3-p)*(y1-q)-(y3-q)*(x1-p);
            if(product1>=0 && product2>=0 && product3>=0)
                flag++;
            q++;
            product1=(x1-p)*(y2-q)-(y1-q)*(x2-p);
            product2=(x2-p)*(y3-q)-(y2-q)*(x3-p);
            product3=(x3-p)*(y1-q)-(y3-q)*(x1-p);
            if(product1>=0 && product2>=0 && product3>=0)
                flag++;
            p--;
            product1=(x1-p)*(y2-q)-(y1-q)*(x2-p);
            product2=(x2-p)*(y3-q)-(y2-q)*(x3-p);
            product3=(x3-p)*(y1-q)-(y3-q)*(x1-p);
            if(product1>=0 && product2>=0 && product3>=0)
                flag++;
            if(flag==4){
                count++;
            }
            flag=0;
        }
    }
    printf("%d",count);
return 0;
}
