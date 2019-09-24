#include<stdio.h> 
float round_robin(int at[10],int bt[10],int rt[10],int time_quantum,int n)
{
	int count,j,time,remain,flag=0,wait_time=0,turnaround_time=0;
	 remain=n;
	//printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
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
     // printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
	return (wait_time*1.0/n);
  //printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  //printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
}
int main() 
{ 
 
   
  int at[10],bt[10],rt[10],count,n,time_quantum; 
	float wt;
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  wt = round_robin(at,bt,rt,time_quantum,n);
  printf("%f",wt);
	
  return 0; 
}
