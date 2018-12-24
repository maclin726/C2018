#include<stdio.h>
int main(){
    int m,n,x1,y1,e1,n1,f1,x2,y2,e2,n2,f2;
    int i,t=1,time,check=0;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&m,&n,&x1,&y1,&e1,&n1,&f1,&x2,&y2,&e2,&n2,&f2);
    if(f1>=f2)
        time=f1;
    else
        time=f2;
    for (i=time; i>0&&check==0; i--){
        if(f1>0){
            if(t%(e1+n1)<=n1 && t%(e1+n1)>0)
                y1++;
            else
                x1++;
            f1--;
        }
        if(x1>=m)
            x1=0;
        if(y1>=n)
            y1=0;
        if(f2>0){
            if(t%(e2+n2)<=e2 && t%(e2+n2)>0)
                x2++;
            else
                y2++;
            f2--;
        }
        if(x2>=m)
            x2=0;
        if(y2>=n)
            y2=0;
        if(x1==x2&&y1==y2){
            check=1;
            printf("robots explode at time %d",t);
        }
        if(check==0 && i==1){
            printf("robots will not explode");
        }
        t++;
    }
return 0;
}
