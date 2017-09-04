#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
	int pid;
	int arr_t;
	int bur_t;
	int pri;
}P;
int n;

int min_burst(int burst[n][3],int cur_time)
{
	int index=0;
	int min_burst=burst[index][2];
	for(int i=1;i<n;i++)
		if(cur_time>=burst[i][1] && min_burst>burst[i][2] && burst[i][2])
		{
			index=i;
			min_burst=burst[i][2];
		}
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
	int total_time=0,burst[n][3];
	printf("Enter Burst Chart\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&pr[i].pid,&pr[i].arr_t,&pr[i].bur_t,&pr[i].pri);
		total_time+=pr[i].bur_t;
	}
	sort(pr);
	for(int i=0;i<n;i++)
		burst[i][0]=pr[i].pid,burst[i][1]=pr[i].arr_t,burst[i][2]=pr[i].bur_t;

	int prev_pr=0,cur_time=0,index=0,prev_time=0;
	int gantt[100][3];
	while(total_time-cur_time)
	{
		int cur_pr=min_burst(burst,cur_time);
		if(prev_pr!=cur_pr || !cur_time )
		{
			gantt[index][0]=cur_pr+1;
			gantt[index++][1]=cur_time;
			prev_time=cur_time;
		}
		burst[cur_pr][2]--;
		cur_time++;
		prev_pr=cur_pr;
	}

	printf("%s\n", "Gantt Chart");
	for(int i=0;i<index-1;i++)	
		gantt[i][2]=gantt[i+1][1];
	gantt[index-1][2]=total_time;
	for(int i=0;i<index;i++)
		printf("%d %d %d\n",pr[gantt[i][0]-1].pid,gantt[i][1],gantt[i][2]);

	int time[n][2];
	memset(time,0,sizeof(time));
	float avg_wt=0,avg_tt=0;
	int i=index-1,j=0;
	while(j<n)
		{
			int g_i=gantt[i][0]-1;
			if(!time[g_i][1])
				{	
					time[g_i][1]=gantt[i][2]-pr[g_i].arr_t;	//end_time-arr_time
					time[g_i][0]=time[g_i][1]-pr[g_i].bur_t; //tt-burst
					avg_wt+=time[g_i][0];
					avg_tt+=time[g_i][1];
					j++;
				}
			i--;
		}
	printf("%s\n", "Waiting and Turnaround Time" );
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\n",pr[i].pid,time[i][0],time[i][1]);
	avg_wt/=n;
	avg_tt/=n;
	printf("Avg Wait Time: %.2f\nAvg Turnaround Time: %.2f\n",avg_wt,avg_tt);
}
/*3 4 40 1
4 9 10 4
2 3 30 2
1 0 60 3*/