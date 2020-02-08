#include<stdio.h>
int main(){
    int n,m,times=0;
    scanf("%d%d",&n,&m);
    while(m>=10){
        if(m%100==n)
            times++;
        m/=10;
    }
    printf("%d",times);
return 0;
}
