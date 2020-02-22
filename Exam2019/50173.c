#include <stdio.h>

#include<stdint.h>
void printMatrix(uint64_t *matrix){
    printf("%llu\n", *matrix);
    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ )
          printf("%ld", (*matrix >> (i*8+j))%2);
        printf("\n");
    }
}
void rotateMatrix(uint64_t *matrix){
    uint64_t old = *matrix;
    for( int i = 0; i < 8; i++ ){
      for( int j = 0; j < 8; j++ ){
        if( old & ((uint64_t)1 << (i*8+j)) )
          (*matrix) |= ((uint64_t)1 << (j*8+(7-i)));
        else
          (*matrix) &= (UINTMAX_MAX ^((uint64_t)1 << (j*8+(7-i))));
      }
    }
    return;
}
void transposeMatrix(uint64_t *matrix){
    uint64_t old = *matrix;
      for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
          if( old & ((uint64_t)1 << (i*8+j)) )
            (*matrix) |= ((uint64_t)1 << (j*8+i));
          else
            (*matrix) &= (UINTMAX_MAX ^ ((uint64_t)1 << (j*8+i)));
        }
      }
      return;
}
 
int main() {
   uint64_t num;
   char operation;
   scanf("%lu", &num);
   while (1) {
       scanf("%c", &operation);
       if (operation == 'p') {
           printMatrix(&num);
           break;
       } else if (operation == 'r')
           rotateMatrix(&num);
       else if (operation == 't')
           transposeMatrix(&num);
   }
   return 0;
}