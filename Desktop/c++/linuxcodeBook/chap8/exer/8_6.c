#include <stdio.h>
int main()
{
    int i;
    if(fork()!=0)
        exit(0);
    for(int i=1;i<=10;i++){
        printf("%d still here %d\n",i,getpid());
        sleep(i);
    }
    return 0;
}