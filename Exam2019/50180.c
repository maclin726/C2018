#include <stdio.h>

int main(){
    int N;
    __int32_t A[32][32], B[32][32];
    __int64_t C[32][32] = {0};
    char A_prefix[32], B_prefix[32], C_prefix[32];
    scanf("%d%s%s%s", &N, A_prefix, B_prefix, C_prefix);
    for( int r = 1; r <= N; r++ ){
        char A_name[32], B_name[32];
        sprintf(A_name, "%s%d", A_prefix, r);
        sprintf(B_name, "%s%d", B_prefix, r);
        FILE *Ain = fopen(A_name, "r"), *Bin = fopen(B_name, "r");
        for( int c = 0; c <= N; c++ ){
            fread(&A[r-1][c], 1, sizeof(__int32_t), Ain);
            fread(&B[r-1][c], 1, sizeof(__int32_t), Bin);
        }
        fclose(Ain), fclose(Bin);
    }
    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            for( int k = 0; k < N; k++ )
                C[i][j] += (long long int) A[i][k] * (long long int)B[k][j];
        }
    }
    for( int r = 1; r <= N; r++ ){
        char C_name[32];
        sprintf(C_name, "%s%d", C_prefix, r);
        FILE *C_out = fopen(C_name, "wb");
        for( int c = 0; c < N; c++ )
            fwrite(&C[r-1][c], 1, sizeof(__int64_t), C_out);
        fclose(C_out);
    }
    return 0;
}