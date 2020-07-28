#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "smsh.h"
#define DFL_PROMPT ">"
int main(){
    char *cmdline,*prompt,**arglist;
    int result;
    void setup();
    prompt = DFL_PROMPT;
    setup();
    while((cmdline = next_cmd(prompt,stdin))!= NULL){
        if((arglist = splitline(cmdline))!=NULL){
            result = execute(arglist);
            freelist(arglist);
        }
        free(cmdline);
    }
    return 0;

}
void setup(){
    signal(SIGINT,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
}
void fatal(char *s1,char *s2,int n){
    fprintf(stderr,"Error: %s,%s\n",s1,s2);
    exit(n);
}
int execute(char *argv[]){
    int pid;
    int child_info = -1;
    if(argv[0] == NULL)
        return 0;
    if((pid = fork()) == -1)
        perror("fork");
    else if(pid == 0){
        signal(SIGINT,SIG_DFL);
        signal(SIGQUIT,SIG_DFL);
        execvp(argv[0],argv);
        perror("cannot execute command");
        exit(1);
    }
    else{
        if(wait(&child_info) == -1){
            perror("wait");
        }
        return child_info;
    }
}