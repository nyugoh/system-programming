#include <sys/stat.h>
#include <fcntl.h> //contains open function
#include <unistd.h> // contains read
#include <stdio.h>
// Constants
#define BUFFER_SIZE 1000

int main(int argc, char argv[]) {
    int fd = open("text.txt", O_RDWR);
    ssize_t read_items;
    char* buffer[BUFFER_SIZE];
    if (fd == -1)
        printf("Failed to open");
    else
    {
        read_items = read(fd, buffer, BUFFER_SIZE);
        printf("File content :%s", buffer);
    }
    return 0;
}
