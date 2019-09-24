#include<stdio.h>
#include<fcntl.h>
main()
{
	int f1,f2,f3,n;
	char buffer[1];
	char buffer1[1];
	f1=open("n.txt",O_RDONLY);
	f2=open("d.txt",O_RDONLY);
	f3=open("nd.txt",O_WRONLY);
	while(read(f1,buffer,1)!=0)
	{
			write(f3,buffer,1);
			if(buffer[0]=='\n')
			{
				while(read(f2,buffer1,1)!=0)
				{
						write(f3,buffer1,1);
						if(buffer1[0]=='\n')
						break;
				}
			}
	}
	
}
