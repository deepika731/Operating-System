#include<stdio.h>
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
int main()
{
	char buf[20];
	int fd,n;
	fd = open("deepika.txt",O_RDONLY);
	n = read(fd,buf,10);
	write(1,buf,n);
	close(fd);
}
