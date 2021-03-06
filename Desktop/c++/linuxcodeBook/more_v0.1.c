#include <stdio.h>
#define PAGELEN 24
#define LINELEN 512
int see_more();
void do_more(FILE *);
int main(int argc, char * argv[]){
    FILE *fp;
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
    while(fgets(line,LINELEN,fp)){
        if(num_of_lines == PAGELEN){
            //full screen 
            reply = see_more();
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
int see_more(){
    int c;
    while((c=getchar())!=EOF){
        if(c=='q')
            return 0;
        if(c==' ')
            return PAGELEN;
        if(c == '\n')
            return 1;
    }
    return 0;
}