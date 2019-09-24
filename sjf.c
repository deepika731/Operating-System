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
int count(int a[10],int n,int f)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<=f)
		{
			c++;
		}
		else 
		{
			break;
		}
	}
	return c;
}
int min(int a[10],int n)
{
	int m=100,k=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]<m && a[i]!=0)
		{
			m=a[i];
			k=i;
		}
	}
	return k;
}						
int array_sum(int a[10],int n)
{
	int i,s=0;
	for(i=0;i<n;i++)
	{
		s+=a[i];
	}
	return s;
}				
int main()
{
	int n,at[10],wt[10],et[10],ft[10],tat[10],i,at1[10],et1[10];
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
	for(i=0;i<n;i++)
	{
		at1[i] = at[i];
		et1[i] = et[i];
		ft[i] = 0;
	}
	int sum = at[0],co,arraysum,l=0;
	arraysum = array_sum(et,n);
	while(arraysum!=0)
	{
		co = count(at,n,ft[l]);
		l = min(et,co);
		sum = sum+et[l];
		ft[l] = sum;
		et[l] = 0;
		arraysum = array_sum(et,n);
	}
	for(i=0;i<n;i++)
	{
		wt[i] = ft[i]-(et1[i]+at1[i]);
		tat[i] = ft[i]-at1[i];
		mtat[i] = (float)tat[i]/et1[i];
	}
	printf("\nnames\tat\tet\twt\tft\ttat\tmtat\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%f\n",nt[i],at[i],et1[i],wt[i],ft[i],tat[i],mtat[i]);
	}
	
	printf("\n");
	
}
