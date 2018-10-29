#include <sys/stat.h>
#include <fcntl.h> //contains open function
#include <unistd.h> // contains read
#include <stdio.h>
// Constants
#define BUFFER_SIZE 20

int  main() {
    int fd;
    char* buffer[BUFFER_SIZE];
    fd = read(/dev/null, buffer, BUFFER_SIZE);

    if(fd ==-1)
        printf("Failed");
    else
        printf("I have read: %s", buffer);
}