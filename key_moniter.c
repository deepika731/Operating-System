#include<stdio.h>
int main()
{
	char buff[20];
	int n;
	n = read(0,buff,20);
	write(1,buff,n);
}
