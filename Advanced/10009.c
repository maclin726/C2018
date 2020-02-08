#include<stdio.h>
#include<math.h>
int gcd(int a,int b){
    int k,p,q;
    p=fmax(a,b);
    q=fmin(a,b);
    while(p%q!=0){
        k=p;
        p=q;
        q=k%q;
    }
    return q;
}
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d / %d\n",a/gcd(a,b),b/gcd(a,b));
    }
return 0;
}
