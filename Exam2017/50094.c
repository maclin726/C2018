#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    int T, map[26][26] = {0};
    scanf("%d",&T);
    char Word[128] = {'\0'};
    while( scanf("%s", Word)  != EOF ){
        int i;
        for( i = 1; i < strlen(Word); i++ )
            map[ Word[i-1] - 'a' ][ Word[i] - 'a' ]++;
    }
    int i ,j, max = 0, start, end;
    for( i = 0; i < 26; i++){
        for(j = 0; j < 26; j++){
            printf("%d",map[i][j]);
            if(j != 25)
                printf(" ");
            if( map[i][j] > max ){
                start = i;
                end = j;
                max = map[i][j];
            }
        }
        printf("\n");
    }
    
    char newWord[32] = {'\0'};
    int record[26] = {0};
    newWord[0] = 'a' + start;
    newWord[1] = 'a' + end;
    record[start] = 1;
    int index = 1;
    while(1){
        start = end;
        record[start] = 1;
        index++;
        int check = 0;
        int frequent = T;                   //最頻繁出現的字
        for( i = 0; i < 26; i++ )
            if( map[start][i] > frequent && record[i] == 0 ){
                frequent = map[start][i];
                end = i;
                newWord[index] = 'a' + i;
                check = 1;
            }
        if( !check )
            break;
    }
    printf("%s", newWord);
    return 0;
}

#ifdef NOTE
1.注意變數的設定值 特別是start和end
2.規則是前兩個一定要印出來，之後再根據不能重複和高於threshold值進行迭代
3.可以用while(1)...的寫法，把迴圈跳出條件設定在loop內，再搭配break使用
#endif