#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        pid_t c_pid = fork();
        
        if(c_pid > 0)
        {
			//parent
            printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid);
            wait(NULL);
        }
        else if(c_pid == 0)
        {
			//child
            printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
        }
        else
        {
            perror("fork() error");
            exit(-1);
        }
        return EXIT_SUCCESS;
}
