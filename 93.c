#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#define MAXHEAP 100 

struct Heap{
    int ary[MAXHEAP];
    int num;
};
void initialize(struct Heap *heap){
    heap->num = 0;
    return;
}
int isFull(struct Heap *heap){
    return heap->num == 100? 1:0;
}
int isEmpty(struct Heap *heap){
    return heap->num == 0? 1:0;
}
int removeMin(struct Heap *heap){
    if( !isEmpty(heap) ){
        int min = heap->ary[heap->num-1];
        heap->num--;
        return min;
    }
}
void add(struct Heap *heap, int i){
    if( !isFull(heap) ){
        int min = 1;
        for( int index = 0; index < heap->num; index++ )
            if( i > heap->ary[index] ){
                for( int j = (heap->num)-1; j >= index; j-- )
                    heap->ary[j+1] = heap->ary[j];
                heap->ary[index] = i;
                    min = 0;
                break;
            }
        if( min )
            heap->ary[heap->num] = i;
        heap->num++;
    }
    return;
}

int main(){
    struct Heap myHeap[10];
    int n;
    while(scanf("%d", &n) == 1){
        int instr;
        int min, i, ret;
        int r;
        r = scanf("%d", &instr);
        assert(r == 1);
        switch(instr){
            case 0:
                initialize(&myHeap[n]);
                break;
            case 1:
                assert(!isEmpty(&myHeap[n]));
                min = removeMin(&myHeap[n]);
                printf("min = %d\n", min);
                break;
            case 2:
                assert(!isFull(&myHeap[n]));
                r = scanf("%d", &i);
                assert(r == 1);
                add(&myHeap[n], i);
                break;
            case 3:
                ret = isFull(&myHeap[n]);
                if(ret)
                    printf("Full\n");
                else
                    printf("Not Full\n");
                break;
            case 4:
                ret = isEmpty(&myHeap[n]);
                if(ret)
                    printf("Empty\n");
                else
                    printf("Not Empty\n");
                break;
        }
    }
    return 0;
}
