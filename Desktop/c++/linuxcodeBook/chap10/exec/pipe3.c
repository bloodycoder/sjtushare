#include <stdio.h>
#include <unistd.h>
#define MAXPIPE 100
#define oops(m,x){perror(m);exit(x);}
int main(int ac,char ** av){
    int thepipe[MAXPIPE][2],newfd,pid;
    if(ac != 4){
        fprintf(stderr,"usage:pipe cmd1 cmd2 cmd3 \n");
        exit(1);
    }
    int pipecnt = ac-2;
    for(int i=0;i<pipecnt;i++){
        if(pipe(thepipe[i]) == -1)
            oops("pipe error",1);
    }
    for(int i=0;i<pipecnt;i++){
        if((pid = fork())==-1){
            oops("cannot fork",2);
        }
        if(pid == 0){
            //son 
                //redirect read redirect write
            close(thepipe[i][1]);
            if(dup2(thepipe[i][0],0) == -1)
                oops("could not redirect stdin",3);
            close(thepipe[i][0]);
            if(i!=pipecnt-1){
                //redirect write
                close(thepipe[i+1][0]);
                if(dup2(thepipe[i+1][1],1) == -1)
                    oops("could not redirect stdout",5);
                close(thepipe[i+1][1]);
            }
            execlp(av[i+1],av[i+1],NULL);
            oops("run son error",6);
        }
    }
    close(thepipe[0][0]);  //close read
    if(dup2(thepipe[0][1],1) == -1)
        oops("could not redirect stdout",5);
    close(thepipe[0][1]);
    execlp(av[1],av[1],NULL);
    oops(av[1],6);
}