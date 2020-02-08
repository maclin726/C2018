#include<stdio.h>
    int record[1024][1024]={0};
void travel(int map[1024][1024], int N, int M, int A_r, int A_c,
            int B_r, int B_c, int directionA[], int directionB[]){
    int counta = 0, countb = 0, oka = 0, okb = 0;
    int extremer,extremec;
    record[A_r][A_c]=1;
    record[B_r][B_c]=2;
    while( oka != 1 || okb != 1 ){
        if( oka == 0 ){
            extremer=A_r;
            extremec=A_c;
            if( A_r > 0 && A_c > 0 && map[A_r-1][A_c-1] > map[extremer][extremec] ){
                extremer=A_r-1;
                extremec=A_c-1;
                directionA[counta]=5;
            }
            if( A_r > 0 && map[A_r-1][A_c] > map[extremer][extremec] ){
                extremer=A_r-1;
                extremec=A_c;
                directionA[counta]=3;
            }
            if( A_r > 0 && A_c < M-1 && map[A_r-1][A_c+1] > map[extremer][extremec] ){
                extremer = A_r-1;
                extremec = A_c+1;
                directionA[counta]=6;
            }
            if( A_c > 0 && map[A_r][A_c-1] > map[extremer][extremec] ){
                extremec=A_c-1;
                extremer=A_r;
                directionA[counta]=1;
            }
            if( A_c < M-1 && map[A_r][A_c+1] > map[extremer][extremec] ){
                extremec=A_c+1;
                extremer=A_r;
                directionA[counta]=0;
            }
            if( A_r < N-1 && A_c > 0 && map[A_r+1][A_c-1] > map[extremer][extremec] ){
                extremer=A_r+1;
                extremec=A_c-1;
                directionA[counta]=7;
            }
            if( A_r < N-1 && map[A_r+1][A_c] > map[extremer][extremec] ){
                extremer=A_r+1;
                extremec=A_c;
                directionA[counta]=2;
            }
            if( A_r < N-1 && A_c < M-1 && map[A_r+1][A_c+1] > map[extremer][extremec] ){
                extremer=A_r+1;
                extremec=A_c+1;
                directionA[counta]=4;
            }
        }
        if (extremer == A_r && extremec == A_c){
            oka = 1;
            directionA[counta+1] = (-1);
        }
        A_r=extremer;
        A_c=extremec;
        if( okb == 0 ){
            extremer=B_r;
            extremec=B_c;
            if( B_r > 0 && B_c > 0 && map[B_r-1][B_c-1] < map[extremer][extremec] ){
                extremer=B_r-1;
                extremec=B_c-1;
                directionB[countb]=5;
            }
            if( B_r > 0 && map[B_r-1][B_c] < map[extremer][extremec] ){
                extremer=B_r-1;
                extremec=B_c;
                directionB[countb]=3;
            }
            if( B_r > 0 && B_c < M-1 && map[B_r-1][B_c+1] < map[extremer][extremec] ){
                extremer=B_r-1;
                extremec=B_c+1;
                directionB[countb]=6;
            }
            if( B_c > 0 && map[B_r][B_c-1] < map[extremer][extremec] ){
                extremec=B_c-1;
                extremer=B_r;
                directionB[countb]=1;
            }
            if( B_c < M-1 && map[B_r][B_c+1] < map[extremer][extremec] ){
                extremec=B_c+1;
                extremer=B_r;
                directionB[countb]=0;
            }
            if( B_r < N-1 && B_c > 0 && map[B_r+1][B_c-1] < map[extremer][extremec] ){
                extremer=B_r+1;
                extremec=B_c-1;
                directionB[countb]=7;
            }
            if( B_r < N-1 && map[B_r+1][B_c] < map[extremer][extremec] ){
                extremer=B_r+1;
                extremec=B_c;
                directionB[countb]=2;
            }
            if( B_r < N-1 && B_c < M-1 && map[B_r+1][B_c+1] < map[extremer][extremec] ){
                extremer=B_r+1;
                extremec=B_c+1;
                directionB[countb]=4;
            }
        }
        if (extremer == B_r && extremec == B_c){
            okb = 1;
            directionB[countb+1] = (-1);
        }
        B_r=extremer;
        B_c=extremec;

        if( A_r == B_r && A_c == B_c ){
            oka = 1;
            okb = 1;
            directionA[counta] = (-1);
            directionB[countb] = (-1);
        }
        else if( record[A_r][A_c]==2 ){
            oka = 1;
            directionA[counta] = (-1);
        }
        else if( record[B_r][B_c]==1 ){
            okb = 1;
            directionB[countb] = (-1);
        }
        if(oka==0){
            record[A_r][A_c]=1;
            counta++;
        }
        if(okb==0){
            record[B_r][B_c]=2;
            countb++;
        }
    }
}
