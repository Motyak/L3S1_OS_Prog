#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include "../libListe/include/Liste.h"

void sauverPid();
void delCur(int);
void newProc(int);
void nextProc(int);

Maillon* liste=NULL;

//gcc -o ordo ordo.c ../libListe/src/Liste.c
int main()
{	
	//sauvegarde du pid dans un fichier
	sauverPid();
	
	signal(SIGUSR2,delCur);
	signal(SIGUSR1,newProc);
	signal(SIGALRM,nextProc);
	while(1)
		pause();
}

void sauverPid()
{
	int pid=getpid();
	int fd=open("ordo.dat",O_WRONLY | O_CREAT,0777);
	if(fd<0)	perror("error");
	write(fd,&pid,sizeof(int));
	close(fd);
}

void delCur(int sig)
{
	printf("delCur, pid : %d\n",liste->val);
	liste=del(liste);
	if(liste==NULL)
		alarm(0);
	else
	{
		kill(liste->val,SIGCONT);
		alarm(2);
	}
}

void newProc(int sig)
{
	int pid;
	int fd=open("pid.dat",O_RDONLY);
	if(fd<0)	perror("error");
	read(fd,&pid,sizeof(int));
	close(fd);
	printf("newProc, pid : %d\n",pid);
	if(liste==NULL)
		alarm(2);
	liste=addPred(pid,liste);
}

void nextProc(int sig)
{
	printf("nextProc, pid : %d\n",liste->val);
	kill(liste->val,SIGSTOP);
	liste=movToSucc(liste);
	printf("nextProc2, pid : %d\n",liste->val);
	kill(liste->val,SIGCONT);
	alarm(2);
}
