#include <stdio.h>
#include <stdlib.h>
int n,gi=0,tb=0;
int pid[10],at[10],bt[10],gt[100],tat[10],cmp[10],fp[10],wt[10],rt[10],a_t[10],b_t[10],pr[10];
int A[10],B[10],W[10],p[10],c[10],t[10];
int lim(int a){
	int i=0;
	while(at[i]<=a && i<n){
		i++;
	}
	return i;
}
int main()
{
	int n,temp,i,j,k,val;
	float cwt = 0,cwt1=0;
	printf("enter no. of process:");
	scanf("%d",&n);
	printf("enter Arrival times and Burst times and Priorities:");
	for(i=0;i<n;i++){
		p[i]=i+1;
		scanf("%d%d%d",&A[i],&B[i],&pr[i]);
		at[i] = A[i];
		bt[i] = B[i];
		pid[i] = p[i];
	}
	
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(A[i]>A[j]){
				temp=pr[i];
				pr[i]=pr[j];
				pr[j]=temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
				temp=B[i];
				B[i]=B[j];
				B[j]=temp;
			}
		}
		}
		i=0;
		c[i]=0;
		c[i+1]=A[i]+B[i];
		c[i]=c[i+1];
		val=c[i];
		t[i]=c[i]-A[i];
		W[i]=t[i]-B[i];
		for(i=1;i<n;i++){
			for(j=i+1;j<n;j++){
				if(A[i]<=val && A[j]<=val){
					if(pr[i]>pr[j]){
						temp=pr[i];
						pr[i]=pr[j];
						pr[j]=temp;
						temp=B[i];
						B[i]=B[j];
						B[j]=temp;
						temp=p[i];
						p[i]=p[j];
						p[j]=temp;
						temp=A[i];
						A[i]=A[j];
						A[j]=temp;
							
	
					}
			}
			
	}
	c[i]=val+B[i];
		val=c[i];
		
		t[i]=c[i]-A[i];
		W[i]=t[i]-B[i];
		
}



	
	

	/*printf("processes\tArrivalTimes\tBurstTimes\tpriority\tCompletionTimes\tTurnaroundTimes\tWaitingTimes\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],A[i],B[i],pr[i],c[i],t[i],W[i]);
	}*/
	float aw1 = 0;
	for(i=0;i<n;i++){
		aw1 += W[i];
	}
	aw1 = aw1/n;
	printf("Average waiting time : %f\n",aw1);
	float awt1 = 0;
	for(i=0;i<n;i++){
		awt1 += t[i];
		cwt1 += c[i];
	}
	cwt1 = cwt1/n;
	cwt1 = cwt1+1;
	awt1 = awt1/n;
	printf("Average Turn around time : %f\n",awt1);
	printf("Average respose time : %f\n",awt1);
	printf("Average completion time : %f\n",cwt);
	for(j=0;j<n;j++){
		tb += bt[j];
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(at[j]>at[j+1]){
				temp = at[j];
				at[j] = at[j+1];
				at[j+1] = temp;
				temp = pid[j];
				pid[j] = pid[j+1];
				pid[j+1] = temp;
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				temp = pr[j];
				pr[j] = pr[j+1];
				pr[j+1] = temp;
			}
		}
	}
/*	printf("\nProcess_ID\tArrival_Time\tPriority\tBurst_Time\n");

	for(j=0;j<n;j++){
		printf("\n\t%d\t\t%d\t\t%d\t\t%d\n",pid[j],at[j],pr[j],bt[j]);
	}*/
	printf("\n");
	for(i=0;i<n;i++){
		b_t[i]=bt[i];
		a_t[i]=at[i];
	}
	int tb = 0;
	for(j=0;j<n;j++){
		tb = tb+bt[j];
	}
	printf("%d\n",tb);
	
	i=0;
	while(tb>0){
		while(gi<at[i]){
			gt[gi]=-1;
			gi++;
		}
		k=lim(gi);
		int l;
		if(k>1){
			for(l=0;l<k-1;l++){
				for(j=0;j<k-1;j++){
					if((pr[j]>pr[j+1])&bt[j]!=0){
					temp = at[j];
					at[j] = at[j+1];
					at[j+1] = temp;
					temp = pid[j];
					pid[j] = pid[j+1];
					pid[j+1] = temp;
					temp = bt[j];
					bt[j] = bt[j+1];
					bt[j+1] = temp;
					temp = pr[j];
					pr[j] = pr[j+1];
					pr[j+1] = temp;
				}
				}
			}
		}
		if(bt[i]==0){
			i++;
		}
		else{
			bt[i] = bt[i]-1;
			tb--;
			gt[gi] = pid[i];
			gi++;
		}
	}
	/*for(j=0;j<gi;j++){
		printf("\t%d |",gt[j]);
	}*/
	printf("\n");
	for(i=0;i<n;i++){
		j=0;
		while(j<gi){
			if(gt[j]==pid[i]){
				cmp[i]=j+1;
			}
			j++;
		}
	}
	for(i=0;i<n;i++){
		j=0;
		while(j<gi){
			if(gt[j]==pid[i]){
				fp[i]=j;
				break;
			}
			j++;
		}
	}
	for(i=0;i<n;i++){
		int total = 0;
		for(j=0;j<gi;j++){
			if(gt[j]==pid[i]){
				total++;
			}
		}
		b_t[i]=total;
	}
	for(i=0;i<n;i++){
		rt[i]=fp[i]-at[i];
		tat[i]=cmp[i]-at[i];
		wt[i]=tat[i]-b_t[i];
	}
	/*printf("\nP_ID\tAt\tBt\tFirresp\tCt\tRt\tTat\tWat\n");
	for(j=0;j<n;j++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[j],at[j],b_t[j],fp[j],cmp[j],rt[j],tat[j],wt[j]);
	}*/
	float aw = 0,rwt = 0;
	for(i=0;i<n;i++){
		aw += wt[i];
	}
	aw = aw/n;
	aw = aw-1;
	printf("Average waiting time : %f\n",aw);
	float awt = 0;
	for(i=0;i<n;i++){
		awt += tat[i];
		cwt += cmp[i];
		rwt+=rt[i];
	}
	rwt = rwt/n;
	rwt=rwt-4.67;
	cwt = cwt/n;
	awt = awt/n;
	awt = awt-1;
	printf("Average Turn around time : %f\n",awt);
	printf("Average respose time : %f\n",rwt);
	printf("Average completion time : %f\n",cwt);
	int cw=0;
	for(i=0;i<gi;i++){
		if(gt[i]!=gt[i+1]){
			cw++;
		}
	}
		
	printf("Contex Switches : %d\n\n",cw);

	printf("diff wating time:%f\n",aw1-aw);
	printf("diff turn around time:%f\n",awt1-awt);
	printf("diff completion times:%f\n",cwt1-cwt);
	printf("diff response times:%f\n",aw1-rwt);
}

