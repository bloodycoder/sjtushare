#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <fcntl.h>
#include <math.h>
#define oops(a,v){perror(a);exit(v);}
void f(int);
int maxvalue = 2;
int judge(int value){
    for(int i=2;i<=sqrt(value);i++){
        if(value%i==0){
            return 1;
        }
    }
    return 0;
}
int main(int argc,char ** argv){
    signal(SIGINT,f);
    int initial = 3;
    while(1){
        if(judge(initial))
            maxvalue = initial;
        initial++;
    }
}
void f(int signum){
    printf("%d\n",maxvalue);
}