#include<stdio.h>
#include<string.h>
int main(){
    int n,j,k,l;
    char recipe[128][16][128];
    scanf("%d",&n);
    for ( j = 0; j < n; j++ ){
        scanf("%s", recipe[j][0] );
        int i;
        scanf("%d", &i);
        for ( k = 1; k <= i; k++ ){
            scanf("%s", recipe[j][k]);
        }
    }
    int m;
    scanf("%d",&m);
    for ( j = 0; j < m; j++ ){
        char a[128], b[128], ingredient[10][128];
        scanf("%s %s", a, b);
        int index_a = 0, index_b = 0, count_ingredient = 0;
        while( strcmp(a, recipe[index_a][0]) != 0 )
            index_a++;
        while( strcmp(b, recipe[index_b][0]) != 0 )
            index_b++;
        for ( k = 1; recipe[index_a][k][0] != '\0'; k++ )
            for ( l = 1; recipe[index_b][l][0] != '\0'; l++ )
                if ( strcmp( recipe[index_a][k], recipe[index_b][l]) == 0 ){
                    strcpy(ingredient[count_ingredient], recipe[index_a][k]);
                    count_ingredient++;
                }
        for ( k = count_ingredient - 1; k > 0; k-- ){
            for ( l = 0; l < k; l++ )
                if( strcmp(ingredient[l], ingredient[l+1]) > 0 ){
                    char temp[128];
                    strcpy( temp, ingredient[l] );
                    strcpy( ingredient[l], ingredient[l+1] );
                    strcpy( ingredient[l+1], temp );
                }
        }
        for ( k = 0; k < count_ingredient; k++){
            ( k != count_ingredient - 1)?
                printf("%s ",ingredient[k]): printf("%s",ingredient[k]);
        }
        if( count_ingredient == 0 )
            printf("nothing");
        printf("\n");
#ifdef DEBUG
        printf("a= %s, b=%s\n",recipe[index_a][0],recipe[index_b][0]);
#endif // DEBUG
    }
return 0;
}
