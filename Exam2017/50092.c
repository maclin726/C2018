#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
 
int digits(char *string){
    int i;
  for (i = 0; i < strlen(string); i++)
    if (!isdigit(string[i]))
      return 0;
  return 1;
}
 
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    int i;
    memset(A, 0, sizeof(A[0])*a);
    memset(B, 0, sizeof(B[0])*b);
    char s[128];
    while( fgets(s, 64, stdin) != NULL ){
        char *arr[5] = {NULL};                            //分成四個組序處理
        arr[0] = strtok( s, " \t\n" );
        for( i = 1; i < 5; i++ )
            arr[i] = strtok( NULL , " \t\n" );
#ifdef DEBUG
        printf("arr[0]<%s>\narr[1]<%s>\narr[2]<%s>\narr[3]<%s>\narr[4]<%s>\n", arr[0], arr[1], arr[2], arr[3],arr[4]);
#endif
        int end = 1;
        if( arr[0] == NULL || arr[1] == NULL || arr[2] == NULL || arr[3] == NULL || arr[4] != NULL){ //not 4 parts  
            printf("0\n");
            continue;
        }
        int index_1 = 0, index_3 = 0;
        if( digits(arr[1]) && digits(arr[3])){
            index_1 = atoi(arr[1]);
            index_3 = atoi(arr[3]);
        }
        else{
            printf("0\n");
            continue;
        }
        if( arr[0][0] == '\0'||arr[1][0] == '\0' || arr[2][0] == '\0'||arr[3][0] == '\0' ) //there is vacant array
            end = 0;
        else if( strlen(arr[0]) != 1  || strlen(arr[2]) != 1 )      //arr[0] or arr[2]  isn't a letter
            end = 0;
        else if( arr[0][0] != 'A' && arr[0][0] != 'B' )             //arr[0] and arr[2] aren't correspondent. 
            end = 0; 
        else if( (arr[0][0] == 'A' && arr[2][0] != 'B') || (arr[0][0] == 'B' && arr[2][0] != 'C') )
            end = 0;
        else if( arr[0][0] =='A' && (index_1 >= a || index_3 >= b) )  //the index > the array
            end = 0;
        else if( arr[0][0] =='B' && (index_1 >= b || index_3 >= c) )  //the index > the array
            end = 0;
        printf("%d\n",end);
        if (arr[0][0] == 'A' && end == 1){
                A[index_1] = &(B[index_3]);
#ifdef DEBUG
                printf("A[%d] = %p, &B[%d] = %p\n",index_1, A[index_1], index_3, &B[index_3]);
                printf("*A[%d] = %p, B[%d] = %p\n", index_1, *A[index_1], index_3, B[index_3]);
#endif
        }
        if (arr[0][0] == 'B' && end == 1){
                B[index_1] = &(C[index_3]);
#ifdef DEBUG
                printf("B[%d] = %p, &C[%d] = %p\n",index_1, B[index_1], index_3, &C[index_3]);
                printf("*B[%d] = %p, C[%d] = %p\n", index_1, *B[index_1], index_3, C[index_3]);
#endif
        }
    }
    return ;
}
