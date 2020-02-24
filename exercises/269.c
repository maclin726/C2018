#include <stdio.h>
#include <stdlib.h>
typedef struct mem{
    int addr;
    int len;
    struct mem *next;
}Memory;

void initMemory(Memory *memory, int length){
    memory->addr = 0;
    memory->len = length;
    memory->next = NULL;
    return;
}

void printMemory(Memory *memory){
    Memory *curptr = memory;
    printf("==========\n");
    while( curptr != NULL && memory->len != 0 ){
        printf("start %d, length %d\n", curptr->addr, curptr->len);
        curptr = curptr->next;
    }
    return;
}

void allocateMemory(Memory *memory, int start, int length){
    Memory *prev_ptr = NULL;
    while( memory->addr + memory->len <= start ){
        prev_ptr = memory;
        memory = memory->next;
    }
    int prev = start - (memory->addr), next = memory->addr + memory->len - (start + length);
    if( prev == 0 && next == 0 ){
        if( prev_ptr == NULL ){
            prev_ptr = memory;
            if( memory->next != NULL )
                *memory = *(memory->next);
            else
                memory->len = 0;
        }
        else
            prev_ptr->next = memory->next;
    }
    else if( prev == 0 && next != 0 ){
        memory->addr += length;
        memory->len -= length;
    }
    else if( prev != 0 && next == 0 ){
        memory->len -= length;
    }
    else{
        Memory *new = (Memory *)malloc(sizeof(Memory));
        new->next = memory->next;
        new->len = next;
        new->addr = start + length;
        memory->next = new;
        memory->len = prev;
    }
    return;
}

void freeMemory(Memory *memory, int start, int length){
    return;
}