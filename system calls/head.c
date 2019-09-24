#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,f,i,c=0,h;
	printf("No of lines to be dispalyed:");
	scanf("%d",&n);
	f=open("n.txt",O_RDONLY);
	char buffer[1];
	while((read(f,buffer,1)!=0)&&c<n)
	{
		if(buffer[0]=='\n')
			c=c+1;
	
		write(1,buffer,1);
	}
	
}

