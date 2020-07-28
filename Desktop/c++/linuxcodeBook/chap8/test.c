#include <stdio.h>
#include <signal.h>
#include <string.h>
int main(){
    int n;
    for(n=0;n<10;n++){
        printf("my pid =%d,n = %d\n",getpid(),n);
        sleep(1);
    }
}