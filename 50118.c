#include<stdio.h>
int main(){
    int a, count = 0, max = 0;
    while( scanf("%d",&a) != EOF ){
        int end ,head, number = a;
        if( count == 0 ){
            end = a % 10;
            while( a > 0 ){
                a /= 10;
                count++;
            }
            if(max < count)
                max = count;
        }
        else{
            while( number >= 10 )
                number /= 10;
            head = number;
            if (head == end){
                end = a % 10;
                while( a > 0 ){
                    a /= 10;
                    count++;
                }
                if( max < count )
                    max = count;
            }
            else{
                end = a % 10;
                count = 0;
                while( a > 0 ){
                    a /= 10;
                    count++;
                }
                if( max < count )
                    max = count;
            }
        }
    }
    printf("%d",max);
return 0;
}
