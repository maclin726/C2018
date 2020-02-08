#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char a[16384], b[128];
    int i = 0;
    while( scanf("%c",&a[i]) != EOF ){
        if( a[i] == '.' ){
#ifdef DEBUG
            printf("a:<%s>\n",a);
#endif // DEBUG
            int j, count = 0, space = 1;
            for(j = 0; j < i; j++){
#ifdef DEBUG
                printf("space now is %d\n",space);
                printf("alpha now is %d\n",isalpha(a[j]));
#endif // DEBUG
                if( isalpha(a[j]) != 0 && space == 1 ){
                    space = 0;
                    if( (a[j] == 't' && a[j+1] == 'h' && a[j+2] == 'e' && isalpha(a[j+3]) == 0) ||
                        (a[j] == 'a' && a[j+1] == 'n' && a[j+2] == 'd' && isalpha(a[j+3]) == 0) ||
                        (a[j] == 'a' && a[j+1] == 't' && isalpha(a[j+2]) == 0) ||
                        (a[j] == 'o' && a[j+1] == 'f' && isalpha(a[j+2]) == 0) ){
                        continue;
                    }
                    else{
                        b[count] = toupper( a[j] );
#ifdef DEBUG
                        printf("b[%d]: %c\n",count,a[j]);
                        printf("space now is %d\n",space);
#endif
                        count++;
                        b[count] = '\0';
                    }
                }
                else if( isalpha(a[j]) == 0 && space == 0 )
                    space = 1;
            }
            printf("%s\n",b);
            count = 0;
            space = 1;
            i = 0;
        }
        else
            i++;
    }
    return 0;
}
