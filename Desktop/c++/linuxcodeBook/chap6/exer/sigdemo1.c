#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#define oops(a,v){perror(a);exit(v);}
int max_tri;
int count = 0;
int main(int argc,char ** argv){
    void f(int);
    int i;
    if(argc ==1){
        oops("wrong argument",1);
    }
    max_tri = atoi(argv[1]);
    signal(SIGINT,f);
    while(1){
        printf("hello\n");
        sleep(1);
    }
}
void f(int signum){
    count++;
    printf("OUCH");
    for(int i=0;i<count;i++)
        putchar('!');
    putchar('\n');
    if(count>=max_tri)
        exit(0);
}