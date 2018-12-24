#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

void print_path( struct node *root, int index, int path[] ){
    //printf("now index = %d\n", index);
    path[index] = root->data;
    if(root->left == NULL && root->right == NULL){
        for( int i = 0; i <= index; i++ )
            printf("%d ", path[i]);
        printf("\n");
        return;
    }
    if(root->left != NULL)
        print_path(root->left, index+1, path);
    if(root->right != NULL)
    print_path(root->right, index+1, path);
    return;
}

void print_all_paths(struct node *root){
    int path[1024];
    print_path( root, 0, path);
    return;
}
 
struct node *insert_bs_tree(struct node *root, int data)
{
    struct node *current;
    if (root == NULL)
    {
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}