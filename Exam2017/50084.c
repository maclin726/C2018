#include<stdio.h>
#include<math.h>
int main(){
    int n,m;                     // n machine and m jobs
    int job_infor[500][2];       // represent a job's arrive time and task number
    int task_infor[500][500][2]; // represent [job],[task],[machine and time]
    int machine_time[500]={0};   // represent time after machine finish a particular task
    int job_time[500]={0};       // job's complete time(final print)
    int task_number[500]={0};    // point which task in a job to do next
    int i,j,min=1000101;
    int nowjob,total=0;
    scanf("%d%d",&n,&m);
    for (i=0; i<m; i++){
        scanf("%d%d",&job_infor[i][0],&job_infor[i][1]);
        for(j=0; j<job_infor[i][1]; j++){
            scanf("%d%d",&task_infor[i][j][0],&task_infor[i][j][1]);
        }
    }
    for (i=0; i<m; i++){
        total+=job_infor[i][1];
    }
    for(j=0; j<total; j++){
        for (i=0; i<m; i++){
            if(task_number[i]==0){
                if(task_infor[i][0][1]+fmax( machine_time[ task_infor[i][0][0] ],job_infor[i][0]) < min){
                    nowjob=i;
                    min=task_infor[i][0][1]+fmax( machine_time[ task_infor[i][0][0] ],job_infor[i][0]);
                }
            }
            else if(task_number[i]!=job_infor[i][1]){
                if(task_infor[i][task_number[i]][1]+fmax(machine_time[ task_infor[i][ task_number[i] ][0] ], job_time[i]) < min){
                    nowjob=i;
                    min=task_infor[i][task_number[i]][1]+fmax(machine_time[ task_infor[i][ task_number[i] ][0] ], job_time[i]);
                }
            }
        }
        job_time[nowjob]=min;
        machine_time[ task_infor[nowjob][ task_number[nowjob] ][0] ]=min;
        min=1000101;
        task_number[nowjob]++;
    }
    for (i=0; i<m; i++)
        printf("%d\n",job_time[i]);
return 0;
}
