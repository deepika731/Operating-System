//4.write a progrm to read smthg from file and write on another file
#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,f1,f2;
	char buffer[100];
	f1=open("n.txt",O_RDONLY);
	n=read(f1,buffer,5);
	f2=open("d.txt",O_WRONLY);
	write(f2,buffer,n);
}
