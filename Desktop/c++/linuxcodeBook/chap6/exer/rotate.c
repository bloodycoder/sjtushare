#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
void tty_mode_restore(int);
void set_crmode();
int main(){
    int c;
    tty_mode_restore(0);
    set_crmode();
    signal(SIGINT,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
    while((c = getchar())!=EOF){
        if(c == 'Q'){
            tty_mode_restore(1);
            exit(0);
        }
        if(c=='z')
            c = 'a';
        else if(islower(c)){
            c++;
        }
        putchar(c);
    }
}
//canonical
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