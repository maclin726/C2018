#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    char c;
    int num_of_char_in_node;
    int num_of_char_in_subtree;
} TreeNode;

// insert [num_of_char] [c]'s so that the first of them is the pos-th character (1-based) 
TreeNode *insert(TreeNode *root, char c, int num_of_char, int pos){
    if (root == NULL) {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->left = root->right = NULL;
        root->c = c;
        root->num_of_char_in_node = num_of_char;
        root->num_of_char_in_subtree = num_of_char;
        return root;
    }

    int left_threshold, right_threshold; // the right(left) most position that we can insert into left(right)-subtree.
    left_threshold = (root->left == NULL)? 1: root->left->num_of_char_in_subtree + 1;
    right_threshold = (root->left == NULL)? root->num_of_char_in_node + 1: root->left->num_of_char_in_subtree + root->num_of_char_in_node + 1;

    if (pos <= left_threshold) {
        root->left = insert(root->left, c, num_of_char, pos);
        root->num_of_char_in_subtree += num_of_char;
    }
    else if (pos >= right_threshold) {
        root->right = insert(root->right, c, num_of_char, pos - right_threshold + 1);
        root->num_of_char_in_subtree += num_of_char;
    }
    else {
        int pos_in_node = pos - left_threshold;
        TreeNode *new_left = (TreeNode *)malloc(sizeof(TreeNode));
        TreeNode *new_right = (TreeNode *)malloc(sizeof(TreeNode));
        new_left->left = root->left;
        new_left->right = NULL;
        new_left->c = root->c;
        new_left->num_of_char_in_node = pos_in_node;
        if (root->left != NULL)
            new_left->num_of_char_in_subtree = new_left->left->num_of_char_in_subtree + new_left->num_of_char_in_node;
        else
            new_left->num_of_char_in_subtree = new_left->num_of_char_in_node;

        new_right->right = root->right;
        new_right->left = NULL;
        new_right->c = root->c;
        new_right->num_of_char_in_node = root->num_of_char_in_node - pos_in_node;
        if (root->right != NULL)
            new_right->num_of_char_in_subtree = new_right->right->num_of_char_in_subtree + new_right->num_of_char_in_node;
        else
            new_right->num_of_char_in_subtree = new_right->num_of_char_in_node;

        root->left = new_left;
        root->right = new_right;
        root->c = c;
        root->num_of_char_in_node = num_of_char;
        root->num_of_char_in_subtree =  num_of_char;
        if (root->left != NULL)
            root->num_of_char_in_subtree += root->left->num_of_char_in_subtree;
        if (root->right != NULL)
            root->num_of_char_in_subtree += root->right->num_of_char_in_subtree;
    }
    return root;
}

void traverse_tree(TreeNode *root, char *cur_char, int *cur_char_count) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        traverse_tree(root->left, cur_char, cur_char_count);
    }
    
    if ((*cur_char) == root->c) {
        (*cur_char_count) += root->num_of_char_in_node;
    }
    else {
        if ((*cur_char_count) > 0)
            printf("%c %d ", (*cur_char), (*cur_char_count));
        (*cur_char) = root->c;
        (*cur_char_count) = root->num_of_char_in_node;
    }

    if (root->right != NULL) {
        traverse_tree(root->right, cur_char, cur_char_count);
    }
    return;
}

void print(TreeNode *root){
    char cur_char;
    int cur_char_count = 0;
    traverse_tree(root, &cur_char, &cur_char_count);
    if (cur_char_count > 0)
        printf("%c %d ", cur_char, cur_char_count);
    printf("$\n");
    return;
}

int main(){
    char instruction_type[16], insert_location[16];
    char c;
    int num_of_char;

    TreeNode *word_root = NULL; 

    while (scanf("%s", instruction_type) != EOF) {
        if (strcmp(instruction_type, "insert") == 0) {
            scanf("%s %c %d", insert_location, &c, &num_of_char);
            if (strcmp(insert_location, "left") == 0) {
                word_root = insert(word_root, c, num_of_char, 1);
            }
            else if (strcmp(insert_location, "right") == 0) {
                if (word_root == NULL)
                    word_root = insert(word_root, c, num_of_char, 1);
                else
                    word_root = insert(word_root, c, num_of_char, word_root->num_of_char_in_subtree+1);
            }
            else {
                int k = atoi(insert_location);
                word_root = insert(word_root, c, num_of_char, k);
            }
        }
        else {
            print(word_root);
        }
    }
    return 0;
}