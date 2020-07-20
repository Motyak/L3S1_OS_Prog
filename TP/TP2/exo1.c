#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void NThandler(int);

int main()
{
	while(1)
		signal(SIGINT,NThandler);

	return 0;
}


void NThandler(int sig)
{
	signal(sig, SIG_IGN);

	char* pwd;
	pwd=getpass("\nPassword:");

	while(strcmp(pwd,"gateau")!=0)
	{
		pwd=getpass("\nPassword:");
	}		

	exit(0);
}
