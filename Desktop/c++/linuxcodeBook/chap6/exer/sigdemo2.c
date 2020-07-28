#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <fcntl.h>
#define oops(a,v){perror(a);exit(v);}
void tty_mode_restore(int);
void set_crmode();
int max_tri;
int count = 0;
int main(int argc,char ** argv){
    void f(int);
    int i;
    tty_mode_restore(0);
    set_crmode();
    signal(SIGINT,f);
    while(1){
        printf("hello\n");
        sleep(1);
    }
}
void f(int signum){
    char input;
    printf("    interrupted! OK to quit(y/n)?");
    fflush(stdout);
    while((input=getchar())!=EOF){
        if(input == 'n'){
            return;
        }
        else if(input == 'y'){
            tty_mode_restore(1);
            exit(0);
        }
    }
}
void tty_mode_restore(int how){
    static struct termios setting;
    if(!how){
        tcgetattr(0,&setting);
    }
    else{
        tcsetattr(0,TCSANOW,&setting);
    }
}
void set_crmode(){
    struct termios setting;
    tcgetattr(0,&setting);
    setting.c_lflag &= ~ICANON;
    setting.c_lflag &= ~ECHO;
    setting.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&setting);
}