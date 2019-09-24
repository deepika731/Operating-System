//2.write a progrm to read smthg from file and write on the monitor
#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,f;
	char buffer[100];
	f=open("n.txt",O_RDONLY);
	n=read(f,buffer,100);
	write(1,buffer,n);
}
