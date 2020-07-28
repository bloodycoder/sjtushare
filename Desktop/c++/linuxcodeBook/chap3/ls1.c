#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#define NOSORT 0
#define SORT 1
#define REVERSESORT 2
#define MAXFILES 100
void do_ls(char []);
void cmp1(char **,int);
void cmp2(char **,int);
short sort_conf;
main(int ac,char *av[]){
    sort_conf = SORT;
    if(ac == 2){
        if(strcmp(av[1],"-r") == 0){
            sort_conf = REVERSESORT;
            ac--;
            av++;
        }
        else if(strcmp(av[1],"-q") == 0){
            sort_conf = NOSORT;
            ac--;
            av++;
        }
    }
    if(ac == 1){
        do_ls(".");
    }
    else{
        while(--ac){
            printf("%s:\n",*++av);
        }
        do_ls(*av);
    }
}
void do_ls(char dirname[]){
    DIR *dir_ptr;
    struct dirent *direntp;
    char *filelist[MAXFILES];
    int start_index=0;
    if((dir_ptr = opendir(dirname)) == NULL){
        fprintf(stderr,"ls1:cannot open",dirname);
    }
    else{
        if(sort_conf == NOSORT){
            while((direntp = readdir(dir_ptr))!=NULL){
                printf("%s\n",direntp->d_name);
            }
        }
        else if(sort_conf == SORT){
            //start sort
            while((direntp = readdir(dir_ptr))!=NULL){
                filelist[start_index] = direntp->d_name;
                start_index++;
                //do sort
            }
            cmp1(filelist,start_index);
            for(int i=0;i<start_index;i++){
                printf("%s\n",filelist[i]);
            }
        }
        else if(sort_conf == REVERSESORT){
            //start sort
            while((direntp = readdir(dir_ptr))!=NULL){
                filelist[start_index] = direntp->d_name;
                start_index++;
                //do sort
            }
            cmp2(filelist,start_index);
            for(int i=0;i<start_index;i++){
                printf("%s\n",filelist[i]);
            }
        }
        closedir(dir_ptr);
    }
}
void cmp1(char *filelist[],int length){
    char *tmp;
    for(int i=length-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(strcmp(filelist[j],filelist[j+1])>0){
                tmp = filelist[j];
                filelist[j] = filelist[j+1];
                filelist[j+1] = tmp;
            }
        }
    }
}
void cmp2(char *filelist[],int length){
    char *tmp;
    for(int i=length-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(strcmp(filelist[j],filelist[j+1])<0){
                tmp = filelist[j];
                filelist[j] = filelist[j+1];
                filelist[j+1] = tmp;
            }
        }
    }
}