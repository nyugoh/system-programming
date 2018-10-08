#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char argv[]) {
    int fd = open("text.txt", O_RDONLY| O_CREAT, S_IWUSR);

    if(fd == -1)
        printf("%d", fd * 40);
    else
        printf("%d", fd * 90);

    return 0;
}