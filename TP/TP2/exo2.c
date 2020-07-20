#include <unistd.h>
#include <stdio.h>

int main()
{
	int nbS=0;
	while(1)
	{
		printf("Bonjour\n");
		if(nbS==4)
			printf("Aurevoir\n");
		nbS=(nbS+1)%5;
		sleep(1);
	}
}
