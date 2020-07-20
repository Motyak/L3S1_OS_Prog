#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
        int status;
        pid_t c_pid = fork();
        
        if(c_pid > 0)
        {
			//parent
            printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid);
            sleep(atoi(argv[1]));
            kill(c_pid,SIGKILL);
            wait(&status);
            printf("Status: %d\n",status);
        }
        else if(c_pid == 0)
        {
			//child
            printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
            // execlp("ls","ls","-l",NULL);   //retourne status 0 car se termine avant envoi signal SIGKILL
			execlp(argv[2],argv[2],NULL);   //retourne status 9 car tuer par signal SIGKILL
        }
        else
        {
            perror("fork() error");
            exit(-1);
        }
        return EXIT_SUCCESS;
}

