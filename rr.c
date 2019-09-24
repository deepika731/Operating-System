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
void insert(int a[10],int num,int k,int n)
{
	int i;
	for(i=n; i>=k; i--)
        {
            a[i] = a[i-1];
        }
        a[k-1] = num;
        n++; 
}
int check_id(int a[10],int n,int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			return i;
		}
	}
}
int count(int a[10],int n,int f)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<f)
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
	int n,at[10],wt[10],et[10],ft[10],tat[10],i,et1[10],tq,pc[10],k,d,x,j,pid[10],m;
	int nt[10];
	float mtat[10];
	printf("enter no of processors:");
	scanf("%d",&n);
	printf("enter the time quantum:");
	scanf("%d",&tq);
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
		et1[i] = et[i];
		ft[i] = 0;
		pc[i] = 0;
	}
	int sum = at[0],l=0,arraysum,co;
	arraysum = array_sum(et,n);
	i=0,x=0;
	while(arraysum!=0)
	{
		for(m=0;m<=x;m++)
		{	
			co = count(at,n,ft[i]);
			d=0;
			for(j=x;j<=co;j++)
			{
				insert(pid,nt[j],d,x);
				d++;
				
			}
			i = check_id(nt,n,pid[m]);
			sum = sum+tq;
			pc[i] = pc[i]+tq;
			if(et[i] == 0)
			{
				arraysum = array_sum(et,n);
				continue;
			}
			else if(pc[i] == et[i])
			{
				et[i] = 0;
				ft[i] = sum;
			}
			else if(pc[i] > et[i])
			{
				sum = sum-(pc[i]-et[i]);
				et[i] = 0;
				ft[i] = sum;
			}
			else
			{
				ft[i] = sum;
				insert(pid,nt[i],x,x);
				arraysum = array_sum(et,n);
				continue;
			}
			
			
		}
		arraysum = array_sum(et,n);
	}	
	for(i=0;i<n;i++)
	{
		wt[i] = ft[i]-(et1[i]+at[i]);
		tat[i] = ft[i]-at[i];
		mtat[i] = (float)tat[i]/et1[i];
	}
	printf("\nnames\tat\tet\twt\tft\ttat\tmtat\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%f\n",nt[i],at[i],et1[i],wt[i],ft[i],tat[i],mtat[i]);
	}
	
	printf("\n");
	
}
