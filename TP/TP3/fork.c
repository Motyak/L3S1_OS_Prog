#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        pid_t childPIDorZero = fork();
        if (childPIDorZero < 0)
        {
            perror("fork() error");
            exit(-1);
        }

        else if(childPIDorZero != 0)
        {
            printf("I'm in the parent %d, my child is %d\n",getpid(),childPIDorZero);
            wait(NULL); /*wait for child process to join with this parent*/
        }
        else
        {
            printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
            execl("/bin/echo","echo","Hello, World",NULL);
        }
        return EXIT_SUCCESS;
}