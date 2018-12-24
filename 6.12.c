#include<stdio.h>
int main(){
    int n;
    int a[10000];
    int i,j,temp,d=10;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for (i=(n-1); i>0; i--){
        for (j=0; j<i; j++){
            while(a[j]%d == a[j+1]%d){
                d*=10;
            }
            if (a[j]%d > a[j+1]%d){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                d=10;
            }
        }
    }
    printf("\n");
    for (i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
return 0;
}
