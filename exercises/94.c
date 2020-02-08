#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}Tree;

void HRHL(Tree *root);
void HLHR(Tree *root);

int balanceComma(char *input, int from, int to){             //return the index of balance comma ok
    int value = 0;
    for( int i = from; i < to; i++ ){
        if( input[i] == '(' )
            value++;
        else if( input[i] == ')' )
            value--;
        
        if( input[i] != ',' )
            continue;
        if(value == 1)
            return i;
    }
    return (-1);
}

int parenthesesValue(char *input, int from, int to){          //get the sum of the numbers in the parentheses ok
    int sum = 0, number = 0;
    for( int i = from; i <= to; i++ ){
        if( isdigit(input[i]) ){
            number *= 10;
            number += (input[i] - '0');
        }
        else{
            sum += number;
            number = 0;
        }
    }
    sum += number;
    return sum;
}

Tree *insertBsTree(char *input, int from, int to){
    int length = strlen(input);
    int balancePoint = balanceComma(input, from, to);
    Tree *current = (Tree*)malloc(sizeof(Tree));
    current -> data = parenthesesValue(input, from, to);
    if( balancePoint != (-1) ){
        current -> left = insertBsTree(input, from+1, balancePoint-1);
        current -> right = insertBsTree(input, balancePoint+1, to-1);
    }
    else{
        current -> left = NULL;
        current -> right = NULL;
    }
    return current;
}

void HRHL(Tree *root){
    if(root == NULL)
        return;
    printf("%d\n", root->data);
    HLHR(root->right);
    printf("%d\n", root->data);
    HLHR(root->left);
    return;
}

void HLHR(Tree *root){
    if(root == NULL)
        return;
    printf("%d\n", root->data);
    HRHL(root->left);
    printf("%d\n", root->data);
    HRHL(root->right);
    return;
}

int main(){
    char input[4096];
    scanf("%s", input);
    int length = strlen(input);
    Tree *root = insertBsTree(input, 0, length-1);
    HLHR(root);
    return 0;
}