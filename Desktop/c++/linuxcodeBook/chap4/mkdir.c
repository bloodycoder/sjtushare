#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
short p_flag = 0;
void do_mkdir(char *);
int main(int argc,char *argv[]){
    int dir_cnt = 0;
    if(argc >= 3 && strcmp(argv[1],"-p")==0){
        p_flag = 1;
        argc--;
        argv++;
    }
    while(--argc){
        do_mkdir(*++argv);
    }
    return 0;
}
void do_mkdir(char * str){
    char dir_names[50][50];
    int dir_cnt = 0;
    int init_index = 0;
    int total_length = strlen(str);
    mode_t mode = 0777;
    for(int i=0;i<total_length;i++){
        if(str[i] == '/'){
            strncpy(dir_names[dir_cnt++],str+init_index,i-init_index);
            strcpy(dir_names[dir_cnt-1]+i-init_index,"\0");
            init_index = i+1;
        }
        else if(i == total_length-1){
            strncpy(dir_names[dir_cnt++],str+init_index,i-init_index+1);
            strcpy(dir_names[dir_cnt-1]+i-init_index+1,"\0");
        }
    }
    for(int i=0;i<dir_cnt;i++){
        int result = mkdir(dir_names[i],mode);
        if(result == -1){
            perror("mkdir error %s",dir_names[i]);
            exit(1);
        }
        result = chdir(dir_names[i]);
        if(result == -1){
            perror("chdir error %s",dir_names[i]);
            exit(1);
        }      
    }
}