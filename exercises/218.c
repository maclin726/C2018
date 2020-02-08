#include<stdio.h>
int selection(int n,int m){
    int i,outcome=1;
    for(i=1; i<=n; i++){
        outcome*=i;
        if(i<=m)
            outcome/=i;
        else
            outcome/=i-m;
    }
    return outcome;
}
int main(){
    int n,m,i,count=0;
    scanf("%d%d",&n,&m);
    for(i=0; i<=m; i++){
        count+=selection(n,i);
    }
    printf("%d",count);
return 0;
}
