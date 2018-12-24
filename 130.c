#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int equivalent(char a[], char b[]){
    int i, check = 0;
    for ( i = 0; i < strlen(a) && check == 0; i++)
        if(a[i] != b[i])
            check = 1;
    if(check == 0)
        return 1;
    else
        return 0;
}

int main(){
    int i,n;
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        int check = 0;
        int j;
        char a[81], b[81], c[81];
        scanf("%s", a);
        scanf("%s", b);
        if( abs( strlen(a) - strlen(b) ) == 1 ){
            if ( strlen(a) < strlen(b) ){
                strcpy(c , b);              //string copy (destination, source)
                strcpy(b , a);
                strcpy(a , c);
            }
            for( j = 0; j < strlen(a); j++ ){
                int k, ok = 0;
                for( k = 0; k < strlen(b) && ok == 0; k++ )
                    if( k < j && a[k] != b[k] )
                        ok = 1;
                    else if ( k >= j && a[k+1] != b[k] )
                        ok = 1;
                if(ok == 0)
                    check = 1;
            }
        }
        else if ( strlen(a) == strlen(b) ){
            if(equivalent(a,b) == 1)
                check = 1;
            char temp;
            for ( j = 0; j < (strlen(a)-1) && check != 1 ; j++ ){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                if(equivalent(a,b) == 1)
                    check = 1;
                else{
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        (check == 0)? printf("no\n") : printf("yes\n") ;
    }
}
