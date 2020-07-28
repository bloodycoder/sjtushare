#define BLANK ' '
#define DFL_SYMBOL 'O'
#define TOP_ROW 1
#define BOT_ROW 31
#define LEFT_EDGE 10
#define RIGHT_EDGE 70
#define X_INIT 10
#define Y_INIT 10
#define TICKS_PER_SEC 50
#define X_TTM 3
#define Y_TTM 3
#define FLAT_TTM 2
#define FLAT_LEN 5
struct ppball{
    int y_pos,x_pos,
        y_ttm,x_ttm,   /* fixed number */
        y_ttg,x_ttg,   /* 动态          */
        y_dir,x_dir;
    char symbol;
};
struct flat{
    int y_pos_l,y_pos_r,x_pos,
        y_ttm,y_ttg;
    int dir;
};