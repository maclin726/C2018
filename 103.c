#include<stdio.h>
int main(){
    double a[16][16],x[16]={0},y[16];
    int n,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
        scanf("%lf",&y[i]);

    for(i=(n-1); i>=0; i--){
        for(j=(n-1); j>i; j--){
            y[i]=y[i]-a[i][j]*x[j];
        }
        x[i]=y[i]/a[i][i];
    }
    for(i=0; i<n; i++){
        printf("%f\n",x[i]);
    }
return 0;
}
