#include<stdio.h>
int main(){
    int a,b,c,d,e,f;
    int g,money=0;
    int i,end=0;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    while((scanf("%d",&g))!=EOF){
        if(g==a||g==b||g==c)
            money+=2000000;
        for(i=100000000; (i>100&&end==0) ; i/=10){
            if(g%i==d%i || g%i==e%i || g%i==f%i){
                if(i==100000000)
                    money+=200000;
                if(i==10000000)
                    money+=40000;
                if(i==1000000)
                    money+=10000;
                if(i==100000)
                    money+=4000;
                if(i==10000)
                    money+=1000;
                if(i==1000)
                    money+=200;
                end=1;
            }
        }
        end=0;
    }
    printf("%d",money);
return 0;
}
