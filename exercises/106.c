#include<stdio.h>
#include<stdlib.h>
int main(){
    int mod2, mod3=0, mod5, oddsum=0, evensum=0,count=0;
    char c,d;
    while(scanf("%c",&c) != EOF ){
        if ( d == '-' && c == '1')
            return 0;
        if ( c == '\n' ){
#ifdef DEBUG
            printf("%d %d %d %d %d\n",mod2,mod3,mod5,evensum,oddsum);
#endif // DEBUG
            if( mod2%2 == 0 )
                printf("yes ");
            else
                printf("no ");
            if( mod3%3 == 0)
                printf("yes ");
            else
                printf("no ");
            if( mod5%5 == 0 )
                printf("yes ");
            else
                printf("no ");
            if ( abs(evensum-oddsum)%11 == 0 )
                printf("yes");
            else
                printf("no");
            mod2=0;
            mod3=0;
            mod5=0;
            evensum=0;
            oddsum=0;
            count=0;
            printf("\n");
        }
        else{
            d = c;
            c-=48;
            mod2 = c;
            mod3+= c;
            mod5 = c;
            if(count%2 == 0)
                oddsum+=c;
            else
                evensum+=c;
            count++;
        }
    }
return 0;
}
