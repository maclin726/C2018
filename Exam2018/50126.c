#include <stdio.h>
int count(int *a[]){
    int i = 0;
    while( a[i] != NULL )
        i++;
    return i;
}
void merge(int A[], int B[], int* a[], int* b[]){
    int numA = count(a) + 1, numB = count(b) + 1;
    int indexA = 0, indexB = 0;
    int flag;                               /* 0 means A index, 1 means B index*/
    if( A[0] > B[0]){
        indexB++;
        flag = 0;
    }
    else{
        flag = 1;
        indexA++ ;
    }
    while( indexA != numA && indexB != numB ){
        if( A[indexA] > B[indexB] ){
            if(flag)
                b[indexB-1] = &B[indexB];
            else
                a[indexA-1] = &B[indexB];
            flag = 1;
            indexB++;
        }
        else{
            if(flag)
                b[indexB-1] = &A[indexA];
            else
                a[indexA-1] = &A[indexA];
            flag = 0;
            indexA++;
        }
    }
    if(indexA == numA)
        a[indexA-1] = &B[indexB];
    else
        b[indexB-1] = &A[indexA];
    return;
}