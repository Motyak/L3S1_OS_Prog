#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigHandler(int sig)
{
    signal(sig,SIG_IGN);
    printf("\nproc\n");
    signal(SIGALRM, sigHandler);
    alarm(2);
}

int main()
{
    alarm(2);
    while(1)
        signal(SIGALRM,sigHandler);
}