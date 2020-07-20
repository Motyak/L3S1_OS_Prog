#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(int argc,char *argv[])
{
	int pid1=0;
	int pid2=0;

	printf("Saisissez PID1 : \n");
	scanf("%d",&pid1);
	printf("Saisissez PID2 : \n");
	scanf("%d",&pid2);
	
	while(1)
	{
		sleep(1);
		kill(pid1,SIGUSR1);
		sleep(1);
		kill(pid2,SIGUSR2);
	}
}
