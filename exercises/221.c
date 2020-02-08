#include<stdio.h>
#include<string.h>
int main(){
    int m;
    scanf("%d", &m);
    char inp[512], save[512][512];
    int length = 0, str_num = 0;
    while( scanf("%s", inp) != EOF ){
        int input_length = strlen(inp);
        if( length + str_num + input_length < m ){
            strcpy( save[str_num], inp );
            length += input_length;
            str_num++;
        }
        else if ( length + str_num + input_length == m ){
            for( int i = 0; i < str_num; i++ )
                printf("%s ", save[i]);
            printf("%s\n", inp);
            for( int i = 0; i < 256; i++)
                save[i][0] = '\0';
            str_num = 0;
            length = 0;
        }
        else{
            int space_count;
            if (str_num != 1)
                space_count = (m - length) / (str_num - 1);
            else
                space_count = m - strlen(inp);
            for( int i = 0; i < str_num; i++ ){
                printf("%s", save[i]);
                for( int j = 0; j < space_count; j++ )
                    printf(" ");
                if(str_num != 1)
                    if( i < (m - length) % (str_num - 1) )
                        printf(" ");
            }
            printf("\n");
            for( int i = 0; i < 256; i++)
                save[i][0] = '\0';
            strcpy( save[0], inp );
            str_num = 1;
            length = input_length;
        }
    }
    int space_count = 0;
    if (str_num != 1)
        space_count = (m - length) / (str_num - 1);
    else
        space_count = m - strlen(save[0]);
    for( int i = 0; i < str_num; i++ ){
        printf("%s", save[i]);
        for( int j = 0; j < space_count; j++ )
            printf(" ");
        if( str_num != 1 )
            if( i < (m - length) % (str_num - 1) )
                printf(" ");
        if( i == str_num - 1 )
            printf("\n");
    }
return 0;
}
