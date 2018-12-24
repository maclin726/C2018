#include<stdio.h>
int evaluate_f(int *iptr[], int n, int *index){
    int i;
    int *ptr = iptr[0];
    for (i=1; i<n ;i++){
        int x,y;
        x=(*ptr);
        y=*(ptr+1);
#ifdef  DEBUG
        printf("x=%d y=%d\n",x,y);
        printf("%d\n", 4*x-6*y);
#endif // DEBUG
        if( 4*(*iptr[i])-6*( *(iptr[i]+1) ) > 4*x-6*y ){
            ptr = iptr[i];
            *index = i;
        }
    }
    return 4*(*ptr)-6*( *(ptr+1) );
}

int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}
