#include<stdio.h> 
void sort(int at[10],int et[10],int nt[10],int n)
{
	int i,j,temp1,temp2;
	int temp3;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
				temp1 = at[i];
				at[i] = at[j];
				at[j] = temp1;
				temp2 = et[i];
				et[i] = et[j];
				et[j] = temp2;
				temp3 = nt[i];
				nt[i] = nt[j];
				nt[j] = temp3;
			}
		}
	}
}
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum,ft[10],nt[10]; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
	ft[count] = 0;
	nt[count] = 65+count;
  } 
	sort(aht,bt,nt,n);
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time|finishing time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
	ft[count] = time;
      wait_time=time-at[count]-bt[count]; 
      turnaround_time=time-at[count]; 
      printf("%c\t|\t%d\t|\t%d\t|\t%d\n",nt[count],turnaround_time,wait_time,ft[count]);
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++;
    else 
      count=0;
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f\n",turnaround_time*1.0/n); 
  
  return 0; 
}
