# File open modes

```
int fd = open('text.txt', flags, Mode)

```
### Path
    ~ Location of file to open
### Flag options
The following are params that can be used in opening the file.

    `O_RDONLY` ~ Opens the file on read only mode
    `O_WRONLY` ~ Opens the file on write only mode
    `O_RDWR` ~ Opens the file for both read and write

### Mode options
Types of modes:
    `S_IWUSR` ~ gives write permission to the owner
    `S_IRWXU` ~ gives read write execute search permission to owner
    `S_IXUSR` ~ excute search persmission to owner
    `S_IRUSR` ~ Execute, search permission to owner

 S_IRWXU = SIWUSR

 ## `create`
 - its' a system call that opens/creates a new file with a give path file or if the file already exits opens the file and truncates it's length to zero.

 ## `open`
 - as it's function result `create` returns a file-descriptor that can be used in subsequent system calls.
   ` create(filePath) == open(filePath,  O_RDONLY| O_CREATE| TRUNC, S_IRWXU)`

 ## `read`
 - the read sys call reads data from a open file refereed to as by the file discriptor, `fd`
  #### Syntax
  `ssize_t read(fd, void* buffer, size_t count)`

  A successful to read returns the number of bytes actually read or zero if EOF is encountered