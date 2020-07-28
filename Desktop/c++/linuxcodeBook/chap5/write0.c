#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <utmpx.h>
#include <string.h>
int main(int ac,char** argv){
    int fd;
    char buf[BUFSIZ];
    char newttyname[50] = "/dev/";
    if(ac!=2){
        fprintf(stderr,"usage:write0 ttyname\n");
        exit(1);
    }
    struct utmpx *current_record;
    char ttyname[50];
    short existName = 0;
    while( (current_record = getutxent())!= NULL){
        if(current_record->ut_type != 7){
            continue;
        }
        if(strncmp(current_record->ut_user,argv[1],strlen(argv[1]))==0){
            strcpy(ttyname,current_record->ut_line);
            existName = 1;
        }
    }
    //
    if(existName == 0){
        fd = open(argv[1],O_WRONLY);
        if(fd == -1){
            perror(argv[1]);
            exit(0);
        }
    }
    else{
        //存在
        strcpy(newttyname+5,ttyname);
        fd = open(newttyname,O_WRONLY);
        if(fd == -1){
            perror(newttyname);
            exit(0);
        }
        printf("ttyname is %s\n",newttyname);
    }
    while(fgets(buf,BUFSIZ,stdin)!=NULL){
        if(write(fd,buf,strlen(buf)) == -1){
            break;
        }
    }
    close(fd);
}