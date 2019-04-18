#include "graphics.h"
using namespace std;

Case::Case(){};

Case::Case(int a,int b){
    i = a;
    j = b;
}

void Coord(Case c, int&x, int&y){
    x = (c.i)*space+space/2;
    y = (c.j)*space+space/2;
}

void DisplayGrid(){
    int W = (8)*(space);
    int H = (8)*(space);
    openWindow(W, H, "Automate");
    for (int i=0; i < 8;i++){
        for (int j= 0; j < 8;j++){
            if ((i+j) % 2 == 1){
                fillRect(i*space, j*space, space, space, Gray);
            }
        }
    }
}
void MakeCircle(Case c, Color col, int r){
    int x, y;
    Coord(c, x, y);
    fillCircle(x, y, r, col);
}
void DisplayRobot(Case c){
    MakeCircle(c, col_robot);
}
void ExitCase(Case c){
    MakeCircle(c, col_case);
}
void GoTo(Case c1, Case c2){
    ExitCase(c1);
    DisplayRobot(c2);
}
