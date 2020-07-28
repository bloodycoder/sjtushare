#include <stdio.h>
#include <utmpx.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
void show_info(struct utmpx*);
void show_time(long);
int main(){
    struct utmpx *current_record;
    int utmpfd;
    int reclen = sizeof(current_record);
    while( (current_record = getutxent())!= NULL){
        show_info(current_record);
    }
    endutxent();
    return 0;
}
void show_info(struct utmpx* utmpxstruct){
    if(utmpxstruct->ut_type != USER_PROCESS)
        return;
    printf("%-8.8s",utmpxstruct->ut_user);
    printf(" ");
    printf("%-8.8s",utmpxstruct->ut_line);
    printf(" ");
    show_time(utmpxstruct->ut_tv.tv_sec);
    printf(" ");
    #ifdef SHOWHOST
        printf("(%s)",utmpxstruct->ut_host);
    #endif
    printf("\n");
}
void show_time(long timeval){
    char *cp;
    cp = ctime(&timeval);
    printf("%12.12s",cp+4);
}