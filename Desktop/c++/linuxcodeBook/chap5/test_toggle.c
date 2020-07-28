#include <termios.h>
int main(){
    struct termios settings;
    tcgetattr(0,&settings);
    settings.c_lflag
}