#include <stdio.h>
#include <string.h>
#include <ctype.h>
int validtest( char license[8] ){
    int cntalpha = 0, cntdigit = 0, sum = 0, hyphon_index = 0;
    for( int i = 0; i < 7; i ++ ){                  //the first and second rule
        if( isalpha(license[i]) )
            cntalpha++;
        if( isdigit(license[i]) ){
            cntdigit++;
            sum += license[i] - '0' ;
        }
        if( license[i] == '-' )
            hyphon_index = i;
    }
    if( (!cntdigit) || (cntalpha + cntdigit != 6) || (hyphon_index != 2 && hyphon_index != 3) || (sum % 7 == 0) )
        return 0;
    char record[8];
    int count[8] = {0}, type = 0, fourcount[2] = {-1,-1}, fourcnt = 0;
    for( int i = 0; i < 7; i++ ){
        int same = 0;
        for( int j = 0; j < type && !same ; j++ )
            if( license[i] == record[j] ){
                count[j]++;
                same = 1;
                if( count[j] == 3 )
                    return 0;
            }
        if( !same ) {
            record[type] = license[i];
            count[type]++;
            type++;
        }
        if( license[i] == '4' ){
            fourcount[fourcnt] = i;
            fourcnt++;
        }
    }
    if( fourcount[1] != (-1) && fourcount[1] - fourcount[0] < 2 )
        return 0;
    else if( hyphon_index == 2 )
        return 1;
    else if( hyphon_index == 3 )
        return 2;
}
void sort( char type[32][8], int cnt ){
    for( int i = 0; i < cnt; i++ ){
        for( int j = cnt-1; j > i; j-- )
            if( strcmp( type[j], type[j-1] ) < 0 ){
                char temp[8];
                strcpy( temp, type[j] );
                strcpy( type[j], type[j-1] );
                strcpy( type[j-1], temp);
            }
    }
    return;
}
int main(){
    int N;
    scanf("%d", &N);
    char license[32][8];
    char typeA[32][8] = {'\0'}, typeB[32][8] = {'\0'};
    int cntA = 0, cntB = 0;
    for( int i = 0; i < N; i++){
        scanf("%s", license[i]);
        switch( validtest(license[i]) ){
            case 1:
                strcpy( typeA[cntA], license[i] );
                cntA++;
                break;
            case 2:
                strcpy( typeB[cntB], license[i] );
                cntB++;
                break;
        }
    }
    sort( typeA, cntA );
    sort( typeB, cntB );
    for( int i = 0; i < cntA; i++)
        printf("%s\n",typeA[i]);
    for( int i = 0; i < cntB; i++)
        printf("%s\n",typeB[i]);
    return 0;
}