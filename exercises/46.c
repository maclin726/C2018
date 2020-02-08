#include<stdio.h>
#include<string.h>
#include<ctype.h>
    char word[65536]={'\0'};
int count_number(char arr[]){
    int i, sum = 0, power = 1;
    for ( i = strlen(arr) - 1; i >= 0; i-- ){
        sum += (arr[i] - '0') * power;
        power *= 10;
    }
    return sum;
}
int main(){
    char instruction[8];
    int tail = -1;
    while( scanf("%s", instruction) != EOF ){
        if( instruction[0] == 'i' ){
            char a[8], b;
            int index = 0, i;
            scanf("%s", a);
            scanf(" %c", &b);
            if( isdigit( a[0] ) ){
                index = count_number(a);
                for ( i = tail + 1 ; i >= index; i-- )
                    word[i] = word[i-1];
                word[ index - 1 ] = b;
                word[ tail + 2 ] = '\0';
            }
            else if ( a[0] == 'r' ){
                word[ tail + 1 ] = b;
                word[ tail + 2 ] = '\0';
            }
            else if ( a[0] == 'l'){
                for ( i = tail + 1; i >= 1; i-- )
                    word[i] = word[i-1];
                word[0] = b;
                word[ tail + 2 ] = '\0';
            }
            tail++;
#ifdef DEBUG
            printf("%s %s %c\n", instruction, a, b);
            printf("tail is %d\n",tail);
            printf("word now is <%s>\n",word);
#endif // DEBUG
        }
        else if ( instruction[0] == 'd' ){
            char a[8];
            int index = 0, i;
            scanf("%s", a);
            if( isdigit(a[0]) ){
                index = count_number(a);
                for( i = index; i <= tail; i++ )
                    word[i-1] = word[i];
                word[ tail ] = '\0';
            }
            else if( a[0] == 'r' ){
                word[ tail ] = '\0';
            }
            else if( a[0] == 'l' ){
                for( i = 1; i <= tail; i++ )
                    word[i-1] = word[i];
                word[ tail ] = '\0';
            }
            tail--;
#ifdef DEBUG
            printf("%s %s\n", instruction, a);
            printf("word now is <%s>\n", word);
#endif // DEBUG
        }
    }
    char longest[100]={'\0'}, index = 0, pre = '\0';
    int max = 0, count = 1;
    for ( int i = 0; i <= tail; i++ ){
        if( word[i] == pre )
            count++;
        else{
            pre = word[i];
            count = 1;
        }
        if( count == max ){
            longest[index] = word[i];
            index++;
        }
        else if( count > max ){
            max = count;
            index = 0;
            longest[index] = word[i];
            index ++;
        }
    }
    for( int i = 0; i < index; i++)
        printf("%c ", longest[i]);
    printf("%d",max);
    return 0;
}
