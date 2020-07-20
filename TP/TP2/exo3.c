#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//#include <sys/types.h>


void timeout(int,int);

int main()
{
	int t;
	int pid;
		
	printf("Entrez le nb de secondes avant l'assassinat\n");
	scanf("%d",&t);
	printf("Entrez le PID du processus à assassiner\n");
	scanf("%d",&pid);

	timeout(t,pid);
}

void timeout(int t,int pid)
{
	sleep(t);
	kill(pid,SIGKILL);	
}
