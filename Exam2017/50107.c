#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    int height;
    int weight;
    double BMI;
    char name[64];
}student;
 
student Student[100000];
student *ptr[100000] = {NULL};
 
int compare(const void *data1, const void *data2){
    student *ptr1 = *(student**) data1;
    student *ptr2 = *(student**) data2;
    if( ptr1->BMI < ptr2->BMI )
        return -1;
    else if( ptr1->BMI > ptr2->BMI )
        return 1;
    else if( ptr1->weight < ptr2->weight )
        return -1;
    else if( ptr1->weight > ptr2->weight )
        return 1;
    else if( ptr1->height < ptr2->height )
        return -1;
    else if( ptr1->height > ptr2->height )
        return 1;
    else
        return strcmp( ptr1->name, ptr2->name ); 
}
 
int main(){
    int N;
    scanf("%d", &N);
    for( int i = 0; i < N; i++ ){
        scanf("%s%d%d", Student[i].name, &Student[i].height, &Student[i].weight);
        double Square = Student[i].height * Student[i].height;
        Student[i].BMI = Student[i].weight / Square * 10000;
        ptr[i] = &Student[i];
    }
    qsort( ptr, N, sizeof(student*), compare );
    for( int i = 0; i < N; i++ )
        printf("%s %d %d\n", ptr[i]->name, ptr[i]->height, ptr[i]->weight);
    return 0;
}
