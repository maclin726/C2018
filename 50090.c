#include <stdio.h>

#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

void count(int **p[]){
    int i,j,temp_num;
    int *location_rd[512],*temp_pointer;
    int count_rd[512]={0};
    int num_rd=0;
    for (i=0; p[i]!=NULL; i++){
        int *ptr = *p[i];
        int check = 0;
#ifdef DEBUG
        printf("the value of p[%d] is at %p\n",i, *p[i]);
#endif // DEBUG
        for( j = 0; j < num_rd; j++ ){
            if( ptr == location_rd[j]){
                count_rd[j]++;
                check = 1;
            }
        }
        if(check == 0){
            location_rd[num_rd] = ptr;
            count_rd[num_rd]++;
            num_rd++;
        }
    }
#ifdef DEBUG
    for (j=0; j < num_rd; j++){
        printf("count_rd[%d]=%d\n",j,count_rd[j]);
    }
#endif // DEBUG
    for (i = 0 ;i < num_rd; i++){
        for(j = num_rd-1; j > i; j--){
            if(count_rd[j] < count_rd[j-1]){
                temp_num = count_rd[j];
                count_rd[j] = count_rd[j-1];
                count_rd[j-1] = temp_num;
                temp_pointer = location_rd[j];
                location_rd[j] = location_rd[j-1];
                location_rd[j-1] = temp_pointer;
            }
        }
    }
    for (i = 0 ;i < num_rd; i++){
        for(j = num_rd-1; j > i; j--){
            if(count_rd[j] == count_rd[j-1] && *location_rd[j] < *location_rd[j-1]){
                temp_num = count_rd[j];
                count_rd[j] = count_rd[j-1];
                count_rd[j-1] = temp_num;
                temp_pointer = location_rd[j];
                location_rd[j] = location_rd[j-1];
                location_rd[j-1] = temp_pointer;
            }
        }
    }
    for(i=0; i<num_rd; i++){
        printf("%d %d\n",*location_rd[i],count_rd[i]);
    }
}

int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];

  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];

  count(ptrArray);

  return 0;
}
