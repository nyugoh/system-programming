obj-m += hello_int.o

all:
    make -C /lib/modules/$(uname -r)/build M=$(pwd)build modules


clean:
    make -C /lib/modules/$(uname -r)/build M=$(pwd) clean