#include <stdio.h>
#include <termios.h>
#define QUESTION "Do you want another transaction"
int get_response(char *);
void set_crmode();
void tty_mode_restore(int);
int main(){
    int response;
    tty_mode_restore(0);
    set_crmode();
    response = get_response(QUESTION);
    printf("response is %d",response);
    tty_mode_restore(1);
    return response;
}
int get_response(char *question){
    char input;
    printf("%s (y/n)",question);
    while(1){
        switch(input = getchar()){
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
        }
    }
}
void set_crmode(){
    //set no buffer
    struct termios ttystate;
    tcgetattr(0,&ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&ttystate);
}
void tty_mode_restore(int how){
    static struct termios original_mode;
    if(!how)
        tcgetattr(0,&original_mode);
    else
        tcsetattr(0,TCSANOW,&original_mode);
}