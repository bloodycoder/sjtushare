#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024
int main(){
    int fd1 = open("./1.txt",O_RDONLY);
    int fd2 = open("./1.txt",O_WRONLY);
    int fd3 = open("./1.txt",O_RDONLY);
    char buf1[BUFSIZE];
    char *p = "testing 1 2 3...";
    ssize_t numread = read(fd1,buf1,20);
    printf("buf1 is %s\n",buf1);
    ssize_t numwrite = write(fd2,p,sizeof(p));
    ssize_t numread3 = read(fd3,buf1,20);
    printf("buf1 is %s\n",buf1);
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}