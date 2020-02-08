#include<stdio.h>
int main(){
    int n,i,s,a=0,b=0,c=0;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&s);
        if(s%3==0)
            a++;
        else if(s%3==1)
            b++;
        else if(s%3==2)
            c++;
    }
    printf("%d %d %d",a,b,c);
}
