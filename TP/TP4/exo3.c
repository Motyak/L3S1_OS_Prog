#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
	int val;
	int fd=open("base.dat",O_RDWR);

	if(fd<0)	return 1;
	if(lseek(fd,sizeof(int)*(atoi(argv[1])-1),SEEK_SET)<0)	return 1;
	if(lockf(fd,F_LOCK,sizeof(val)) == -1) return 1;
	read(fd,&val,sizeof(val));
	printf("%d\n",val);
	getchar();
	val--;
	
	if(lseek(fd,-sizeof(int),SEEK_CUR)<0)	return 1;
	write(fd,&val,sizeof(int));
	if(lseek(fd,-sizeof(int),SEEK_CUR)<0)	return 1;
	if(lockf(fd,F_ULOCK,sizeof(int)) == -1)	return 1;
	getchar();
	close(fd);
	return 0;
}

