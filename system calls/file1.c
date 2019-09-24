//1.write a progrm to read smthg from keyboard and write on the monitor
#include<stdio.h>
main()
{
	int n;
	char buffer[100];
	n=read(0,buffer,100);
	write(1,buffer,n);
}
