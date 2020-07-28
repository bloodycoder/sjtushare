#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
/*
添加了ls 文件夹功能.
*/
void do_normal_ls(char []);
void do_ls(char*);
void dostat(char*,char*);
void show_file_info(char *,struct stat* );
void mode_to_letters(int,char[]);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);
main(int ac,char *av[]){
    if(ac == 1){
        do_normal_ls(".");
    }
    else{
        while(--ac){
            printf("%s:\n",*++av);
            do_ls(*av);
        }
    }
}
void do_normal_ls(char dirname[]){
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname)) == NULL){
        fprintf(stderr,"ls1:cannot open",dirname);
    }
    else{
        while((direntp = readdir(dir_ptr))!=NULL){
            dostat(direntp->d_name,direntp->d_name);
        }
        closedir(dir_ptr);
    }
}
void do_ls(char dirname[]){
    DIR *dir_ptr;
    struct dirent *direntp;
    int dirlen = strlen(dirname);
    if((dir_ptr = opendir(dirname)) == NULL){
        fprintf(stderr,"ls1:cannot open",dirname);
    }
    else{
        char newpath[100];
        strncpy(newpath,dirname,dirlen);
        strncpy(newpath+dirlen,"/",1);
        while((direntp = readdir(dir_ptr))!=NULL){
            strcpy(newpath+dirlen+1,direntp->d_name);
            dostat(newpath,direntp->d_name);
        }
        closedir(dir_ptr);
    }
}
void dostat(char *filepath,char *filename){
    struct stat info;
    if(stat(filepath,&info) == -1){
        perror(filepath);
    }
    else{
        show_file_info(filename,&info);
    }

}
void show_file_info(char *filename,struct stat* info_p){
    //char *uid_to_name(),*ctime(),*gid_to_name(),*filemode();
    char modestr[] = "----------";
    mode_to_letters(info_p->st_mode,modestr);
    printf("%s",modestr);
    printf("%4d ",(int)info_p->st_nlink);
    printf("%-6s ",uid_to_name(info_p->st_uid));
    printf("%-6s ",gid_to_name(info_p->st_gid));
    printf("%6ld ",(long)info_p->st_size);
    printf("%-.12s ",4+ctime(&info_p->st_ctimespec.tv_nsec));
    printf("%-s\n",filename);
}
void mode_to_letters(int mode,char str[]){
    if(S_ISDIR(mode))str[0] = 'd';
    if(S_ISCHR(mode))str[0] = 'c';
    if(S_ISBLK(mode))str[0] = 'b';

    if(mode & S_IRUSR) str[1] = 'r';
    if(mode & S_IWUSR) str[2] = 'w';
    if(mode & S_IXUSR) str[3] = 'x';
    if(mode & S_IRGRP) str[4] = 'r';
    if(mode & S_IWGRP) str[5] = 'w';
    if(mode & S_IXGRP) str[6] = 'x';
    if(mode & S_IROTH) str[7] = 'r';
    if(mode & S_IWOTH) str[8] = 'w';
    if(mode & S_IXOTH) str[9] = 'x';
}
#include <pwd.h>
char *uid_to_name(uid_t uid){
    struct passwd *getpwuid(), *pw_ptr;
    static char numstr[10];
    if((pw_ptr = getpwuid(uid)) == NULL){
        sprintf(numstr,"%d",uid);
        return numstr;
    }
    else{
        return pw_ptr->pw_name;
    }
}
#include <grp.h>
char *gid_to_name(gid_t gid){
    struct group *getgrgid(),*gp_ptr;
    static char numstr[10];
    if((gp_ptr = getgrgid(gid)) == NULL){
        sprintf(numstr,"%d",gid);
        return numstr;
    }
    else{
        return gp_ptr->gr_name;
    }
}