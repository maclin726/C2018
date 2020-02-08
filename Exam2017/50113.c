#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int small,large;
    struct node *left,*mid,*right;
}Node;

Node *buildTree(Node *root, int data){
    if( root == NULL ){
        Node *current = (Node*)malloc(sizeof(Node));
        current->left = current->right = current->mid = NULL;
        current->large = data;
        current->small = (-1);
        return current;
    }
    else{
        if( root->small == (-1)  ){
            if( data > root->large ){
                root->small = root->large;
                root->large = data;
            }
            else
                root->small = data;
        }
        else if( data > root->large )
            root->right = buildTree(root->right, data);
        else if( data < root->large && data > root->small )
            root->mid = buildTree(root->mid, data);
        else if( data < root->small )
            root->left = buildTree(root->left, data);
    }
    return root;
}

Node *ConstructTree(int sequence[], int N){
    Node *root = NULL;
    for( int i = 0; i < N; i++ )
        root = buildTree(root, sequence[i]);
    return root;
}

#define MAXN 32768
int sequence[MAXN];
void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d %d\n", root->small, root->large);
    PrintTree(root->left);
    PrintTree(root->mid);
    PrintTree(root->right);
    return;
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}