#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#define LINELEN 512
int see_more();
void do_more(FILE *);
int pagelen;
void tty_mode_restore(int);
void set_crmode();
int main(int argc, char * argv[]){
    FILE *fp;
    struct winsize wbuf;
    tty_mode_restore(0);
    set_crmode();
    signal(SIGINT,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
    if(ioctl(0,TIOCGWINSZ,&wbuf)!=-1){
        pagelen = wbuf.ws_row;
    }
    else
        pagelen = 24;
    if(argc == 1){
        do_more(stdin);
    }
    else{
        while(--argc){
            if((fp = fopen(*++argv,"r"))!=NULL){
                do_more(fp);
                fclose(fp);
            }
            else{
                tty_mode_restore(1);
                exit(1);
            }
        }
    }
    tty_mode_restore(1);
}
void do_more(FILE *fp){
    char line[LINELEN];
    int num_of_lines = 0;
    int reply;
    FILE *fp_tty;
    fp_tty = fopen("/dev/tty","r");
    if(fp_tty == NULL)
        exit(1);
    while(fgets(line,LINELEN,fp)){
        if(num_of_lines == pagelen){
            //full screen 
            reply = see_more(fp_tty);
            if(reply == 0){
                break;
            }
            num_of_lines -= reply;
        }
        if(fputs(line,stdout)==EOF){
            tty_mode_restore(1);
            exit(1);
        }
        num_of_lines++;
    }
}
int see_more(FILE*fp){
    int c;
    while((c=getc(fp))!=EOF){
        if(c=='q'){
            tty_mode_restore(1);
            return 0;
        }        
        if(c==' ')
            return pagelen;
        if(c == '\n')
            return 1;
    }
    return 0;
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