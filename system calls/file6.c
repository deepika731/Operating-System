//appending into third file
#include<stdio.h>
#include<fcntl.h>
main()
{
	int f1,f2,f3,n;
	char buffer[1];
	f1=open("n.txt",O_RDONLY);
	f2=open("d.txt",O_RDONLY);
	f3=open("nd.txt",O_WRONLY);
	while(read(f1,buffer,1)!=0)
	{
		write(f3,buffer,1);
	}
	while(read(f2,buffer,1)!=0)
	{
		write(f3,buffer,1);
	}
}
