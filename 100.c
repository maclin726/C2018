#include <stdio.h>
#include <assert.h>

void snake(const int *ptr_array[100][100], int m){
    int i,j,k;
    int *iptr[10000];
    int *temp;
    for (i=0 ;i<m; i++){
        if( i % 2 == 0)
            for(j=0; j<m; j++)
                iptr[i*m + j] = ptr_array[i][j];
        else
            for(j=m-1; j>=0; j--)
                iptr[i*m - (j-(m-1))] = ptr_array[i][j];
    }
    for (i=0; i<m*m; i++)
        for ( j=(m*m-1) ; j>i; j--)
            if( *iptr[j] < *iptr[j-1] ){
                temp = iptr[j];
                iptr[j] = iptr[j-1];
                iptr[j-1] = temp;
            }
    for (i=0 ;i<m; i++){
        if( i % 2 == 0)
            for(j=0; j<m; j++)
                ptr_array[i][j] = iptr[i*m + j];
        else
            for(j=m-1; j>=0; j--)
                 ptr_array[i][j] = iptr[i*m - (j-(m-1))];
    }
}

int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;

  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }

  snake(ptr_array, m);

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }

  return 0;
}
