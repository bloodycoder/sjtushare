#include <stdio.h>
int main(){
    int ret,mypid;
    mypid = getpid();
    printf("Before: my pid is %d",mypid);
    //_6fflush(stdout);
    ret = fork();
    //sleep(1);
    printf("\n my pid is %d ret value is %d\n",getpid(),ret);
}