#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define oops(s,x) { perror(s);exit(x);}
int main(int argc,char **argv){
    if(argc == 1){
        oops("argument err",1);
    }
    //char tty_path[50] = "/dev/";
    char* mytty = ttyname(0);
    //strcpy(tty_path+5,mytty);
    if(argv[1][0] == 'n'){
        //cchmod
        chmod(mytty,S_ISUID|S_IRWXU);
    }
    else if(argv[1][0] == 'y'){
        chmod(mytty,S_ISUID|S_IRWXU|S_IRWXG|S_IRWXO);
    }
    else{
        oops("n or y",2);
    }
    return 0;
}