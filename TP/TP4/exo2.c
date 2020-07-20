#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
	int content[4];
	int fd=open("base.dat",O_RDWR);
	int* buffer=malloc(sizeof(int));

	if(fd<0)	return 1;
	read(fd,content,sizeof(content));
	
	*buffer=content[atoi(argv[1])-1]-1;
	
	if(fd<0)	return 1;
	if(lseek(fd,sizeof(int)*(atoi(argv[1])-1),SEEK_SET)<0)	return 1;
	write(fd,buffer,sizeof(int));
	
	close(fd);
	return 0;
}
