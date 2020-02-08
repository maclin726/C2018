#include<stdio.h>
int main(){
    int n,count,flag=0;
    int i;
    int max=-10000,min=10000;
    while(scanf("%d",&n)!=EOF){
        if(flag==0){
            count=n;
            flag=1;
        }
        else{
            if(n>max)
                max=n;
            if(n<min)
                min=n;
            count--;
        }
        if(count==0){
            printf("%d\n",max);
            max=-10000;
            min=10000;
            flag=0;
        }
    }
    if(count!=0){
        printf("%d",min);
    }
return 0;
}
