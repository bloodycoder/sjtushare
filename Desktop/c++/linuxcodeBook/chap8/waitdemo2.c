#include <stdio.h>
#define DELAY 20
int main(){
    int newpid;
    void child_code(),parent_code();
    printf("mypid is %d\n",getpid());
    if((newpid = fork()) == -1){
        perror("fork\n");
    }
    else if(newpid == 0){
        child_code(DELAY);
    }
    else{
        parent_code(newpid);
    }
}
void child_code(int delay){
    printf("child %d here,willl sleep for %d seconds\n",getpid(),delay);
    sleep(delay);
    printf("child done.about to exit\n");
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