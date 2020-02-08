#include<stdio.h>
#include<math.h>
int lcm(int a,int b){
    int i,gcd=1;
    for (i=1; i<=fmin(a,b);i++){
        if(a%i==0 && b%i==0)
            gcd=i;
    }
    return (a*b/gcd);
}

int main(){
    int n,m=1;
    while (scanf("%d",&n)!=EOF){
        m=lcm(n,m);
    }
    printf("%d",m);
return 0;
}
