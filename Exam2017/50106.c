#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024
 
typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
 
Node *insertBSTree(char name[16], int data, Node *root, int index){      //0 means height, 1 means weight
    if( root == NULL ){
        Node *current = (Node *)malloc(sizeof(Node));
        current->left = current->right = NULL;
        strcpy(current->name, name);
        if( !index )
            current->height = data;
        else
            current->weight = data;
        return current;
    }
    if( !index ){
        if( root->height > data )
            root->left = insertBSTree(name, data, root->left, index);
        else
            root->right = insertBSTree(name, data, root->right, index);
    }
    else{
        if( root->weight > data )
            root->left = insertBSTree(name, data, root->left, index);
        else
            root->right = insertBSTree(name, data, root->right, index);
    }
    return root;
}
 
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
    Node *root = NULL;
    #ifdef HEIGHT
        for( int i = 0; i < N; i++ )
            root = insertBSTree(name[i], height[i], root, 0);
    #endif
    #ifdef WEIGHT
        for( int i = 0; i < N; i++ )
            root = insertBSTree(name[i], weight[i], root, 1);
    #endif
    return root;
}
