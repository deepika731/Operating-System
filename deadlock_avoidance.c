#include<stdio.h>
int main()
{
	int n,m,avail[10],work[10],finish[10],max[10][10],alloc[10][10],need[10][10],sequence[10],i,j,flag,c,k,count;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&sequence[i]);
		finish[i] = -1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
		work[i] = avail[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("need is");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j] = max[i][j]-alloc[i][j];
			printf("%d",need[i][j]);
		}
		printf("\n");
		
	}
	for(i=0;i<n;i++)
	{
		count = 0;
		for(j=0;j<m;j++)
		{
			if(need[sequence[i]][j] <= work[j])
			{
				count++;
			}
			printf("count : %d\n",count);
		}
		if(count == m)
		{
			flag = 1;
		}
		if(flag == 1 && finish[sequence[i]] == -1)
		{
			for(j=0;j<m;j++)
			{
				work[j] = work[j] + alloc[sequence[i]][j];
				printf("work[j] :%d\n",work[j]);
			}
			finish[i] = 0;
		}
		else 
		{
			c=0;
			for(k=0;k<n;k++)
			{
				if(finish[k] == 0)
				{
					c++;
				}
			}
			if(c==n)
			{
				printf("safe sequence");
				break;
			}
			else 
			{
				printf("not safe sequence");
			}
		}
	}		
}

