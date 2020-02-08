#include<stdio.h>
#include<ctype.h>
int main(){
    char c, pre_c, prepre_c, count=0, check=0;
    while( scanf("%c",&c)!=EOF ){
        if( c == ' ' && pre_c == ' ' && prepre_c == '.' )
            count++;
        else if ( c == '\n' && pre_c == '.')
            count++;
        if( c == '.' && check == 0 )
            check = 1;
        else
            check = 0;
        if( (c == ' ' || c == '\n') && check != 0 )
            check = 2;
        else
            check = 0;
        prepre_c = pre_c;
        pre_c = c;
    }
    if(check == 2)
        count++;
    if(pre_c == '.')
        count++;
    printf("%d",count);
return 0;
}
