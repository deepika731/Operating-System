#include<stdio.h>
int main()
{
	int i,j,no_of_pages,no_of_frames = 3,array_of_pages[30],count=0,flag,frames[10],k;
	printf("enter no of pages:");
	scanf("%d",&no_of_pages);
	for(i=0;i<no_of_pages;i++)
	{
		printf("enter page:");
		scanf("%d",&array_of_pages[i]);
	}
	for(i=0;i<no_of_frames;i++)
	{
		frames[i] = -1;
	}
	k=0;
	for(i=0;i<no_of_pages;i++)
	{
		flag = 0;
		for(j=0;j<no_of_frames;j++)
		{
			if(frames[j] == array_of_pages[i])
			{
				flag = 1;
				continue;
			}
		}
		if(flag == 0)
		{
			frames[k] = array_of_pages[i];
			k = (k+1)%3;
			count++;
		}
	}
	printf("no of pagefaults:%d\n",count);		
}
