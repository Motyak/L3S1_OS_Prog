#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>


void Ls(char* repertoire);
void LsDansFichier(char* repertoire,char* fichierResultat);
void NbFichier(char* repertoire);
int NbFichier2(char* repertoire);

int main(int argc, char* argv[])
{
	//~ Ls(argv[1]);
	//~ LsDansFichier(argv[1],argv[2]);
	//~ NbFichier(argv[1]);
	printf("bonjour\n");
	
}

void Ls(char* repertoire)
{
	int status;
    pid_t c_pid;
    
	c_pid=fork();
    if(c_pid == 0) 
    { 
		//child
		execlp("ls","ls",repertoire,NULL);
		// exit(0);    //ici pas besoin car execlp
	}
    else if(c_pid>0)
    {
		//parent
		wait(&status);
    }
    else
    {
		perror("fork() error");
		exit(-1);
    }
}

void LsDansFichier(char* repertoire, char* fichierResultat)
{
	int status;
    pid_t c_pid;
    
	c_pid=fork();
    if(c_pid == 0) 
    { 
		//child
		int fw=open(fichierResultat,O_WRONLY | O_CREAT);
		close(1);
		dup(fw);
		execlp("ls","ls",repertoire,NULL);
		close(fw);
		// exit(0);    //ici pas besoin car execlp
	}
    else if(c_pid>0)
    {
		//parent
		wait(&status);
    }
    else
    {
		perror("fork() error");
		exit(-1);
    }
}

void NbFichier(char* repertoire)
{
	int status;
    pid_t c_pid1,c_pid2;
    int f[2];
    pipe(f);
    
	c_pid1=fork();
    if(c_pid1 == 0) 
    { 
		//child
		close(1);
		dup(f[1]);
		close(f[0]);
		close(f[1]);
		execlp("ls","ls",repertoire,NULL);
		// exit(0);    //ici pas besoin car execlp
	}
    else if(c_pid1>0)
    {
		//parent
		c_pid2=fork();
		if(c_pid2==0)
		{
			close(0);
			dup(f[0]);
			close(f[0]);
			close(f[1]);
			execlp("wc","wc","-l",NULL);
		}
		else if(c_pid2>0)
		{
			close(f[0]);
			close(f[1]);
			wait(&status);
			wait(&status);
		}
		else
		{
			perror("fork() error");
			exit(-1);
		}
    }
    else
    {
		perror("fork() error");
		exit(-1);
    }
}

//PAS FINI
int NbFichier2(char* repertoire)
{
	int status;
    pid_t c_pid1,c_pid2;
    int f[2];
    int f2[2];
    pipe(f);
    
	c_pid1=fork();
    if(c_pid1 == 0) 
    { 
		//child
		close(1);
		dup(f[1]);
		close(f[0]);
		close(f[1]);
		execlp("ls","ls",repertoire,NULL);
		// exit(0);    //ici pas besoin car execlp
	}
    else if(c_pid1>0)
    {
		//parent
		
		
		
		pipe(f2);
		c_pid2=fork();
		if(c_pid2==0)
		{
			close(0);
			dup(f[0]);
			close(f[0]);
			close(f[1]);
			close(f2[0]);
			close(f2[1]);
			execlp("wc","wc","-l",NULL);
		}
		else if(c_pid2>0)
		{
			close(f[0]);
			close(f[1]);
			close(f2[0]);
			close(f2[1]);
			wait(&status);
			wait(&status);
		}
		else
		{
			perror("fork() error");
			exit(-1);
		}
    }
    else
    {
		perror("fork() error");
		exit(-1);
    }
}
