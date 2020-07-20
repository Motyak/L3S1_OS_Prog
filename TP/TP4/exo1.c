#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int arr[4]={100,100,100,100};
	int fd=open("base.dat",O_WRONLY | O_CREAT);
	if(fd<0)	return 1;
	write(fd,arr,sizeof(arr));
	close(fd);
	return 0;
}
