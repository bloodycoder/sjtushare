#include <stdio.h>
#include <signal.h>
int main(){
    void f(int);
    int i;
    signal(SIGINT,SIG_IGN);
    for(int i=0;i<5;i++){
        printf("you can't stop me \n");
        sleep(1);
    }
}
void f(int signum){
    printf("OUCH!\n");
}