#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int status;
    pid_t c_pid;
    int n=1;
    while(1)
    { 
        c_pid=fork();
        if(c_pid == 0) 
        { 
            //child
            printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
            // execlp(argv[2],argv[2],NULL);
            execlp(argv[2],argv[2],argv[3],NULL);
            // exit(0);    //ici pas besoin car execlp
        }
        else if(c_pid>0)
        {
            //parent
            printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid);
            wait(&status);
            printf("Process %d terminated with status : %d\n\n",n,status);
        }
        else
        {
            perror("fork() error");
            exit(-1);
        }
        n++;
        sleep(atoi(argv[1]));
    }
}

