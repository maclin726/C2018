#include<stdio.h>
#include<string.h>

int main(void){
    char a[128] = {'\0'} ,input[128];
    int end = 0;
    while( scanf("%s", input) != EOF ){
#ifdef DEBUG
        printf("input is <%s>\n",input);
#endif // DEBUG
        int i, max_string = 0;
        for ( i = strlen(input); i > 0 && max_string == 0; i-- ){
            if ( strlen(a) < i )
                continue;
            int j, check = 0;
            for ( j = 0; j < i && check == 0; j++ ){
                if( input[j] != a[end - i + 1 + j] )
                     check = 1;
            }
            if( check == 0 ){
                max_string = 1;
                end = end - i + 1;
                a[end] = '\0';
            }
        }
#ifdef DEBUG
        printf("after while a:<%s>\n",a);
#endif // DEBUG
        strcat( a , input);
        end = strlen(a) - 1;
#ifdef DEBUG
        printf("%s\n",a);
        printf("end = %d\n",end);
#endif // DEBUG
    }
    printf("%s",a);
    return 0;
}
