#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <string.h>
#define BUFFERSIZE 4096
#define COPYMODE 0644
void oops(char *s1,char *s2);
short is_dir(char *);
int main(int ac,char *av[]){
    int in_fd,out_fd,n_chars;
    struct dirent *direntp;
    char buf[BUFFERSIZE];
    DIR *src_ptr,*des_ptr;
    if(ac != 3){
        fprintf(stderr,"usage:%s source destination\n",*av);
        exit(1);
    }
    short src_is_dir,dst_is_dir;
    src_is_dir = is_dir(av[1]);
    dst_is_dir = is_dir(av[2]);
    char src_filename[50],des_filename[50];
    int dir_len = strlen(av[1]);
    if(src_is_dir && dst_is_dir){
        //all are direct
        src_ptr = opendir(av[1]);
        strcpy(src_filename,av[1]);
        strcpy(src_filename+dir_len,"/");
        strcpy(des_filename,av[2]);
        strcpy(des_filename+dir_len,"/");
        while((direntp = readdir(src_ptr))!=NULL){
            if(strcmp(direntp->d_name,".") == 0 || strcmp(direntp->d_name,"..") == 0){
                continue;
            }
            strcpy(src_filename+dir_len+1,direntp->d_name);
            strcpy(des_filename+dir_len+1,direntp->d_name);
            if((in_fd = open(src_filename,O_RDONLY))==-1){
                oops("cannot open",src_filename);
            }
            if((out_fd = creat(des_filename,COPYMODE)) == -1){
                oops("Cannot create ",des_filename);
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
        }
        return 0;
    }
    if((in_fd=open(av[1],O_RDONLY)) == -1){
        oops("Cannot open ",av[1]);
    }
    char newname[100];
    src_ptr = opendir(av[2]);
    if(src_ptr == NULL){
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
short is_dir(char *filename){
    struct stat src;
    if(stat(filename,&src) == -1){
        perror(filename);
    }
    else{
        //
        if(S_ISDIR(src.st_mode)){
            return 1;
        }
        return 0;
    }
}