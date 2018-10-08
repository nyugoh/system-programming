#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fd;
    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error");
    }
    else
    {
        printf("Success");
    }
}
