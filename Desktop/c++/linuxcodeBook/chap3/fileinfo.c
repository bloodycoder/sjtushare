#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int ac,char *av[]){
    struct stat info;
    if(ac>1){
        if(stat(av[1],&info) != -1){
            show_stat_info(av[1],&info);
            return 0;
        }
        else{
            perror(av[1]);
        }
    }
    return 1;
}
show_stat_info(char* fname,struct stat* statname){
    printf("mode :%o\n",statname->st_mode);
    printf("links:%d\n",statname->st_nlink);
    printf("user:%d",statname->st_uid);
    printf("group:%d\n",statname->st_gid);
    printf("size:%d\n",statname->st_size);
    printf("modtime:%d\n",statname->st_mtime);
    printf("name:%s\n",fname);
}
void mode_to_letters(int mode,char str[]){
    if(S_ISDIR(mode)) str[0] = 'd';
    
}