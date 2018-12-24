#include<stdio.h>
int main(){
    int i,n,j,outcome=1;
    scanf("%d%d",&n,&i);
    for (j=0; j<i; j++){
        outcome*=n;
    }
    printf("%d",outcome);
return 0;
}
