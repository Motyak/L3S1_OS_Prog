#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigHandlerChild1(int);
void sigHandlerChild2(int);

int main(int argc, char* argv[])
{
    pid_t child1,child2;
    child1=fork();
    if(child1<0)
    {
        perror("fork() error child 1");
        exit(-1);
    }
    else if(child1 == 0)
    {
		//child 1
        printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
        while(1)
            signal(SIGUSR1,sigHandlerChild1);
    }
    else
    {
        child2=fork();
        if(child2<0)
        {
            perror("fork() error child 2");
            exit(-1);
        }
        else if(child2 == 0)
        {
            //child2
            printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
            while(1)
                signal(SIGUSR2,sigHandlerChild2);
        }
        else
        {
            //parent
            printf("I'm in the parent %d, my childs are %d and %d\n",getpid(),child1,child2);
            while(1)
	        {
		        sleep(1);
		        kill(child1,SIGUSR1);
		        sleep(1);
		        kill(child2,SIGUSR2);
	        }
        }
    }
    return EXIT_SUCCESS;
}

void sigHandlerChild1(int sig)
{
    printf("\nCeci est un bon exercice..\n");
}

void sigHandlerChild2(int sig)
{
    printf("\n..pour comprendre le mécanisme des signaux\n");
}