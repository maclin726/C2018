#include<stdio.h>
int main(){
    int n;
    int x1,y1,r1,x2,y2,r2,x3,y3,r3;
    int count=0;
    int i,j,k,x,y,z;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d%d%d%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2,&x3,&y3,&r3);
        for (j=x1-r1; j<=x1+r1; j++){
            for (k=y1-r1; k<=y1+r1; k++){
                x=(j-x1)*(j-x1)+(k-y1)*(k-y1);
                y=(j-x2)*(j-x2)+(k-y2)*(k-y2);
                z=(j-x3)*(j-x3)+(k-y3)*(k-y3);
                if(x<=r1*r1){
                    count++;
                    if(abs(x1-x2)<=20 && abs(y1-y2)<=20){
                        if(y<=r2*r2)
                            count-=2;
                        if(abs(x1-x3)<=20 && abs(y1-y3)<=20){
                            if(z<=r3*r3 && y<=r2*r2)
                                count+=4;
                        }
                    }
                    if(abs(x1-x3)<=20 && abs(y1-y3)<=20){
                        if(z<=r3*r3)
                            count-=2;
                    }
                }
            }
        }
        for (j=x2-r2; j<=x2+r2; j++){
            for (k=y2-r2; k<=y2+r2; k++){
                y=(j-x2)*(j-x2)+(k-y2)*(k-y2);
                z=(j-x3)*(j-x3)+(k-y3)*(k-y3);
                if(y<=r2*r2){
                    count++;
                    if(abs(x2-x3)<=20 && abs(y2-y3)<=20){
                        if(z<=r3*r3)
                            count-=2;
                    }
                }
            }
        }
        for (j=x3-r3; j<=x3+r3; j++){
            for (k=y3-r3; k<=y3+r3; k++){
                z=(j-x3)*(j-x3)+(k-y3)*(k-y3);
                if(z<=r3*r3)
                    count++;
            }
        }
        printf("%d\n",count);
        count=0;
    }
return 0;
}

//key®e¥¸­ì²z
