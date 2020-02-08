#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>

typedef struct tree{
    char op;
    struct tree *left;
    struct tree *right;
    int value;
}Expression;

int operate(char op, int a, int b){
    switch(op){
        case '\0':  return a;
        case '+':   return a+b;
        case '-':   return a-b;
        case '*':   return a*b;
        case '/':   return a/b;
    }
}

char *balance(char *expression, int length){
    int value = 0;
    for( int i = 4; i < length; i++ ){
        if(expression[i] == '(')
            value++;
        else if(expression[i] == ')')
            value--;
        if( !value && isspace(expression[i]) )
            return &(expression[i]);
    }
    return NULL;
}

int compare(char *expression, char variable[][64], int value[], int value_count){
    int N = 0;
    while( !isspace(expression[N]) )
        N++;
    for( int i = 0; i < value_count; i++)
        if(strncmp(expression, variable[i], N) == 0)
            return value[i];
    return 0;
}

Expression *build(char *expression, int length, char variable[][64], int value[], int value_count){
    Expression *current = (Expression*)malloc(sizeof(Expression));
    assert(current != NULL);

    current->left = current->right = NULL;
    char *balancePoint = balance(expression, length);
    if( balancePoint == NULL ){
        current->op = '\0';
        if( isdigit(expression[0]) )
            current->value = atoi(expression);
        else
            current->value = compare(expression, variable, value, value_count);
    }
    else{
        current->op = expression[2];
        expression[length-1] = expression[length-2] = '\0';
        *balancePoint = '\0';
        current->left = build(&expression[4], balancePoint-(&expression[4]), variable, value, value_count);
        current->right = build(balancePoint+1, (length-3)-(balancePoint-expression), variable, value, value_count);
        current->value = operate(current->op, current->left->value, current->right->value);
    }
    return current;
}

int main(){
    char expression[1024] = {'\0'}, variable[64][64] = {'\0'};
    int value[64] = {0}, var_count = 0;

    fgets(expression, 1000, stdin);
    while( scanf("%s = %d", variable[var_count], &value[var_count]) != EOF )
        var_count++;
    Expression *root = build(expression, strlen(expression)-1, variable, value, var_count);
    printf("%d", root->value);
    return 0;
}