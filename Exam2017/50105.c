#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXN 16384
 
int T[MAXN];

typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;

int findBalanceFromTo(int T[], int from, int to){
    if( to - from  < 2 )
        return (-1);
    long long int mass = 0, torque = 0;
    for( int i = from; i <= to; i++ ){
        mass += T[i];
        torque += (long long)(T[i] * (i-from));
    }
    return ( torque % mass == 0 )? (torque / mass + from): (-1);
}

Node *linked_list(int *T, int from, int to){
    if( from > to )
        return NULL;
    Node *current = (Node*)malloc(sizeof(Node));
    assert(current != NULL);
    current->value = T[to];
    current->left = linked_list(T, from, to-1);
    current->right = NULL;
    return current;
}

Node *insert_tree(int *T, int from, int to){
    if( from > to )
        return NULL;
    Node *current = (Node*)malloc(sizeof(Node));
    assert(current != NULL);

    int pivot = findBalanceFromTo(T, from, to);

    if( pivot == (-1) ){
        current->value = T[to];
        current->left = linked_list(T, from, to-1);
        current->right = NULL;
    }
    else{
        current->value = T[pivot];
        current->left = insert_tree(T, from, pivot-1);
        current->right = insert_tree(T, pivot+1, to); 
    }
    return current;
}
 
Node *ConstructTree(int T[], int N){
    Node *root = insert_tree(T, 0, N-1);
    return root;
}
 
void PrintTree( Node *root ){
    if (root == NULL)
        return;
 
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree( T, N );
 
    PrintTree( tree );
    return 0;
}