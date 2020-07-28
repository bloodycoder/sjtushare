#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
ino_t get_inode(char *);
void inum_to_name(ino_t,char *,int);
void printpathto(ino_t);
int main(){
    printpathto(get_inode("."));
    putchar('\n');
    return 0;
}
ino_t get_inode(char *fname){
    struct stat info;
    if(stat(fname,&info) == -1){
        fprintf(stderr,"cannot stat");
        perror(fname);
        exit(1);
    }
    return info.st_ino;
}
void inum_to_name(ino_t inode_to_find,char *namebuf,int buflen){
    DIR *dir_ptr;
    struct dirent *direntp;
    dir_ptr = opendir(".");
    if(dir_ptr == NULL){
        perror(".");
        exit(1);
    }
    while((direntp=readdir(dir_ptr))!=NULL){
        if(direntp->d_ino == inode_to_find){
            strcpy(namebuf,direntp->d_name);
            closedir(dir_ptr);
            return;
        }
    }
    perror("not found");
    exit(1);
}
void printpathto(ino_t this_inode){
    ino_t father_inode;
    char its_name[BUFSIZ];
    if(get_inode("..") != this_inode){
        chdir("..");
        inum_to_name(this_inode,its_name,BUFSIZ);
        father_inode = get_inode(".");
        printpathto(father_inode);
        printf("/%s",its_name);
    }
}