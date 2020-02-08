#include<stdio.h>
#include<stdlib.h>
#include "node.h"

struct node *location[1000000];

struct node *getNode(struct node *head, unsigned int i){
    int count = 1;
    struct node *ptr = head;
    location[0] = head;
    while( ptr -> next != NULL ){
        ptr = ptr->next;
        location[count] = ptr;
        count++;
    }
    if( i >= count )
        return NULL;
    return location[count-1-i];
}
