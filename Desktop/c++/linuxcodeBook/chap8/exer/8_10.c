#include <stdio.h>
#include <signal.h>
#define DELAY 5
int subp_cnt;
int main(int argc,char ** argv){
    int pid1;
    subp_cnt = atoi(argv[1]);
    void child_code(),parent_code();
    printf("mypid is %d\n",getpid());
    for(int i=0;i<subp_cnt;i++){
        if((pid1 = fork()) == -1){
            perror("fork\n");
        }
        else if(pid1 == 0){
            child_code(DELAY);
        }
    }
    /*
    int wait_rv;
    for(int i=0;i<subp_cnt;i++){
        wait_rv = wait(NULL);
        printf("done waitting for %d\n",wait_rv);
    }*/
    void handler(int);
    signal(SIGCHLD,handler);
    while(1){
        printf("waiting");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".\n");
    }
    return 0;
}
void child_code(int delay){
    //printf("child %d here,willl sleep for %d seconds\n",getpid(),delay);
    sleep(delay);
    //printf("child done.about to exit\n");
    exit(17);
}
void parent_code(int childpid){
    int wait_rv;
    int child_status;
    int high_8,low_7,bit_7;
    wait_rv = wait(&child_status);
    printf("done waiting for %d,wait returned:%d\n",childpid,wait_rv);
    high_8 = child_status>>8;
    low_7 = child_status & 0x7f;
    bit_7 = child_status & 0x80;
    printf("status:exit = %d,sig = %d,core = %d\n",high_8,low_7,bit_7);
}
void handler(int signum){
    static int counter = 0;
    int wait_rv;
    int child_status;
    wait_rv = wait(&child_status);
    counter++;
    printf("done waitting for %d,counter:%d \n",wait_rv,counter);
    if(counter>=subp_cnt){
        exit(0);
    }
}