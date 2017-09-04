#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
	int pid;
	int arr_t;
	int bur_t;
	int pri;
}P;
int n,max_pri=0;

int high_pr(P pr[n],int cur_time,int flag[n])
{
	int index=0;
	int high_pr=max_pri;
	for(int i=0;i<n;i++)
		if(cur_time>=pr[i].arr_t && high_pr>=pr[i].pri && !flag[i])
		{
			index=i;
			high_pr=pr[i].pri;
		}
	flag[index]=1;
	return index;
}

void sort(P pr[n])
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(pr[j].arr_t > pr[j+1].arr_t)
			{
				P t = pr[j];
				pr[j] = pr[j+1];
				pr[j+1]=t;
			}
}
void main()
{
	printf("Enter number of process: ");
	scanf("%d",&n);
	P pr[n];
	int total_time=0;
	printf("Enter Burst Chart\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&pr[i].pid,&pr[i].arr_t,&pr[i].bur_t,&pr[i].pri);
		total_time+=pr[i].bur_t;
		if(pr[i].pri>max_pri)
			max_pri=pr[i].pri;
	}
	sort(pr);
	int flag[n],gantt[n][3];
	memset(flag,0,sizeof(flag));
	int cur_time=0;
	int i=0;
	printf("Gantt Chart\n");
	while(total_time-cur_time)
	{
		int index=high_pr(pr,cur_time,flag);
		printf("%d %d %d\n",pr[gantt[i++][0]=index].pid,gantt[i][1]=cur_time-pr[index].bur_t,gantt[i][2]=cur_time+=pr[index].bur_t);
	}

	int time[n][3];
	int index=0;
	float avg_wt=0,avg_tt=0;
	printf("%s\n", "Waiting and Turnaround Time" );
	for(int i=0;i<n;i++)
		{
			index=gantt[i][0];
			time[index][0]=index;
			time[index][2]=gantt[i][2]-pr[index].arr_t;//tt=end_time-arr_time
			time[index][1]=time[index][2]-pr[index].bur_t;//wt=tt-burst
			avg_wt+=time[index][1];
			avg_tt+=time[index][2];
		}
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\n",pr[time[i][0]].pid,time[i][1],time[i][2]);

	avg_wt/=n;
	avg_tt/=n;
	printf("Avg Wait Time: %.2f\nAvg Turnaround Time: %.2f\n",avg_wt,avg_tt);
}
/*3 4 40 1
4 9 10 4
2 3 30 2
1 0 60 3*/