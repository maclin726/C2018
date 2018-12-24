#include<stdio.h>
int main()
{
    int a[100];
    int b[5050][2];
    int n,check=1;
    int i,j,k,num=0;
    int start=0,end,max=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)         //read n numbers
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<(n-i); j+=2)                    //檢查從自己開始下j個是不是單數回文
        {
            for(k=0; (k<((j+2)/2)&&check==1); k++)
            {
                if(a[i+k]!=a[i+j-k])
                    check=0;
            }
            if (check==1)
            {
                b[num][0]=i;
                b[num][1]=i+j;
                num++;
            }
            check=1;
        }
    }
    for(i=0; i<n; i++)                          //check 是不是雙數回文
    {
        for(j=1; j<(n-i+1); j+=2)
        {
            for(k=0; (k<((j+1)/2)&&check==1); k++)
            {
                if(a[i+k]!=a[i+j-k])
                    check=0;
            }
            if (check==1)
            {
                b[num][0]=i;
                b[num][1]=i+j;
                num++;
            }
            check=1;
        }
    }
    for(i=0; i<num; i++){         //print all palindromic
        for(j=0;j<2;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if( b[i][1]+1==b[j][0] &&  ( (b[j][1]-b[i][0])>max || (b[j][1]-b[i][0])==max) ){
                start=b[i][0];
                end=b[j][1];
                max=end-start;
            }
        }
    }
        for(i=start; i<end+1; i++)
        {
            if(i!=end)
            printf("%d ",a[i]);
            else
            printf("%d",a[i]);
        }
return 0;
}
