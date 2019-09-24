#include<stdio.h>
#include<stdlib.h>


int n,gi=0,tb=0;
int pid[10],at[10],bt[10],gt[100],tat[10],cmp[10],fp[10],wt[10],rt[10],a_t[10],b_t[10],pr[10];

int lim(int a){
	int i=0;
	while(at[i]<=a && i<n){
		i++;
	}
	return i;
}

int main(){
	int i,j,temp,m,k;
	printf("Enter no of processes:");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter process details:");
		printf("enter arrival ,bursttime,priority");
		scanf("%d%d%d%d",&pid[i],&at[i],&bt[i],&pr[i]);
	}
/*
	printf("\nProcess_ID\tArrival_Time\tPriority\tBurst_Time\n");

	for(j=0;j<n;j++){
		printf("\t%d\t\t%d\t\t%d\t\t%d\n",pid[j],at[j],pr[j],bt[j]);
	}*/
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
	printf("\nP_ID\tAt\tBt\tFirresp\tCt\tRt\tTat\tWat\n");
	for(j=0;j<n;j++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[j],at[j],b_t[j],fp[j],cmp[j],rt[j],tat[j],wt[j]);
	}
	float aw = 0;
	for(i=0;i<n;i++){
		aw += wt[i];
	}
	aw = aw/n;
	printf("Average waiting time : %f\n",aw);
	float at = 0;
	for(i=0;i<n;i++){
		at += tat[i];
	}
	at = at/n;
	printf("Average Turn around time : %f\n",at);
	int cw=0;
	for(i=0;i<gi;i++){
		if(gt[i]!=gt[i+1]){
			cw++;
		}
	}
	printf("Contex Switches : %d\n\n",cw);

}
