#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>
void set_crmode();
int main(){
    void f(int);
    int i;
    //signal(SIGINT,SIG_IGN);
    set_crmode();
    while(1){
        printf("you can't stop me \n");
        sleep(1);
    }
}
void set_crmode(){
    struct termios setting;
    tcgetattr(0,&setting);
    setting.c_lflag &= ~ISIG;
    tcsetattr(0,TCSANOW,&setting);
}