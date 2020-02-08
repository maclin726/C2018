#include<stdio.h>
int main(){
    int a[1000],b[1000],c[1000];
    int i,j=0,k=0;
    int n;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i]%2==1){
            b[j]=a[i];
            j++;
        }
        else{
            c[k]=a[i];
            k++;
        }
    }
    for(i=0; i<j; i++){
        if(i!=0)
            printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
    for(i=0; i<k; i++){
        if(i!=0)
            printf(" ");
        printf("%d",c[i]);
    }
return 0;
}
