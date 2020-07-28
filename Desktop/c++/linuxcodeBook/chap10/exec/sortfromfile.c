#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc,char ** argv){
    int newfd,fd;
    if(argc != 2){
        perror("input error");
        exit(1);
    }
    fd = open(argv[1],O_RDONLY);
    newfd = dup2(fd,0);
    if(newfd !=0){
        perror("redir error");
        exit(2);
    }
    execlp("sort","sort",NULL);

}