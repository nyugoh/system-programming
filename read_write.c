#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // contains read

#define BUFFER_SIZE 1000

int main(int argc, char* argv[]) {
    char* buffer[BUFFER_SIZE];
    int fd1, fd2;
    ssize_t nmread;
    fd1 = open(argv[1], O_RDONLY);
    mode_t filePerm = O_CREAT | O_WRONLY | O_TRUNC;
    mode_t modules = S_IWUSR | S_IRWXO| S_IXUSR;

    fd2 = open(argv[2], filePerm, modules);

    if(fd2 == 1)
        printf("Failed");
    while(nmread=read(fd1, buffer, BUFFER_SIZE) > 0) {
        if(write(fd2, buffer, BUFFER_SIZE) != nmread){
            printf("Not equal");
            close(fd1);
            close(fd2);
        }
    }
    return 0;
}