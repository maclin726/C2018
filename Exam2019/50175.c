#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxL 1000

typedef struct Submission
{
    int subID;
    int studentID;
    char outputs[10][maxL];   
}Submission;

#define MAXSTU 100
int compare(const void *ptr1, const void *ptr2){
    Submission *a = (Submission *)ptr1, *b = (Submission *)ptr2;
    return (a->subID > b->subID);
}

void grading(char answer[10][maxL], Submission* sub, int num_of_submission){
    int sub_cnt[MAXSTU] = {0};
    for( int i = 0; i < num_of_submission; i++ ){
        int id = sub[i].studentID;
        sub_cnt[id]++;
    }
    Submission *sub_list[MAXSTU];
    for( int i = 0; i < MAXSTU; i++ ){
        sub_list[i] = (Submission *)malloc(sizeof(Submission)*sub_cnt[i]);
        sub_cnt[i] = 0;
    }
    for( int i = 0; i < num_of_submission; i++ ){
        int id = sub[i].studentID;
        sub_list[id][sub_cnt[id]++] = sub[i];
    }
    for( int i = 0; i < MAXSTU; i++ ){
        if( sub_cnt[i] != 0 )
            qsort(sub_list[i], sub_cnt[i], sizeof(Submission), compare);
    }
    for( int i = 0; i < MAXSTU; i++ ){
        int final = 0;
        for( int j = 0; j < sub_cnt[i]; j++ ){
            int correct = 0;
            for( int data = 0; data < 10; data++ )
                if( strcmp(answer[data], sub_list[i][j].outputs[data]) == 0 )
                    correct++;
            printf("Student %d gets %d with Submission %d.\n", i, correct * 10, sub_list[i][j].subID);
            if( correct * 10 > final )
                final = correct * 10;
        }
        if( sub_cnt[i] != 0 )
            printf("Student %d gets %d in this exam.\n", i, final);
    }
}

int main(){
    char answer[10][maxL];
    int  num_of_submission;
    Submission* sub;
 
    for(int i=0;i<10;i++){
        scanf("%s",answer[i]);
    }
 
    scanf("%d",&num_of_submission);
 
    sub=(Submission*)malloc(num_of_submission*sizeof(Submission)); 
    for(int i=0;i<num_of_submission;i++){
        scanf("%d %d",&sub[i].subID,&sub[i].studentID);
        for(int j=0;j<10;j++){
            scanf("%s",sub[i].outputs[j]);
        }
    }
    grading(answer,sub,num_of_submission);
    return 0;
}