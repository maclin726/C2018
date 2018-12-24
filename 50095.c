#include<stdio.h>
#include<string.h>
    char letter[10000000];
int main(){
    char **LINE[1024] = {NULL}, *WORD[16384] = {NULL};
    int N;
    scanf("%d", &N);
    LINE[0] = &WORD[0];
    WORD[0] = &letter[0];
    int word_count[1024] = {0};
    int w = 0, l = 0;
    char c = '\0';
    do{
        if (c == '\n'){
            if( l == N-1){
                word_count[N] = w;
                break;
            }
            l++;
            LINE[l] = &WORD[w];
            word_count[l] = w;
        }
        scanf("%s", WORD[w]);
        WORD[w][strlen(WORD[w])] = '\0';
#ifdef DEBUG
        printf("%s ", WORD[w]);
#endif
        w++;
        WORD[w] = &( WORD[w-1][strlen(WORD[w-1])+1] );
    }while( scanf("%c", &c) != EOF );
    int M, l1, w1, l2, w2;
    scanf("%d", &M);
    int m;
    for( m = 0; m < M; m++ ){
        scanf("%d%d%d%d", &l1, &w1, &l2, &w2);
        char *temp = LINE[l1][w1];
        LINE[l1][w1] = (LINE[l2][w2]);
        LINE[l2][w2] = temp;
    }
    for( l = 0; l < N; l++ ){
        int i;
        for( i = word_count[l] ; i < word_count[l+1]; i++  ){
            if(i != word_count[l+1] - 1)
                printf("%s ", WORD[i]);
            else
                printf("%s", WORD[i]);
        }
        printf("\n");
    }
return 0;
}