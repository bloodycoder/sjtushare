#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
int main(int argc,char *argv[]){
    int dir_cnt = 0;
    if(argc < 3){
        perror("wrong args");
        exit(1);
    }
    short dir_flag = 0;
    DIR *dir_ptr;
    if((dir_ptr = opendir(argv[2])) != NULL){
        dir_flag = 1;
    }
    if(!dir_flag){
        int result = rename(argv[1],argv[2]);
        if(result == -1){
            perror("rename file err");
        }
        return 0;
    }
    char newname[50];
    int dirlen = strlen(argv[2]);
    strcpy(newname,argv[2]);
    strcpy(newname+dirlen,"/");
    strcpy(newname+dirlen+1,argv[1]);
    int result = rename(argv[1],newname);
    if(result == -1){
        perror("rename file err");
    }
    return 0;
}