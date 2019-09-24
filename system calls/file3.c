//2.write a progrm to read smthg from keyboard and write on the file
#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,f;
	char buffer[100];
	n=read(0,buffer,5);
	f=open("n.txt",O_WRONLY);
	write(f,buffer,n);
}
