#include<stdio.h>
void game_of_cell(int grid[50][50],int outcome[50][50],int N){
    int i;
    for (i = 0; i < N; i++){
        int count[50][50][3]={0};
        int j,k;
        for (j = 1; j < 50; j++)       //check up
            for(k = 0; k < 50; k++)
                count[j][k][ grid[j-1][k] ]++;
        for (j = 0; j < 49; j++)       //check down
            for(k = 0; k < 50; k++)
                count[j][k][ grid[j+1][k] ]++;
        for (j = 1; j < 50; j++)       //check left
            for(k = 0; k < 50; k++)
                count[k][j][ grid[k][j-1] ]++;
        for (j = 0; j < 49; j++)       //check right
            for(k = 0; k < 50; k++)
                count[k][j][ grid[k][j+1] ]++;
        for (j = 1; j < 50; j++)       //check up left
            for(k = 1; k < 50; k++)
                count[j][k][ grid[j-1][k-1] ]++;
        for (j = 1; j < 50; j++)       //check up right
            for(k = 0; k < 49; k++)
                count[j][k][ grid[j-1][k+1] ]++;
        for (j = 0; j < 49; j++)       //check down left
            for(k = 1; k < 50; k++)
                count[j][k][ grid[j+1][k-1] ]++;
        for (j = 0; j < 49; j++)       //check down right
            for(k = 0; k < 49; k++)
                count[j][k][ grid[j+1][k+1] ]++;
        for (j = 0; j < 50; j++){
            for(k = 0; k < 50; k++){
                if(grid[j][k] == 2){
                    if(count[j][k][2] < 2)
                        grid[j][k] = 0;
                    else if(count[j][k][2] > 3)
                        grid[j][k] = 1;
                }
                else if (grid[j][k] == 0 && count[j][k][2] == 3)
                    grid[j][k] = 2;
                else if (grid[j][k] == 1 && count[j][k][2] == 2)
                    grid[j][k] = 2;
            }
        }
    }
    for(int j = 0; j < 50; j++){
        for(int k = 0; k < 50; k++)
            outcome[j][k] = grid[j][k];
    }
}

int main()
{
    int grid[50][50]={0},outcome[50][50]={0},N;
    scanf("%d",&N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&grid[i][j]);
    game_of_cell(grid,outcome,N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            printf("%d%c",outcome[i][j]," \n"[j==49]);
    return 0;
}
