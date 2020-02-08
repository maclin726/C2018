#include <stdio.h>
void prepare_array(int buffer[], int *array[], int row, int column[]){
    int i,k=0;
    int j;
    int *ptr,*iptr = buffer;
    for (i=0; i < row; i++){
        array[i] = iptr;
        iptr+=column[i];
    }
}

int main() {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    int i,j;
    prepare_array(buffer, array, row, column);
    for (i = 0; i < 4; i++)
     for (j = 0; j < column[i]; j++)
       array[i][j] = i * 100 + j;
    return 0;
}
