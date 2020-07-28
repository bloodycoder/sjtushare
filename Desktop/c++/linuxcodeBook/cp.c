#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#define BUFFERSIZE 4096
#define COPYMODE 0644
void oops(char *s1,char *s2);
int main(int ac,char *av[]){
    int in_fd,out_fd,n_chars;
    char buf[BUFFERSIZE];
    if(ac != 3){
        fprintf(stderr,"usage:%s source destination\n",*av);
        exit(1);
    }
    if((in_fd=open(av[1],O_RDONLY)) == -1){
        oops("Cannot open ",av[1]);
    }
    DIR *dir_ptr;
    char newname[100];
    dir_ptr = opendir(av[2]);
    if(dir_ptr == NULL){
        //not a dir
        if((out_fd = creat(av[2],COPYMODE)) == -1){
            oops("Cannot create ",av[2]);
        }
    }
    else{
        //is dir
        int len = strlen(av[2]);
        strcpy(newname,av[2]);
        strcpy(newname+len,"/");
        strcpy(newname+len+1,av[1]);
        if((out_fd = creat(newname,COPYMODE)) == -1){
            oops("Cannot create ",av[2]);
        }
    }
    while((n_chars = read(in_fd,buf,BUFFERSIZE))>0){
        if(write(out_fd,buf,n_chars) != n_chars){
            oops("Write error to",av[2]);
        }
        if(n_chars == -1){
            oops("read error from",av[1]);
        }
    }
    close(in_fd);
    close(out_fd);
    return 0;
}
void oops(char *s1,char *s2){
    fprintf(stderr,"Error: %s",s1);
    perror(s2);
    exit(1);
}