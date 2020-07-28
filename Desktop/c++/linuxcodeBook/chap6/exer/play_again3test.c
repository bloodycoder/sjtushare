/*
answer for 6.3
*/
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#define ASK "Do you want another transaction"
#define TRIES 3
#define SLEEPTIME 2
#define BEEP putchar('\a')
int get_response(char *,int);
void set_crmode();
void tty_mode_restore(int);
char get_ok_char();
void set_nodelay_mode();
int main(){
    int response;
    tty_mode_restore(0);
    set_crmode();
    //set_nodelay_mode();
    response = get_response(ASK,TRIES);
    printf("response is %d",response);
    tty_mode_restore(1);
    return response;
}
int get_response(char *question,int maxtries){
    char input;
    printf("%s (y/n)",question);
    //printf("\njust for test");
    fflush(stdout);
    signal(SIGINT,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
    while(1){
        //sleep(SLEEPTIME);
        input = tolower(get_ok_char());
        if(input == 'y')
            return 0;
        if(input == 'n')
            return 1;
        if(maxtries-- == 0)
            return 2;
        BEEP;
    }
}
char get_ok_char(){
    int c;
    while((c=getchar())!=EOF && strchr("yYnN",c) == NULL);
    return c;
}
void set_crmode(){
    //set no buffer
    struct termios ttystate;
    tcgetattr(0,&ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 0;
    ttystate.c_cc[VTIME] = 20;
    tcsetattr(0,TCSANOW,&ttystate);
}
void set_nodelay_mode(){
    int termflags;
    termflags = fcntl(0,F_GETFL);
    termflags |= O_NDELAY;
    fcntl(0,F_SETFL,termflags);
}
void tty_mode_restore(int how){
    static struct termios original_mode;
    static int original_flags;
    if(!how){
        tcgetattr(0,&original_mode);    
        original_flags = fcntl(0,F_GETFL);
    }
    else{
        tcsetattr(0,TCSANOW,&original_mode);
        fcntl(0,F_SETFL,original_flags);
    }
}