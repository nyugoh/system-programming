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

### `lseek()`
 `lseek()` For each open file, the kernel records a file offset, sometimes called the `read-write` offset or pointer.
 This is the location in the file, in which the  next
 read or write will commence. The file offset is expressed as a file as an ordinal point relative to the file. The first byte file is at  of offset of 0, the file offset is said to point to
 start of the file when the file is opened, and is automatically adjusted by subsequent call to read/write so that it points to the next byte of the file after the byte just read or written.
 The first succesive read() and write() progress sequentially thought-out the file.
 #### Syntax
 ```
 off_t lseek(int fd, off_t offset, int whence);
 ```
 offset arg ~ Specifies a value in byte
 whence arg ~ Indicate the best point from where the offset is to be interpreted and is one of the following values,
    - `SEEK_SET` ~ The file offset is set offet byte to the beginning of the file
    - `SEEK_CUR` ~ The file offset is adjusted by offset bytes relative to the current file offset
    - `SEEK_END` ~ The file offset is set to file size plus offset, in other words it's interpreted with respect to the next byte after the last byte of the file