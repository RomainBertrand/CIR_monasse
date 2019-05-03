#include "graphics.h"
#include "case.h"
using namespace std;
#include <string.h>

/*******************
 * tools functions *
 ******************/
void coord(Case c, int&x, int&y){
    x = (c.get(0))*SPACE+MARGIN;
    y = (7-c.get(1))*SPACE+MARGIN;
}

Color color_case(Case c){
    return BOARD_COLORS[(c.get(0)+c.get(1))%2];
}

std::string get_path_image(Piece* p){
    string col = string(1, "bw"[p->get_color()]); //b = black = 0, w = white = 1
    string s = col+p->get_name();
    return stringSrcPath("img/"+to_string(SPACE)+"/"+s+".png");
}

/*********************
 * grpahic functions *
 ********************/

void display_grid_empty(){
    int W = (8)*(SPACE)+2*MARGIN;
    int H = (8)*SPACE+2*MARGIN;
    openWindow(W, H, "Chessboard");
    string columns = "ABCDEFGH";
    string rows = "87654321";
    for (int i=0; i < 8;i++){
        // rows and columns
        int x = MARGIN + i*SPACE+SPACE/2;
        int y1 = MARGIN/2;
        int y2 = MARGIN/2+MARGIN+8*SPACE;
        int dx = 2*FONT_SIZE/7;
        int dy = FONT_SIZE/2;
        drawString(x-dx, y1+dy, string(1, columns[i]), BLACK, FONT_SIZE);
        drawString(x-dx, y2+dy, string(1, columns[i]), BLACK, FONT_SIZE);
        drawString(y1-dx, x+dy, string(1, rows[i]), BLACK, FONT_SIZE);
        drawString(y2-dx, x+dy, string(1, rows[i]), BLACK, FONT_SIZE);

        // cases
        for (int j= 0; j < 8;j++){
            clr_case(Case(i, j));
        }
    }
}

void display_piece(Case c, Piece* p){
    Image<AlphaColor> im; // Image en niveaux de gris
    string file = get_path_image(p);
    if (! load(im, file)) {
        cerr << "Impossible d’ouvrir le fichier " << file << endl ;
        exit (1);
    }
    int x, y;
    coord(c, x, y);
    display(im, x, y, false);
}
void clr_case(Case c){
    int x, y;
    coord(c, x, y);
    fillRect(x, y, SPACE, SPACE, color_case(c));
}
void go_to(Case c1, Case c2, Piece* p){
    clr_case(c1);
    display_piece(c2, p);
}

void display_board(Plateau* board){
    for (int j=0;j<8;j++){
        for (int i=0;i<8;i++){
            Case c(i, j);
            clr_case(c);
            Piece* p = board->get(c);
            if (p != nullptr){
                display_piece(c, p);
            }
        }
    }
}
