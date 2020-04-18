#include<stdio.h>
int main()
{
    int at[10],bt[10],rt[10],endTime,i,x;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter arrival time for Process P%d : ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
    rt[9]=9999;
    for(time=0;remain!=n;time++)
    {
        x=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]<rt[x] && rt[i]>0)
            {
                x=i;
            }
        }
        rt[x]--;
        if(rt[x]==0)
        {
            remain++;
            endTime=time+1;
            printf("\nP%d\t|\t%d\t|\t%d",x+1,endTime-at[x],endTime-bt[x]-at[x]);
            sum_wait+=endTime-bt[x]-at[x];
            sum_turnaround+=endTime-at[x];
        }
    }
    printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);
    printf("Average Turnaround time = %f",sum_turnaround*1.0/n);
    return 0;
}
