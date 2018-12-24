#include<stdio.h>
int main(){
    char c,i;
    int a[26]={0};
    while( scanf("%c",&c)!=EOF ){
        for( i=0; i<26; i++ )
            if( c == ('a' + i) || c == ('A' + i) )
                a[i]++;
    }
    for(i = 0; i<26; i++)
        printf("%d\n",a[i]);
return 0;
}
