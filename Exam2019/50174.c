#include <stdio.h>
#include <inttypes.h> 
#define N 63

#include <stdint.h>
void BubbleSort(uint64_t input, uint64_t output[63]){
    for( int i = 0; i < 63; i++ ){
        for( int j = 63; j > i; j-- ){
            if( (input & ((uint64_t)1 << j)) && (!(input & ((uint64_t)1 << (j-1)))) )
                input = input - ((uint64_t)1 << j) + ((uint64_t)1 << (j-1));
        }
        output[i] = input;
    }
    return;
}

int main(){
    uint64_t input;
    uint64_t output[N];
 
    scanf("%I64lu", &input);
    BubbleSort(input, output);
    for(int i = 0; i < N; i++)
        printf("%" PRIx64 "\n", output[i]);
    return 0;
}