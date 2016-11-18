#include <stdio.h>


void fill(char* p)
{
	p[0]='a';
	p[1]='b';
	*(p+2)='c';
}
int main(int argc, const char *argv[])
{
	char buf[3];// buf=&buf[0]   
	char buffer[4]={0,1,2,3};
	unsigned short* b=(unsigned short*)buffer;
	printf("%c\n",buffer[0]);
	printf("%c\n",buffer[1]);
	printf("%c\n",buffer[2]);
	printf("%c\n",buffer[3]);
    printf("------>%d\n",b[0]);
    printf("------>%d\n",b[1]);
/*	
	fill(buf);
	printf("%c\n",buf[0]);
	printf("%c\n",buf[1]);
	printf("%c\n",buf[2]);
*/	return 0;
}



