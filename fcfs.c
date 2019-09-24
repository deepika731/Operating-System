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
	int n,at[10],wt[10],et[10],ft[10],tat[10],i;
	int nt[10];
	float mtat[10];
	printf("enter no of processors:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter name of %d processor:",i+1);
		scanf("%d",&nt[i]);
		printf("enter arrival time of %d processor:",i+1);
		scanf("%d",&at[i]);
		printf("enter execution time of %d processor:",i+1);
		scanf("%d",&et[i]);
	}
	sort(at,et,nt,n);
	int sum = at[0];
	for(i=0;i<n;i++)
	{
		sum = sum+et[i];
		ft[i] = sum;
		wt[i] = ft[i]-(et[i]+at[i]);
		tat[i] = ft[i]-at[i];
		mtat[i] = (float)tat[i]/et[i];
	}
	printf("\nnames\tat\tet\twt\tft\ttat\tmtat\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%f\n",nt[i],at[i],et[i],wt[i],ft[i],tat[i],mtat[i]);
	}
	
	printf("\n");
	
}
