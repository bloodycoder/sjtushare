#include <stdio.h>
int main(){
    int ret,mypid;
    mypid = getpid();
    fork();
    fork();
    fork();
    printf("Before: my pid is %d\n",getpid());
}