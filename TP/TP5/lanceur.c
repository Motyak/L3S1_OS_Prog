#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char* argv[])
{
    int status;
    pid_t c_pid;
    int fd;
    int pidOrdo;
    
     c_pid=fork();
        if(c_pid == 0) 
        { 
            //child
            printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
            kill(getpid(),SIGSTOP);
            execvp(argv[1],&argv[1]);
            // exit(0);    //ici pas besoin car execlp
        }
        else if(c_pid>0)
        {
            //parent
            printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid);
            fd=open("pid.dat",O_WRONLY | O_CREAT,0777);
            write(fd,&c_pid,sizeof(int));
            close(fd);
            fd=open("ordo.dat",O_RDONLY);
            read(fd,&pidOrdo,sizeof(int));
            kill(pidOrdo,SIGUSR1);
            wait(&status);
            kill(pidOrdo,SIGUSR2);
            printf("Process terminated with status : %d\n\n",status);
        }
        else
        {
            perror("fork() error");
            exit(-1);
        }
    
}
