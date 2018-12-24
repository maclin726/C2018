#include<stdio.h>
int main(){
    int w,h;
    int n;
    int x=0,y=0;
    scanf("%d%d",&w,&h);
    printf("%d\n%d\n",x,y);
    while(scanf("%d",&n)!=EOF){
        if(n%5==1 && x+n<w){
            x+=n;
            printf("%d\n%d\n",x,y);
        }
        if(n%5==2 && x-n>=0){
            x-=n;
            printf("%d\n%d\n",x,y);
        }
        if(n%5==3 && y+n<h){
            y+=n;
            printf("%d\n%d\n",x,y);
        }
        if(n%5==4 && y-n>=0){
            y-=n;
            printf("%d\n%d\n",x,y);
        }
    }
return 0;
}
