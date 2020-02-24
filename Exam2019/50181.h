#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* rightPtr;
    struct node* downPtr;
}NODE;
int calArea(NODE* head){
    int sum = 0;
    NODE *PT1 = head->rightPtr, *PT2 = head->downPtr; 
    int pt1 = 0, pt2 = 1;
    while( PT1 != PT2 ){
        while( PT2->rightPtr == NULL && PT2->downPtr != NULL ){
            pt2++;
            PT2 = PT2->downPtr;
        }
        if( PT2->rightPtr != NULL )  PT2 = PT2->rightPtr;
        sum += (pt2 - pt1);
        while( PT1->rightPtr == NULL && PT1->downPtr != NULL ){
            pt1++;
            PT1 = PT1->downPtr;
        }
        if( PT1->rightPtr != NULL )  PT1 = PT1->rightPtr;
    }
    return sum;
}