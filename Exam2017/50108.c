#include <stdio.h>
#include <stdlib.h>
 
#define MAXN 16384
 
#ifndef MAXLENGTH
    #define MAXLENGTH 0
#endif
 
typedef struct node{
    int value;
    struct node *left, *right;
} Node;
 
int compare(const void *data1, const void *data2){
    int *ptr1 = *(int **)data1;
    int *ptr2 = *(int **)data2;
    if( *ptr1 < *ptr2 )
        return 1;
    else if( *ptr1 > *ptr2 )
        return -1;
}
 
int *findNumber(int *sequence, int start, int end){
    int *ptr[MAXN] = {NULL};
    for( int i = 0; i < end - start + 1; i++ )
        ptr[i] = &sequence[start+i];
    qsort( ptr, end-start+1, sizeof(int*), compare);
    return ptr[MAXLENGTH-1];
}
 
Node *ConstructFromTo(int sequence[], int start, int end){
    if( end < start )
        return NULL;
    if( (end - start + 1) < (MAXLENGTH)  ){
        Node *current = (Node *)malloc(sizeof(Node*));
        current->value = sequence[end];
        current->right = NULL;
        current->left = ConstructFromTo(sequence, start, end-1);
        return current;
    }
    int *balance = findNumber( sequence, start, end);
    int balanceIndex = balance-sequence;
    Node *current = (Node *)malloc(sizeof(Node*));
    current->value = *balance;
    current->left = ConstructFromTo(sequence, start, balanceIndex-1);
    current->right = ConstructFromTo(sequence, balanceIndex+1, end);
    return current;
}
 
Node *ConstructTree(int sequence[], int N){
    Node *head = ConstructFromTo(sequence, 0, N-1);
    return head;
}
