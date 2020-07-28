#include <fcntl.h>
#define FD 0
#define oops(s,x) { perror(s);exit(x);}
int main(){
    int s;
    s = fcntl(FD,F_GETFL);
    s |= O_SYNC;
    int result = fcntl(FD,F_SETFL,s);
    if(result == -1){
        oops("setting SYNC",1);
    }
}

