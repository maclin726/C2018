#include<stdio.h>
#include<math.h>
int gcd(int a,int b){
    if(a==0 || b==0){
        return 1;
    }
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
    int n,p[16][2],s[15][2],ratio[120][2];
    int i,j;
    int count,divide;
    for(i=0; i<16; i++){
        p[i][0]=1;
        p[i][1]=1;
        if(i!=15){
            s[i][0]=1;
            s[i][1]=1;
        }
    }
    scanf("%d",&n);
    for (i=0; i<(n*(n+1)/2); i++){
        scanf("%d%d",&ratio[i][0],&ratio[i][1]);
        if(ratio[i][0]==0)
            ratio[i][1]=1;
        else if(ratio[i][1]==0)
            ratio[i][0]=1;
        else{
            divide=gcd(ratio[i][0],ratio[i][1]);
            ratio[i][0]/=divide;
            ratio[i][1]/=divide;
        }
    }
    if(n==0){
        printf("1/1");
    }
    else{
        for (i=1; i<=n; i++){           //處理球跑到第n層
            count=(i-1)*i/2;
            for(j=0; j<i; j++){
                s[j][0]=p[j][0];
                s[j][1]=p[j][1];
            }
            for(j=0; j<=i; j++){        //處理第i層時第j個 hole's probability
                if(j==0){
                    p[j][0]*=ratio[count][0];
                    p[j][1]*=(ratio[count][0]+ratio[count][1]);
                    divide=gcd(p[j][0],p[j][1]);
                    p[j][0]/=divide;
                    p[j][1]/=divide;
                    if(p[j][0]==0)
                        p[j][1]=1;
                }
                else if(j==i){
                    p[j][0]=s[i-1][0]*ratio[count+j-1][1];
                    p[j][1]=s[i-1][1]*(ratio[count+j-1][0]+ratio[count+j-1][1]);
                    divide=gcd(p[j][0],p[j][1]);
                    p[j][0]/=divide;
                    p[j][1]/=divide;
                    if(p[j][0]==0)
                        p[j][1]=1;
                }
                else{
                    int w=s[j-1][0]*ratio[count+j-1][1];
                    int x=s[j-1][1]*(ratio[count+j-1][0]+ratio[count+j-1][1]);
                    int y=s[j][0]*ratio[count+j][0];
                    int z=s[j][1]*(ratio[count+j][0]+ratio[count+j][1]);
                    divide=gcd(w,x);
                    w/=divide;
                    x/=divide;
                    divide=gcd(y,z);
                    y/=divide;
                    z/=divide;
                    p[j][0]=x*y+w*z;
                    p[j][1]=x*z;
                    divide=gcd(p[j][0],p[j][1]);
                    p[j][0]/=divide;
                    p[j][1]/=divide;
                    if(p[j][0]==0)
                        p[j][1]=1;
                }
            }
        }
        for(i=0; i<=n; i++){
            printf("%d/%d\n",p[i][0],p[i][1]);
        }
    }
return 0;
}
