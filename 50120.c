#include<stdio.h>
    int map[1000][1000];
int main(){
    int n;
    int count = 0, max = 0;
    scanf("%d",&n);
    for ( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ )
            scanf("%d", &map[i][j] );
    }
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if ( map[i][j] == 1 ){
                count++;
                if( count > max )
                    max = count;
            }
            else
                count = 0;
        }
        count = 0;
        for ( int j = 0; j < n; j++ ){
            if ( map[j][i] == 1 ){
                count++;
                if( count > max )
                    max = count;
            }
            else
                count = 0;
        }
        count = 0;
    }
    for ( int i = 0; i < n ; i++ ){
        int x = i;
        for ( int j = 0; x < n; j++ ){
            if ( map[j][x] == 1 ){
                count++;
                if( count > max )
                    max = count;
            }
            else
                count = 0;
            x++;
        }
        count = 0;
        x = i;
        for ( int j = 0; x < n; j++ ){
            if ( map[x][j] == 1 ){
                count++;
                if( count > max )
                    max = count;
            }
            else
                count = 0;
            x++;
        }
        count = 0;
    }
    printf("%d",max);
return 0;
}
