#include<stdio.h>
int main(){
    int n,m,r,ball;
    scanf("%d%d%d",&n,&m,&r);
    int a=n,b=m;
    while(scanf("%d",&ball)!=EOF){
        if(r==0){
            if(a>=ball){
                a-=ball;
            }
            else if(b>=ball){
                b-=ball;
            }
        }
        if(r==1){
            if(a>=ball && b>=ball){
                    if(a<=b)
                        a-=ball;
                    else
                        b-=ball;
            }
            else if(a>=ball && b<ball)
                a-=ball;
            else if(a<ball && b>=ball)
                b-=ball;
        }
        printf("%d %d\n",a,b);
    }
return 0;
}
