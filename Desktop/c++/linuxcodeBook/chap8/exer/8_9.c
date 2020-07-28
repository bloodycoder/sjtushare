#include <stdio.h>
#include <signal.h>
#define DELAY 5
int main(){
    int newpid;
    void child_code(),parent_code();
    void handler(int);
    printf("mypid is %d\n",getpid());
    if((newpid = fork()) == -1){
        perror("fork\n");
    }
    else if(newpid == 0){
        child_code(DELAY);
    }
    else{
        //parent_code(newpid);
        signal(SIGCHLD,handler);
        while(1){
            printf("waiting...\n");
            sleep(1);
        }
    }
}
void child_code(int delay){
    printf("child %d here,willl sleep for %d seconds\n",getpid(),delay);
    sleep(delay);
    printf("child done.about to exit\n");
    exit(17);
}
void handler(int signum){
    printf("process exited");
    exit(0);
}