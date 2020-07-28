#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#define LINELEN 512
int see_more();
void do_more(FILE *);
int pagelen;
int main(int argc, char * argv[]){
    FILE *fp;
    struct winsize wbuf;
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
                exit(1);
            }
        }
    }
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
            exit(1);
        }
        num_of_lines++;
    }
}
int see_more(FILE*fp){
    int c;
    while((c=getc(fp))!=EOF){
        if(c=='q')
            return 0;
        if(c==' ')
            return pagelen;
        if(c == '\n')
            return 1;
    }
    return 0;
}