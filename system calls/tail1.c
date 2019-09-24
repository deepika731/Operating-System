#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,fd,c=0;
	char buffer[1];
	fd=open("n.txt",O_RDONLY);
	while(read(fd,buffer,1)!=0)
	{
	if(buffer[0]=='\n')
	{
		c=c+1;
	}	
	}
	printf("%d",c+1);	
	close(fd);
	fd=open("n.txt",O_RDONLY);
	int k,i,count=0;
	printf("enter the lines ");
	scanf("%d",&k);
	if(c<k)
	{
		while(read(fd,buffer,1)!=0)
			write(1,buffer,1);
	}
	else
	{
		i=(c+1)-k;
		while(read(fd,buffer,1)!=0)
		{
			if(buffer[0]=='\n')
				count++;
		if(count>=i)
		{
			write(1,buffer,1);
		}
	}
	}
}
