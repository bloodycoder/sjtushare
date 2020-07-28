#include <stdio.h>
#include <signal.h>
int main(){
    void wakeup(int);
    printf("sleep start\n");
    fflush(stdout);
    signal(SIGALRM,wakeup);
    signal(SIGINT,SIG_IGN);
    alarm(4);
    pause();
    printf("morning so soon?\n");
}
void wakeup(int signum){
    printf("alarm received from kernel\n");
}