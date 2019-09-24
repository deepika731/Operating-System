#include<stdio.h>
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
int main()
{
	char buf[20];
	int fd1,n,fd2;
	fd1 = open("deepika.txt",O_RDONLY);
	fd2 = open("deepika1.txt",O_WRONLY);
	n = read(fd1,buf,10);
	write(fd2,buf,n);
	close(fd1);
	close(fd2);
}
