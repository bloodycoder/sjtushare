#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
void do_ls(char []);
void dostat(char *);
void show_file_info(char *,struct stat* );
void mode_to_letters(int,char[]);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);
short acc = 0;
char dirname[50] = "/dev";
int len = 4;
main(int ac,char *av[]){
    do_ls(dirname);
}
void do_ls(char dirname[]){
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname)) == NULL){
        fprintf(stderr,"ls1:cannot open",dirname);
    }
    else{
        while((direntp = readdir(dir_ptr))!=NULL){
            //printf("%s\n",direntp->d_name);
            //direntp->d_name
            //direntp->d_ino;
            dostat(direntp->d_name);
        }
        closedir(dir_ptr);
    }
}
void dostat(char *filename){
    struct stat info;
    if(strncmp(filename,"tty",3) != 0){
        return;
    }
    strcpy(dirname+len,"/");
    strcpy(dirname+len+1,filename);
    if(stat(dirname,&info) == -1){
        perror(dirname);
    }
    else{
        show_file_info(filename,&info);
    }
}
void show_file_info(char *filename,struct stat* info_p){
    //char *uid_to_name(),*ctime(),*gid_to_name(),*filemode();
    char modestr[] = "----------";
    //mode_to_letters(info_p->st_mode,modestr);
    //printf("%s",modestr);
    //printf("%4d ",(int)info_p->st_nlink);
    printf("%-6s ",uid_to_name(info_p->st_uid));
    //printf("%-6s ",gid_to_name(info_p->st_gid));
    //printf("%6ld ",(long)info_p->st_size);
    //printf("%-.12s ",4+ctime(&info_p->st_ctimespec.tv_sec));
    printf("%-s ",filename);
    printf("%-.12s\n",4+ctime(&info_p->st_mtimespec.tv_sec));
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