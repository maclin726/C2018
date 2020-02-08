#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2){
    if( root1 == NULL || root2 == NULL )
        return NULL;
    else{
        Node *current = (Node*)malloc(sizeof(Node));
        current->val = root1->val * root2->val;
        current->left = treeAND(root1->left, root2->left);
        current->right = treeAND(root1->right, root2->right);
        return current;
    }
}
Node *treeOR(Node *root1, Node *root2){
    if( root1 == NULL && root2 == NULL )
        return NULL;
    else{
        Node *current = (Node*)malloc(sizeof(Node));
        int a, b;
        a = root1 == NULL? 0: root1->val;
        b = root2 == NULL? 0: root2->val;
        current->val = a+b;
        if( root1 == NULL ){
            current->left = treeOR(NULL, root2->left);
            current->right = treeOR(NULL, root2->right);
        }
        else if(root2 == NULL){
            current->left = treeOR(root1->left, NULL);
            current->right = treeOR(root1->right, NULL);
        }
        else{
            current->left = treeOR(root1->left, root2->left);
            current->right = treeOR(root1->right, root2->right);
        }
        return current;
    }
}
 
void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
 
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
 
Node *insertBST(Node *root, int val) {
    if (root == NULL) {
        root = (Node *) malloc(sizeof(Node));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}
 
int main() {
    int op, n1, n2, val;
    scanf("%d%d%d", &op, &n1, &n2);
    Node *tree1 = NULL;
    Node *tree2 = NULL;
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &val);
        tree1 = insertBST(tree1, val);
    }
    for (int i = 0; i < n2; ++i) {
        scanf("%d", &val);
        tree2 = insertBST(tree2, val);
    }
 
    Node *tree = (op) ? treeAND(tree1, tree2) : treeOR(tree1, tree2);
 
    preorder(tree);
    printf("\n");
    inorder(tree);
    printf("\n");
 
    return 0;
}