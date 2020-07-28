#include <stdio.h>
#include <string.h>
#define oops(s,x) { perror(s);exit(x);}
int main(){
    FILE *fd1,*fd2;
    char *words = "picard xie\n";
    fd1 = fopen("1.md","a");
    if(fd1 == NULL){
        oops("open 1.md",1);
    }
    fd2 = fopen("1.md","a");
    if(fd2 == NULL){
        oops("open 1.md",2);
    }
    if(fputs(words,fd1)==-1){
        oops("write error",3);
    }
    if(fputs(words,fd2)==-1){
        oops("write error",3);
    }
    fclose(fd1);
    fclose(fd2);
}