#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
 
typedef struct ta_set{
    unsigned long long int x;
}ta_Set;
 
void initializeSet(ta_Set* set, int numberOfElement){
    set->x = 0;
    return;
}
void printSet(ta_Set set){
    for( int i = 0; i < 64; i++ ){
        if( ((long long)1 << i & set.x) != 0 )
            printf("%d ", i+1);
    }
    return;
}

bool intersect(ta_Set set1, ta_Set set2){
    //printSet(set1);
    //printSet(set2);
    if ((set1.x & set2.x) != 0)
        return 1;
    else
        return 0;
}
void addElement(ta_Set* set, int element){
    (set->x) |= ((long long)1 << (element-1));
    return;
}
void removeElement(ta_Set* set, int element){
    (set->x) &= ~(((long long)1) << (element-1));
    return;
}
