#include<stdio.h>
int main(){
    unsigned int number;
    int map[32];
    int m, n, r = 0, c = 0;
    scanf("%d%d",&m,&n);
    char a[2],b[2];
    scanf("%s%s",a,b);
    while( scanf("%u", &number) != EOF ){
        int i;
        for( i = 31; i >= 0; i-- ){
            map[i] = number % 2;
            number /= 2;
        }
        for( i = 0; i < 32; i++){
            if(map[i])
                printf("%s",a);
            else
                printf("%s",b);
            c++;
            if( c == m ){
                c = 0;
                r++;
                printf("\n");
                if( r == n )
                    return 0;
            }
        }
    }
    return 0;
}