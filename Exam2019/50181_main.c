#include<stdio.h>
#include<stdlib.h>
#include"50181.h"
 
NODE* initList(NODE* pos, int len){
    NODE* tail = pos;
    char direction;
    for(int i = 0; i < len-1; i++){
        scanf("%c", &direction);
        getchar();
        NODE* pNew = (NODE*) malloc(sizeof(NODE));
        pNew->downPtr = NULL;
        pNew->rightPtr = NULL;
        if(direction == 'r'){
            pos->rightPtr = pNew;
            pos = pos->rightPtr;
        }
        else{
            pos->downPtr = pNew;
            pos = pos->downPtr;
        }
        if(i == len-3)
            tail = pos;
    }
    return tail;
}
 
int main(){
    int len;
 
    NODE* head = (NODE*) malloc(sizeof(NODE));
 
    scanf("%d\n", &len);
    getchar();
    NODE *pos;
    char direction;
    scanf("%c", &direction);
    head->rightPtr = (NODE*) malloc(sizeof(NODE));
    pos = head->rightPtr;
    pos->downPtr = NULL;
    pos->rightPtr = NULL;
    NODE* tailR = initList(pos, len);
 
    head->downPtr = (NODE*) malloc(sizeof(NODE));
    pos = head->downPtr;
    pos->downPtr =NULL;
    pos->rightPtr = NULL;
    scanf("%c", &direction);
    getchar();
    NODE* tailD = initList(pos, len);
    free(tailD->rightPtr);
    tailD->rightPtr = tailR->downPtr;
 
    printf("%d", calArea(head));
}