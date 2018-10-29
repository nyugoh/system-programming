#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // contains read

#define BUFFER_SIZE 1000

int main(int argc, int argv[]) {
    char* buffer[BUFFER_SIZE];
    int file1_fd, file2_fd;
    char* file1[20], file2[20];
    file1 = argv[1];
    file2= argv[2];
    //Open file 1 and 2
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_WRONLY);

    //Read file 1
    file1_fd = read(fd1, buffer, BUFFER_SIZE);
    // Write to file 2
    file2_fd = write(fd2, buffer, BUFFER_SIZE);

    if(file1_fd == -1)
        printf("Error reading file 1");
    else
        printf("Reading file 1");

    if(file2_fd == -1)
        printf("\nError writing to file 2");
    else
        printf("\nWriting to file 2");

    return 0;
}