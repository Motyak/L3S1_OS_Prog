#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int redirect_stdout(char* fichier)
{
    int fd = open(fichier,O_WRONLY | O_CREAT | O_APPEND);//
    int save = dup(1);
    close(1);
    dup(fd);
    close(fd);//*
    return save;
}

void restaure(int saved)
{
    close(1);//
    dup(saved);
}

int main()
{
    printf("Hello 1\n");
    int save = redirect_stdout("hello.txt");
    printf("Hello 2\n");
    restaure(save);
    printf("Hello 3\n");
    return 0;
}