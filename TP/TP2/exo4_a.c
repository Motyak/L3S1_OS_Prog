#include <stdio.h>
#include <signal.h>

void NThandler(int);

int main()
{
	while(1)
		signal(SIGUSR1,NThandler);

	return 0;
}


void NThandler(int sig)
{
	signal(sig, SIG_IGN);
	printf("\nCeci est un bon exercice..\n");
}

