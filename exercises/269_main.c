#include "269.h"
#include <stdlib.h>
#include <stdio.h>
int main() {
    Memory myMemory[100];
    char ins;
    int n, start, length;
    while( scanf("%c", &ins) != EOF ){
        if( ins == 'I' ){
            scanf("%d %d\n", &n, &length);
            initMemory(&myMemory[n], length);
        }
        else if( ins == 'A' ){
            scanf("%d %d %d\n", &n, &start, &length);
            allocateMemory(&myMemory[n], start, length);
        }
        else if( ins == 'P' ){
            scanf("%d\n", &n);
            printMemory(&myMemory[n]);
        }
        else
            break;
    }
    return 0;
}