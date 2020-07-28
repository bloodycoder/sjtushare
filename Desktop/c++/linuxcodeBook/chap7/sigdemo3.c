#include <stdio.h>
#include <signal.h>
#define INPUTLEN 100
int main(int ac,char *av[]){
    void inthandler(int);
    void quithandler(int);
    char input[INPUTLEN];
    int nchars;
    signal(SIGINT,inthandler);
    signal(SIGQUIT,quithandler);
    do{
        printf("\n Type a message\n");
        nchars = read(0,input,(INPUTLEN-1));
        if(nchars == -1)
            perror("read error");
        else{
            input[nchars] = '\0';
            printf("you type:%s",input);
        }
    }
    while(strncmp(input,"quit",4)!=0);
}
void inthandler(int s){
    printf("Received signal %d..waiting \n",s);
    sleep(2);
    printf(" leaving inthandler\n");
}
void quithandler(int s){
    printf("received signal %d .. waiting \n",s);
    sleep(3);
    printf(" leaving quithandler\n");
}