#include<stdio.h>
#include<math.h>
#define p 0.03912

double oneshot(int t, int total){
    double prob = 1;
    for( int i = 1; i < t; i++ )
        prob *= (1-p);
    prob *= p;
    for( int i = t+1; i <= total; i++ )
        prob *= (1-p);
    return prob; 
}

double oneshotModel( int remain ){
    double prob = 0;
    for( int i = 1; i <= remain; i++ )
        prob += oneshot(i, remain);
    return prob;
}

double twoshotModel( int remain ){
    double prob = 0;
    for( int i = 1; i <= remain; i++ ){
        int P = 1;
        for( int j = 1; j < i; j++ )
            P *= (1-p);
        P = P * p * oneshotModel(remain - i);
        prob += P;
    }
    return prob;
}

double threeshotModel( int remain ){
    double prob = 0;
    for( int i = 1; i <= remain; i++ ){
        int P = 1;
        for( int j = 1; j < i; j++ )
            P *= (1-p);
        P = P * p * twoshotModel(remain - i);
        prob += P;
    }
    return prob;
}

int main(){
    double prob = threeshotModel(100) + twoshotModel(100) + oneshotModel(100);
    printf("%lf", prob);
    return 0;
}