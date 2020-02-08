#include<stdio.h>
int main(){
    int a[9]={0},b[9]={0},n=0,i;     //a[] for mark order, b[] for game board
    int check=0;
    while( scanf("%d",&a[n])!=EOF ){
        n++;
    }
    for(i=0; (i<(n+1)&&check==0); i++){
        if(i%2==0)
            b[a[i]-1]=1;
        if(i%2==1)
            b[a[i]-1]=2;
        if(b[0]==b[1] && b[1]==b[2] && b[0]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[3]==b[4] && b[4]==b[5] && b[3]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[6]==b[7] && b[7]==b[8] && b[6]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[0]==b[3] && b[3]==b[6] && b[0]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[1]==b[4] && b[4]==b[7] && b[1]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[2]==b[5] && b[5]==b[8] && b[2]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[0]==b[4] && b[4]==b[8] && b[0]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
        if(b[2]==b[4] && b[4]==b[6] && b[2]!=0){
                    check=1;
                    printf("%d",a[i]);
        }
    }
    if(check==0)
        printf("0");
return 0;
}

//心得：可以用二維陣列寫，檢驗是否有勝負時會比較方便。
