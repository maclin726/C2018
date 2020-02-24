#include <stdlib.h>
typedef struct Node
{
          int val;
          struct Node *left, *right;
}Node;
int Nodecnt(Node *list){
    if( list == NULL )
        return 0;
    int cnt = 1;
    while( list->left != NULL ){
        cnt++;
        list = list->left;
    }
    return cnt;
}
Node* BuildTree(Node* list1, Node* list2){
    int list1cnt = Nodecnt(list1), list2cnt = Nodecnt(list2);
    if( list1 == NULL && list2 == NULL )
        return NULL;
    else if( list1 == NULL )
        return list2;
    else if( list2 == NULL )
        return list1;
    else{
        Node *head;
        if( list1->val < list2->val ){
            head = list1;
            list1 = list1->left;
            list1cnt--;
        }
        else{
            head = list2;
            list2 = list2->left;
            list2cnt--;
        }
        Node *list1_first = list1, *list2_first = list2;
        for( int i = 1; i < (list1cnt+1)/2; i++ )
            list1 = list1->left;
        for( int i = 1; i < (list2cnt+1)/2; i++ )
            list2 = list2->left;
        Node *list1_sec, *list2_sec;
        if( list1 == NULL )
            list1_sec = NULL;
        else
            list1_sec = list1->left, list1->left = NULL;
        if( list2 == NULL )
            list2_sec = NULL;
        else
            list2_sec = list2->left, list2->left = NULL;
        /*if( list1_first != NULL )
            printf("list1_first: %d\n", list1_first->val);
        if( list2_first != NULL )
            printf("list2_first: %d\n", list2_first->val);
        if( list1_sec != NULL )
            printf("list1_sec: %d\n", list1_sec->val);
        if( list2_sec != NULL )
            printf("list2_sec: %d\n", list2_sec->val);*/
        head->left = BuildTree(list1_first, list2_first);
        head->right = BuildTree(list1_sec, list2_sec);
        return head;
    }
}