#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;

int Jsort(paper P[], int N, char journal[][64], int paperNumber[], int whichJournal[]){
    int kind = 0;
    for( int i = 0; i < N; i++ ){
        int same = 0;
        for( int j = 0; j < kind && !same; j++ ){
            if( strcmp( P[i].journalName , journal[j] ) == 0 ){
                same = 1;
                whichJournal[i] = j;
                paperNumber[j]++;
            }
        }
        if( !same ){
            strcpy( journal[kind], P[i].journalName );
            whichJournal[i] = kind;
            paperNumber[kind]++;
            kind++;
        }
    }
    return kind;
}

void alphaSort( int order[], char journal[][64], int journalCount ){
    for( int i = 0; i < journalCount; i++ ){
        for( int j = journalCount-1; j > i; j-- )
            if( strcmp( journal[order[j-1]], journal[order[j]] ) > 0 ){
                int temp = order[j];
                order[j] = order[j-1];
                order[j-1] = temp;
            }
    }
    return;
}

void compute(paper P[], int N){
    char journal[1024][64] = {};
    int paperNumber[1024] = {0};
    int whichJournal[1024] = {0};
    int journalCount = Jsort( P, N, journal, paperNumber, whichJournal );

    int citedCount[1024] = {0};
    for( int i = 0; i < N; i++ )
        for( int j = 0; j < P[i].numCitedPaper; j++ )
            citedCount[ whichJournal[ P[i].citedPaperIndex[j] ] ]++;
    int order[1024];
    for( int i = 0; i < journalCount; i++ )
        order[i] = i;
    alphaSort(order, journal, journalCount);
    for( int i = 0; i < journalCount; i++ )
        printf("%s %d/%d\n", journal[order[i]], citedCount[order[i]], paperNumber[order[i]]);
    return;
}

int main() {
    int N;
    paper P[1024] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}