#include<stdio.h>
void switch_people(int array[],int i, int j){
    int temp;
    temp=array[j];
    array[j]=array[i];
    array[i]=temp;
}

int main(){
    int n,a[2048],balance=0;
    int left=0,right=0;
    int i;
    scanf("%d",&n);
    int leftnumber=0,rightnumber=n-1;
    for(i=0 ;i<n; i++){
        scanf("%d",&a[i]);
    }
    while(left!=right || left==0 || right==0){
        left=0;
        right=0;
        for(i=0; i<n; i++){
            if(i<balance)
                left+=a[i]*(balance-i);
            else if(i>balance)
                right+=a[i]*(i-balance);
        }
        balance++;
        if(balance>=n-1){
            switch_people(a,leftnumber,rightnumber);
            leftnumber++;
            rightnumber--;
            balance=0;
        }
    }
    for(i=0; i<n; i++){
        if(i!=(balance-1) && i!=n-1)
            printf("%d ",a[i]);
        else if( i==(balance-1) )
            printf("v ");
        else if(i==n-1)
            printf("%d",a[i]);
    }
return 0;
}
