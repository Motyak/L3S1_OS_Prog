#include <stdio.h>
#include <signal.h>

void NThandler(int);

int main()
{
	while(1)
		signal(SIGUSR2,NThandler);

	return 0;
}


void NThandler(int sig)
{
	signal(sig, SIG_IGN);
	printf("\n..pour comprendre le mécanisme des signaux\n");
}

