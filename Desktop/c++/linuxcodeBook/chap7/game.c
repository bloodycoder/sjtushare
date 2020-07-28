#include <curses.h>
#include <signal.h>
#include "game.h"
#include <string.h>
#include <sys/time.h>
void set_up();
void wrap_up();
void game_start();
int set_ticker(int);
int bounce_or_lose(struct ppball *);
void prt_welcome(int);
void prt_boarder(int);
void prt_gameover(int);
void set_up_value();
struct ppball the_ball;
struct flat the_flat;
enum GAMESTATE{
    GAMENOTSTART=1,
    GAMESTART,
    GAMEOVER
}gamestate;
int main(){
    int c;
    set_up();
    prt_welcome(0);
    prt_boarder(0);
    gamestate = GAMENOTSTART;
    while((c = getchar())!='Q'){
        if(c == 's' || c == 'S'){
            if(gamestate == GAMENOTSTART)
                game_start();
            if(gamestate == GAMEOVER){
                clear();
                prt_boarder(0);
                set_up_value();
                game_start();
            }
        }
        if(c == 'a' || c == 'A'){
            the_flat.dir = -1;
        }
        if(c == 'd' || c == 'D'){
            the_flat.dir = 1;
        }
    }
    wrap_up();
}
void game_start(){
    void all_move(int);
    gamestate = GAMESTART;
    prt_boarder(1);
    for(int y=the_flat.y_pos_l;y<=the_flat.y_pos_r;y++){
        mvaddch(BOT_ROW,y,'-');
    }
    mvaddch(the_ball.y_pos,the_ball.x_pos,the_ball.symbol);
    refresh();
    signal(SIGALRM,all_move);
    set_ticker(1000/TICKS_PER_SEC);
    prt_welcome(1);
}
void set_up_value(){
    the_ball.y_pos = Y_INIT;
    the_ball.x_pos = X_INIT;
    the_ball.y_ttg = the_ball.y_ttm = Y_TTM;
    the_ball.x_ttg = the_ball.x_ttm = X_TTM;
    the_ball.y_dir = 1;
    the_ball.x_dir = 1;
    the_ball.symbol = DFL_SYMBOL;
    the_flat.x_pos = 31;
    the_flat.y_pos_l = (LEFT_EDGE+RIGHT_EDGE)/2-FLAT_LEN/2;
    the_flat.y_pos_r = the_flat.y_pos_l+FLAT_LEN;
    the_flat.y_ttm = the_flat.y_ttg = FLAT_TTM;
    the_flat.dir = 0;
}
void set_up(){
    void ball_move(int);
    set_up_value();
    initscr();
    noecho();
    crmode();
    signal(SIGINT,SIG_IGN);
}
void prt_welcome(int how){
    static char * words = "PingPong Game.Press s to start";
    int posix = (TOP_ROW+BOT_ROW)/2;
    int posiy = (LEFT_EDGE+RIGHT_EDGE)/2 - strlen(words)/2;
    
    if(!how){
        //prt welcome
        move(posix,posiy);
        addstr(words);
        refresh();
    }
    else{
        //delete welcome
        move(posix,posiy);
        addstr("                              ");
        refresh();
    }
}
void prt_gameover(int how){
    static char * words = "Gameover.Press s to restart.Q to quit";
    int posix = (TOP_ROW+BOT_ROW)/2;
    int posiy = (LEFT_EDGE+RIGHT_EDGE)/2 - strlen(words)/2;
    
    if(!how){
        //prt welcome
        move(posix,posiy);
        addstr(words);
        refresh();
    }
    else{
        //delete welcome
        move(posix,posiy);
        addstr("                                        ");
        refresh();
    }
}
void prt_boarder(int how){
    int posix,posiy;
    if(how == 0){
        //draw all
        for(posiy = LEFT_EDGE-1;posiy<=RIGHT_EDGE+1;posiy++){
            mvaddch(TOP_ROW-1,posiy,'-');
            mvaddch(BOT_ROW+1,posiy,'-');
        }
        for(posix = TOP_ROW-1;posix<=BOT_ROW+1;posix++){
            mvaddch(posix,LEFT_EDGE-1,'|');
            mvaddch(posix,RIGHT_EDGE+1,'|');
        }
        refresh();
    }
    if(how == 1){
        for(posiy = LEFT_EDGE-1;posiy<=RIGHT_EDGE+1;posiy++){
            mvaddch(BOT_ROW+1,posiy,BLANK);
        }
    }
}
void wrap_up(){
    set_ticker(0);
    endwin();
}
void all_move(int signum){
    if(gamestate == GAMEOVER)
        return;
    void ball_move(int);
    void flat_move(int);
    flat_move(signum);
    ball_move(signum);
    //if(gamestate != GAMEOVER)
    signal(SIGALRM,all_move);
}
void flat_move(int signum){
    int y_cur,moved;
    y_cur = the_flat.y_pos_l;
    moved = 0;
    /**/
    
    /**/
    if(the_flat.y_ttm>0 && the_flat.y_ttg-- == 1){
        if(the_flat.y_pos_l <= LEFT_EDGE && the_flat.dir == -1){
            the_flat.dir = 1;
        }
        if(the_flat.y_pos_r >= RIGHT_EDGE && the_flat.dir == 1){
            the_flat.dir = -1;
        }
        the_flat.y_pos_l += the_flat.dir;
        the_flat.y_ttg = the_flat.y_ttm;
        the_flat.y_pos_r = the_flat.y_pos_l+FLAT_LEN;
        moved = 1;
    }
    if(moved){
        for(int y=y_cur;y<=y_cur+FLAT_LEN;y++){
            mvaddch(BOT_ROW,y,BLANK);
        }
        for(int y=the_flat.y_pos_l;y<=the_flat.y_pos_r;y++){
            mvaddch(BOT_ROW,y,'-');
        }
        move(LINES-1,COLS-1);
        refresh();
    }
}
void ball_move(int signum){
    int y_cur,x_cur,moved;
    signal(SIGALRM,SIG_IGN);
    y_cur = the_ball.y_pos;
    x_cur = the_ball.x_pos;
    moved = 0;
    if(the_ball.y_ttm>0 && the_ball.y_ttg-- == 1){
        the_ball.y_pos += the_ball.y_dir;
        the_ball.y_ttg = the_ball.y_ttm;
        moved = 1;
    }
    if(the_ball.x_ttm>0 && the_ball.x_ttg-- == 1){
        the_ball.x_pos += the_ball.x_dir;
        the_ball.x_ttg = the_ball.x_ttm;
        moved = 1;
    }
    if(moved){
        mvaddch(y_cur,x_cur,BLANK);
        mvaddch(y_cur,x_cur,BLANK);
        mvaddch(the_ball.y_pos,the_ball.x_pos,the_ball.symbol);
        int ret = bounce_or_lose(&the_ball);
        if(ret == -1){
            prt_gameover(0);
            gamestate = GAMEOVER;
            signal(SIGALRM,NULL);
        }
        move(LINES-1,COLS-1);
        refresh();
    }
    signal(SIGALRM,all_move);
}
int set_ticker(int n_msecs){
    struct itimerval new_timeset;
    long n_sec,n_usecs;
    n_sec = n_msecs/1000;
    n_usecs = (n_msecs%1000)*1000;
    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usecs;
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;
    return setitimer(ITIMER_REAL,&new_timeset,NULL);
}
int bounce_or_lose(struct ppball *bp){
    int return_val = 0;
    if(bp->y_pos == TOP_ROW){
        bp->y_dir = 1;
        return_val = 1;
    }else if(bp->y_pos == BOT_ROW){
        bp->y_dir = -1;
        if(bp->x_pos<the_flat.y_pos_l || bp->x_pos>the_flat.y_pos_r){
            return -1;
        }
        return_val = 1;
    }
    if(bp->x_pos == LEFT_EDGE){
        bp->x_dir = 1;
        return_val = 1;
    }
    else if(bp->x_pos == RIGHT_EDGE){
        bp->x_dir = -1;
        return_val = 1;
    }
    return return_val;
}