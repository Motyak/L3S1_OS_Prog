#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd=open("test.dat",O_RDWR | O_CREAT,0777); //important le ',0777'
    int number=4;
    // int *buffer=malloc(sizeof(int));
    // *buffer=4;
    // write(fd,buffer,sizeof(int));
    write(fd,&number,sizeof(number));
    close(fd);

    return 0;
}