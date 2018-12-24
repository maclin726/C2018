#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char VAR[128][8];
    int VAL[128];
    int var = 0;
    while( scanf("%s", VAR[var]) != EOF )
        if( strcmp(VAR[var], "END") == 0 )
            break;
        else{
            char string[16];
            scanf(" = %s", string);
            VAL[var] = atoi(string);
            var++;
        }
#ifdef DEBUG
    int i;
    for( i = 0; i < var; i++ )
        printf("VAR[%d] = %s, VAL[%d] = %d\n",i, VAR[i], i, VAL[i]);
#endif
    char line[1024][8][8];
    int L = 1;
    while( scanf("%s", line[L][0]) != EOF ){
        if( strcmp( line[L][0], "GOTO" ) == 0 )
            scanf("%s", line[L][1]);
        else if( strcmp( line[L][0], "IF" ) == 0  )
            scanf("%s%s%s%s%s", line[L][1], line[L][2], line[L][3], line[L][4], line[L][5]);
        else if( strcmp( line[L][0], "PRINT" ) == 0  )
            scanf("%s", line[L][1]);
        else if( strcmp( line[L][0], "STOP" ) != 0  )
            scanf("%s%s%s%s", line[L][1], line[L][2], line[L][3], line[L][4]);
        L++;
    }
    int l = 1;
    while( strcmp( line[l][0], "STOP" ) != 0 ){
#ifdef DEBUG
        printf("\nnow line = %d\n", l);
#endif
        if( strcmp( line[l][0], "GOTO" ) == 0 )
            l = atoi(line[l][1]); 
        else if( strcmp( line[l][0], "IF" ) == 0  ){
            int v, var1, var2;
            for( v = 0; v < var; v++ )
                if( strcmp( VAR[v], line[l][1] ) == 0 )
                    var1 = v;
                else if( strcmp( VAR[v], line[l][3] ) == 0 )
                    var2 = v;
            if( ( strcmp( line[l][2], "==" ) == 0  &&  (VAL[var1] == VAL[var2])  ) ||
                ( strcmp( line[l][2], "!=" ) == 0  &&  (VAL[var1] != VAL[var2])  ) ||
                ( strcmp( line[l][2], ">" ) == 0  &&  (VAL[var1] > VAL[var2])    ) ||
                ( strcmp( line[l][2], "<" ) == 0  &&  (VAL[var1] < VAL[var2])    ) ||
                ( strcmp( line[l][2], ">=" ) == 0  &&  (VAL[var1] >= VAL[var2])  ) ||
                ( strcmp( line[l][2], "<=" ) == 0  &&  (VAL[var1] <= VAL[var2])  )  )
                l = atoi(line[l][5]);
            else
                l++;
        }
        else if( strcmp( line[l][0], "PRINT" ) == 0  ){
            int v;
            for( v = 0; v < var; v++ )
                if( strcmp( VAR[v], line[l][1] ) == 0 ){
                    printf("%d\n", VAL[v]);
                    break;
                }
            l++;
        }
        else{
            int v, var1, var2, var3;
            for( v = 0; v < var; v++ ){
                if( strcmp( VAR[v], line[l][0] ) == 0 )
                    var1 = v;
                if( strcmp( VAR[v], line[l][2] ) == 0 )
                    var2 = v;
                if( strcmp( VAR[v], line[l][4] ) == 0 )
                    var3 = v;
            }
            if( strcmp( line[l][3], "+" ) == 0)
                VAL[var1] = VAL[var2] + VAL[var3];
            else if( strcmp( line[l][3], "-" ) == 0)
                VAL[var1] = VAL[var2] - VAL[var3];
            else if( strcmp( line[l][3], "*" ) == 0)
                VAL[var1] = VAL[var2] * VAL[var3];
            else if( strcmp( line[l][3], "/" ) == 0)
                VAL[var1] = VAL[var2] / VAL[var3];
            else if( strcmp( line[l][3], "%" ) == 0)
                VAL[var1] = VAL[var2] % VAL[var3];
            l++;
        }
        int i;
#ifdef DEBUG
        for( i = 0; i < var; i++ )
            printf("%s = %d ", VAR[i], VAL[i]);
#endif
    }
    return 0;
}