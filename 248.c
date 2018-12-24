#include<stdio.h>
int in_map( int r, int c ){
    return (r < 9 && r >= 0 && c < 9 && c >= 0);
}
int indexR(int block){
    return block / 9;
}
int indexC(int block){
    return block % 9;
}
int printSol(int solution[9][9]){
    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 9; j++)
            if(j != 8)
                printf("%d ", solution[i][j]);
            else
                printf("%d\n",solution[i][j]);
}
void adjust( int map[9][9], int block, int instruction){           /* instruction = (-1) means -, 1 means + */
    int dr[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    for( int i = 0; i < 9; i++ ){
        int nextR = indexR(block) + dr[i];
        int nextC = indexC(block) + dc[i];
        if( in_map(nextR, nextC) )
            map[nextR][nextC] += instruction;
    }
    return;
}
int mine( int map[9][9], int solution[9][9], int block ){
    if( block == 92 )
        return 1;
    int r = indexR(block-11), c = indexC(block-11);
    if( block >= 11 && map[r][c] != 0 )
        return 0;
    if( block > 80 ){
        if( mine(map, solution, block + 1) )
            return 1;
        return 0;
    }
    if( mine(map, solution, block + 1) )
        return 1;
    adjust(map, block, -1);
    if( mine(map, solution, block + 1 ) ){
        solution[indexR(block)][indexC(block)] = 1;
        return 1;
    }
    adjust(map, block, 1);
    return 0;
}
int main(){
    int map[9][9] = {0};
    int solution[9][9] = {0};
    for( int i = 0; i < 9; i++ )
        for(int j = 0; j < 9; j++)
         scanf("%d", &map[i][j]);
    if( mine( map, solution, 0 ) )
        printSol(solution);
    else
        printf("no solution\n");
}