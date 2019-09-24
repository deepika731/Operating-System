#include<stdio.h>
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
int main()
{
	char buf[20];
	int fd,n;
	n = read(1,buf,10);
	fd = open("deepika1.txt",O_WRONLY);
	write(fd,buf,n);
	close(fd);
}
