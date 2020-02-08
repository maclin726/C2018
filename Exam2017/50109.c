#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    char name[16];
    int cited;
}paper;
 
int compare(const void *a, const void *b ){
    paper *ptr1 = (paper *)a;
    paper *ptr2 = (paper *)b;
    if( strcmp(ptr1->name, ptr2->name) > 0 )
        return 1;
    else if( strcmp(ptr1->name, ptr2->name) < 0 )
        return -1;
    else if( ptr1->cited < ptr2->cited )
        return 1;
    else if( ptr1->cited > ptr2->cited )
        return -1;
    else
        return 0;
}
 
int main(){
    paper Paper[20000];
    int n = 0;
    while( scanf("%s%d", Paper[n].name, &Paper[n].cited) != EOF )
        n++;
    qsort( Paper, n, sizeof(paper), compare );
#ifdef DEBUG
    for( int i = 0; i < n; i++ )
        printf("%s%d\n", Paper[i].name, Paper[i].cited);
#endif
 
    int h_index = 0;
    for( int i = 0; i < n; i++ ){
        if( Paper[i].cited > h_index ){
            h_index++;
            if( strcmp(Paper[i].name, Paper[i+1].name) != 0 ){
                printf("%s %d\n", Paper[i].name, h_index);
                h_index = 0;
            }
        }
        else{
            printf("%s %d\n", Paper[i].name, h_index);
            h_index = 0;
            while( strcmp( Paper[i].name, Paper[i+1].name ) == 0 )
                i++;
        }
    }
    return 0;
}
