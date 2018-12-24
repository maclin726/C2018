#include<stdio.h>
int main(){
    int a[2][20][20][20]={0}, b[20][20][20]={0};//a[0]:input number, a[1]:number order, b:flag
    int n;
    int i,j,k,p,q,r,check=0;    //check flag: check whether I found the number in the chart
    int end=1,last=0;                    //end flag: check whether the game ends
    scanf("%d",&n);
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            for (k=0; k<n; k++){
                scanf("%d",&a[0][i][j][k]);
            }
        }
    }
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            for (k=0; k<n; k++){
                scanf("%d",&a[1][i][j][k]);
            }
        }
    }
    for (i=0; i<n; i++){            //檢查是否bingo
        for (j=0; j<n; j++){
            for (k=0; k<n && last!=1; k++){
                check=0;
                for (p=0; p<n; p++){             //把order的東西放到flag
                    for (q=0; q<n; q++){
                        for (r=0; r<n && check==0; r++){
                            if(a[0][p][q][r]==a[1][i][j][k]){
                                b[p][q][r]=1;
                                check=1;
                            }
                        }
                    }
                }
                for (p=0; p<n; p++){             //1D line
                    for (q=0; q<n; q++){
                        for (r=0; r<n && end==1; r++){
                            if (b[p][q][r]==0)
                                end=0;
                            else if(r==(n-1)&&b[p][q][r]==1)
                                last=1;
                        }
                        end=1;
                        for (r=0; r<n && end==1; r++){
                            if (b[p][r][q]==0)
                                end=0;
                            else if(r==(n-1)&&b[p][r][q]==1)
                                last=1;
                        }
                        end=1;
                        for (r=0; r<n && end==1; r++){
                            if (b[r][p][q]==0)
                                end=0;
                            else if(r==(n-1)&&b[r][p][q]==1)
                                last=1;
                        }
                        end=1;
                    }
                }
                for (p=0; p<n; p++){             //2D line
                    for (q=0; q<n && end==1; q++){
                        if (b[p][q][q]==0)
                            end=0;
                        else if (q==(n-1)&&b[p][q][q]==1)
                            last=1;
                    }
                    end=1;
                    for (q=0; q<n && end==1; q++){
                        if (b[p][q][n-1-q]==0)
                            end=0;
                        else if (q==(n-1)&&b[p][q][n-1-q]==1)
                            last=1;
                    }
                    end=1;
                    for (q=0; q<n && end==1; q++){
                        if (b[q][p][q]==0)
                            end=0;
                        else if (q==(n-1)&&b[q][p][q]==1)
                            last=1;
                    }
                    end=1;
                    for (q=0; q<n && end==1; q++){
                        if (b[q][p][n-1-q]==0)
                            end=0;
                        else if (q==(n-1)&&b[q][p][n-1-q]==1)
                            last=1;
                    }
                    end=1;
                    for (q=0; q<n && end==1; q++){
                        if (b[q][q][p]==0)
                            end=0;
                        else if (q==(n-1)&&b[q][q][p]==1)
                            last=1;
                    }
                    end=1;
                    for (q=0; q<n && end==1; q++){
                        if (b[q][n-1-q][p]==0)
                            end=0;
                        else if (q==(n-1) && b[q][n-1-q][p]==1)
                            last=1;
                    }
                    end=1;
                }
                for (p=0; p<n && end==1; p++){   //3D line
                    if (b[p][p][p]==0)
                        end=0;
                    else if(p==(n-1) && b[p][p][p]==1)
                        last=1;
                }
                end=1;
                for (p=0; p<n && end==1; p++){   //3D line
                    if (b[p][n-1-p][p]==0)
                        end=0;
                    else if(p==(n-1) && b[p][n-1-p][p]==1)
                        last=1;
                }
                end=1;
                for (p=0; p<n && end==1; p++){   //3D line
                    if (b[p][p][n-1-p]==0)
                        end=0;
                    else if(p==(n-1) && b[p][p][n-1-p]==1)
                        last=1;
                }
                end=1;
                for (p=0; p<n && end==1; p++){   //3D line
                    if (b[p][n-1-p][n-1-p]==0)
                        end=0;
                    else if(p==(n-1) && b[p][n-1-p][n-1-p]==1)
                        last=1;
                }
                end=1;
                if(last==1)
                    printf("%d",a[1][i][j][k]);
            }
        }
    }
return 0;
}
