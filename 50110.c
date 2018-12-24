#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *left, *right;
} Node;
 
Node *FlipTree(Node *root){
    if( root == NULL )
        return NULL;
    Node *current = (Node *)malloc(sizeof(Node));
    current->n = root->n;
    current->left = FlipTree(root->right);
    current->right = FlipTree(root->left);
    return current;
}
int isIdentical(Node *tree1, Node *tree2){
    if( tree1 == NULL && tree2 == NULL )
        return 1;
    else if( tree1->n != tree2->n )
        return 0;
    else
        return( isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right) );
}

int countDepth(Node *root, int level, int *number){
    if( root == NULL )
        return 0;
    if( root->left == NULL && root->right == NULL ){
        *number = *number + 1;
        return level;
    }
    return countDepth(root->left, level+1, number) + countDepth(root->right, level+1, number);
}

void depthAvg(Node *root){
    int number = 0;
    int sum = countDepth(root, 0, &number);
    printf("%d/%d\n",sum, number);
    return;
}
 
void printTree(Node *root) {
  if (root == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d\n", root->n);
  if (root->left == NULL && root->right == NULL) return;
  printTree(root->left);
  printTree(root->right);
}
 
int main() {
  Node tree1[9];
 
  for(int i = 0; i < 9; i++){
    tree1[i].n = i;
    tree1[i].left = tree1[i].right = NULL;
  }
 
  tree1[0].left = &tree1[1];
  tree1[0].right = &tree1[2];
  tree1[1].left = &tree1[3];
  tree1[1].right = &tree1[4];
  tree1[2].left = &tree1[5];
  tree1[5].left = &tree1[6];
  tree1[6].left = &tree1[7];
  tree1[7].left = &tree1[8];
 
  depthAvg(&tree1[0]);
 
  return 0;
}