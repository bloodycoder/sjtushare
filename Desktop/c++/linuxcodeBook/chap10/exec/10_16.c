#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
int isaregfile(int fd){
    struct stat setting;
    fstat(fd,&setting);
    return S_ISREG(setting.st_mode);
}
int main(){
    int in_fd;
    in_fd = open("/etc/passwd",O_RDONLY);
    printf("value is %d",isaregfile(0));
    printf("value is %d",isaregfile(in_fd));
    close(in_fd);
}