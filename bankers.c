#include <stdlib.h>
#include<stdio.h>
void Sequence_check(int p,int r,int Max[10][10],int alloc[10][10],int avail[0])
{
	int need[10][10],completed[10], safeSequence[10];
    	int  i, j, process, count,temp = 0;
   	count = 0;
	for(i = 0; i< p; i++)
        	completed[i] = 0;
	for(i = 0; i < p; i++)
	{
        	for(j = 0; j < r; j++)
		{
	
            		need[i][j] = Max[i][j] - alloc[i][j];
			if(need[i][j]<0)
			{
				printf("requested resource is not available");
				temp = 1;
				return;
			}
			
			
		}
		//break;
	}
			

        do
        {
		if(temp == 1)
		{
			break;
		}
            printf("\n Max matrix:\tAllocation matrix:\n");

            for(i = 0; i < p; i++)
            {
                for( j = 0; j < r; j++)
                    printf("%d ", Max[i][j]);
                printf("\t\t");
                for( j = 0; j < r; j++)
                    printf("%d ", alloc[i][j]);
                printf("\n");
            }

            process = -1;

            for(i = 0; i < p; i++)
            {
                if(completed[i] == 0)//if not completed
                {
                    process = i ;
                    for(j = 0; j < r; j++)
                    {
                        if(avail[j] < need[i][j])
                        {
                            process = -1;
                            break;
                        }
                    }
                }
                if(process != -1)
                    break;
            }

            if(process != -1)
            {
                printf("\nProcess %d runs to completion!", process + 1);
                safeSequence[count] = process + 1;
                count++;
                for(j = 0; j < r; j++)
                {
                    avail[j] += alloc[process][j];
                    alloc[process][j] = 0;
                    Max[process][j] = 0;
                    completed[process] = 1;
                }
            }
        }
        while(count != p && process != -1);

        if(count == p)
        {
            printf("\nThe system is in a safe state!!\n");
            printf("Safe Sequence : < ");
            for( i = 0; i < p; i++)
                printf("%d ", safeSequence[i]);
            printf(">\n");
        }
        else
            printf("\nThe system is in an unsafe state!!");

}
int main()
{
    int Max1[10][10] = {{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
    int Max2[10][10] = {{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
    int Max3[10][10] = {{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
    int alloc1[10][10] = {{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
    int alloc2[10][10] = {{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{1,3,0,0}};
    int alloc3[10][10] = {{0,0,1,2},{0,4,2,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
    int avail1[10] = {1,5,2,0};
     int avail2[10] = {1,5,2,0};
	 int avail3[10] = {1,5,2,0};
    int p, r, i, j, process, count,ch;
    count = 0;
	p = 5;
	r = 4;
	do{
		printf("\n1.check safe sequence\n2.check p4\n3.check p1\n4.exit\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				Sequence_check(p,r,Max1,alloc1,avail1);
				break;
			case 2:
				Sequence_check(p,r,Max2,alloc2,avail2);
				break;
			case 3:
				Sequence_check(p,r,Max3,alloc3,avail3);
				break;
			case 4:
				printf("exited\n");
				break;
			default:
				printf("invalid option\n");
				break;
		}
	}while(ch<=3);
}
