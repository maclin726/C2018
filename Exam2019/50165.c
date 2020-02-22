#include <stdio.h>
#include <tgmath.h>

void intersection(double line[][3], int i, int j, double *ans){
    ans[0] = (line[i][2]*line[j][1] - line[i][1]*line[j][2])/(line[i][0]*line[j][1] - line[i][1]*line[j][0]);
    ans[1] = (line[i][0]*line[j][2] - line[i][2]*line[j][0])/(line[i][0]*line[j][1] - line[i][1]*line[j][0]);
    return;
}

double distance(double point[][2], int i , int j){
    double aa = (point[i][0] - point[j][0])*(point[i][0] - point[j][0]) + (point[i][1] - point[j][1])*(point[i][1] - point[j][1]);
    return sqrt(aa);
}

int main(){
    int N;
    scanf("%d", &N);
    double line[300][3];
    for ( int i = 0; i < N; i++ )
        scanf("%lf%lf%lf", &line[i][0], &line[i][1], &line[i][2]);
    double point[300][2];
    for( int i = 0; i < N; i++ ){
        double ans[2];
        intersection(line, i, (i+1)%N, ans);
        point[i][0] = ans[0];
        point[i][1] = ans[1];
    }
    double count = 0;
    for( int i = 0; i < N; i++ ){
        count += distance(point, i, (i+1)%N);
    }
    printf("%.3lf\n", count);
}