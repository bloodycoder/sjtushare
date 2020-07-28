#include <stdio.h>
#include <termios.h>
#define oops(s,x) { perror(s);exit(x);}
struct flaginfo{int fl_value;char *fl_name};
void showbaud(int);
void show_some_flags(struct termios *);
void show_flagset(int,struct flaginfo[]);
int main(){
    struct termios ttyinfo;
    if(tcgetattr(0,&ttyinfo) == -1){
        oops("tcgetarttr",1);
    }
    showbaud(cfgetospeed(&ttyinfo));
    printf("the erase character is ascii %d,Ctrl-%c\n",ttyinfo.c_cc[VERASE],ttyinfo.c_cc[VERASE]-1+'A');
    printf("the line kill character is ascii %d,Ctrl-%c\n",ttyinfo.c_cc[VKILL],ttyinfo.c_cc[VKILL]-1+'A');
    show_some_flags(&ttyinfo);
}
void showbaud(int thespeed){
    printf("the baud rate is %d\n",thespeed);
    /*
    switch(thespeed){
        case B300: printf("");
    }*/
}
struct flaginfo input_flags[] = {
    IGNBRK,"ignore break condition",
    BRKINT,"Signal interrupt on break",
    IGNPAR,"ignore chars with parity errors",
    PARMRK,"mark parity errors",
    INPCK,"enable input parity check",
    IGNCR,"ignore cr",
    ICRNL,"map CR to NL on input",
    IXON,"enable start/stop",
    0,NULL
};
struct flaginfo local_flags[] = {
    ISIG,"Enable signals",
    ICANON,"canonical input",
    ECHO,"enable echo",
    ECHOE,"Echo Erase as BS-SPACE-BS",
    ECHOK,"Echo KIll by starting new line",
    0,NULL
};
void show_some_flags(struct termios *ttyp){
    show_flagset(ttyp->c_iflag,input_flags);
    show_flagset(ttyp->c_lflag,local_flags);
}
void show_flagset(int thevalue,struct flaginfo thebitnames[]){
    int i;
    for(i=0;thebitnames[i].fl_value;i++){
        printf("  %s is ",thebitnames[i].fl_name);
        if(thevalue & thebitnames[i].fl_value){
            printf("ON\n");
        }
        else{
            printf("OFF\n");
        }
    }
}