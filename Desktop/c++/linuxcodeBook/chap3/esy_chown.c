#include <unistd.h>
#include <uuid/uuid.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
int main(int argc,char **argv){
    if(argc<3){
        fprintf(stderr,"usage username/uid filename");
        return -1;
    }
    short is_uid = 1;
    uid_t uid = 0;
    struct passwd * pas_struct;
    for(int i=0;i<strlen(argv[1]);i++){
        if(argv[1][i]<'0' || argv[1][i]>'9'){
            is_uid = 0;
            break;
        }
        uid = uid*10+argv[1][i]-'0';
    }
    if(!is_uid){
        pas_struct = getpwnam(argv[1]);
    }
    else{
        pas_struct = getpwuid(uid);
    }
    if(pas_struct == NULL){
        fprintf(stderr,"user not exist");
        return -1;
    }
    uid = pas_struct->pw_uid;
    for(int i=2;i<argc;i++){
        chown(argv[i],uid,0);
    }
    return 0;
}