#include<stdio.h>
int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        int count = 0;
        while(a >= 1){
            count+= a%2;
            a = (a-(a%2))/2;
        }
        printf("%d\n",count);
    }
return 0;
}
