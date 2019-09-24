//5.write a progrm to count spaces,vowels,lines in afile.
#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,f,i,sc=0,vc=0,lc=0;
	char buffer[1];
	f=open("n.txt",O_RDONLY);
	while(read(f,buffer,1)!=0)
	{
		if(buffer[0]==' ')
		{
			sc=sc+1;
		}
		if(buffer[0]=='a'||buffer[0]=='e'||buffer[0]=='i'||buffer[0]=='o'||buffer[0]=='u'||buffer[0]=='A'||buffer[0]=='E'||buffer[0]=='I'||buffer[0]=='O'||buffer[0]=='U')
		{
			vc=vc+1;
		}
		if(buffer[0]=='\n')
		{
			lc=lc+1;
		}
		else
			{
				sc=sc+0;
				vc=vc+0;
				lc=lc+0;
			}
	}
	printf("No of spaces=%d\n",sc);
	printf("No of vowels=%d\n",vc);
	printf("No of lines=%d\n",lc);
}
