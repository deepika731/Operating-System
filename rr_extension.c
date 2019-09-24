#include<stdio.h> 
float round_robin(int at[10],int bt[10],int rt[10],int time_quantum,int n,int ch)
{
   int count,j,time,remain,flag=0,res_time=0,wait_time=0,rest[10];
   remain=n;
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
	rest[count]=time;
      rt[count]-=time_quantum; 
      time+=time_quantum; 
	
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      wait_time+=time-at[count]-bt[count]; 
      res_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
	if(ch==1)
	{
		return (res_time*1.0/n);
	}
	else
	{
		return (wait_time*1.0/n);
	}
}
int array_min(int a[10],int n)
{
	int i,min;
	min = a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min = a[i];
		}
	}
	return min;
}
int array_max(int a[10],int n)
{
	int i,max;
	max = 0;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}
int main() 
{ 
 	int at[10],bt[10],rt[10],count,n,time_quantum,i,rt1[10],rt2[10],rt3[10]; 
	float wt1,wt2;
	printf("Enter Total Process:\t ");
	scanf("%d",&n); 
	for(count=0;count<n;count++) 
	{ 
		printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
		scanf("%d",&at[count]); 
		scanf("%d",&bt[count]); 
		rt[count]=bt[count];
		rt1[count]=bt[count];
		rt2[count]=bt[count];
		rt3[count]=bt[count];
	} 
	time_quantum = array_min(bt,n);
	printf("%d\n",time_quantum);
	wt1 = round_robin(at,bt,rt,time_quantum,n,0);
	printf("first waiting time:%f\n",wt1);
	time_quantum = array_max(bt,n);
	printf("%d",time_quantum);
	wt2 = round_robin(at,bt,rt1,time_quantum,n,0);
	printf("second waiting time:%f\n",wt2);
	printf("difference:%f",wt1-wt2);
	time_quantum = array_min(bt,n);
	printf("%d\n",time_quantum);
	wt1 = round_robin(at,bt,rt2,time_quantum,n,1);
	printf("first response time:%f\n",wt1);
	time_quantum = array_max(bt,n);
	printf("%d",time_quantum);
	wt2 = round_robin(at,bt,rt3,time_quantum,n,1);
	printf("second response time:%f\n",wt2);
	printf("difference:%f\n",wt1-wt2);
	return 0; 
}
