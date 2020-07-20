#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void fork1();
void fork2();
void fork3();
void fork4();

int main(int argc, char* argv[])
{
	// fork1();
	// fork2();
	// fork3();
	fork4();

	exit(0);
}

// one parent one child (A->A.1)
void fork1()
{
	int status;
	pid_t c_pid = fork();
	
	if(c_pid > 0)
	{
		//parent
		printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid);
		wait(&status);
	}
	else if(c_pid == 0)
	{
		//child
		printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		perror("fork() error");
		exit(-1);
	}
}

// one parent two children (A->{A.1,A.2})
void fork2()
{
	int status;
    pid_t c_pid1,c_pid2;
    
	c_pid1=fork();
    if(c_pid1 == 0) 
    { 
		//fils1
		printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
		exit(0);
	}
    else if(c_pid1>0)
    {
		c_pid2=fork();
		if(c_pid2==0)
		{
			//fils2
			printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
			exit(0);
		}
		else if(c_pid2>0)
		{
			//parent
			printf("I'm in the parent %d, my child is %d,%d\n",getpid(),c_pid1,c_pid2);
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

// one parent two children (A->A.1->A.1.1)
void fork3()
{
	int status;
    pid_t c_pid1,c_pid2;
    
	c_pid1=fork();
    if(c_pid1 == 0) 
    { 
		c_pid2=fork();
		if(c_pid2==0)
		{
			//fils2
			printf("I'm in the child %d, my parent is %d\n",getpid(),getppid());
			exit(0);
		}
        else if(c_pid2>0)
        {
            //fils 1
            printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid2);
            wait(&status);
        }
        else
        {
            perror("fork() error");
			exit(-1);
        }
	}
    else if(c_pid1>0)
    {
        //parent
        printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid1);
        wait(&status);
    }
	else
    {
        perror("fork() error");
        exit(-1);
    }
    
}
//one parent 3 children (A->A.1->{A.1.1;A.1.2})
void fork4()
{
	int status;
	int c_pid1,c_pid2,c_pid3;

	c_pid1=fork();
	if(c_pid1==0)
	{
		c_pid2=fork();
		if(c_pid2==0)
		{
			//fils 2
			printf("fils2>I'm in the child %d, my parent is %d\n",getpid(),getppid());
		}
		else if(c_pid2>0)
		{
			c_pid3=fork();
			if(c_pid3==0)
			{
				//fils3
				printf("fils3>I'm in the child %d, my parent is %d\n",getpid(),getppid());
				// sleep(3); //pour prouver que fils 1 attend bien ses fils
			}
			else if(c_pid3>0)
			{
				//fils1
				wait(&status);
				wait(&status);
				printf("fils1>I'm in the child %d, my parent is %d\n",getpid(),getppid());
			}
		}
	}
	else if(c_pid1>0)
	{
		//parent
		wait(&status);
		printf("I'm in the parent %d, my child is %d\n",getpid(),c_pid1);
	}

}
