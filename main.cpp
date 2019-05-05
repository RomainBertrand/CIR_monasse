#include <iostream>
using namespace std;
#include "case.h"
#include "joueur.h"
#include "piece.h"
#include "plateau.h"
#include "graphics.h"

int main()
{
    display_grid_empty();
    load_all_pieces();
    Plateau b;
    display_board(b);
    click();
    b.affiche();
    Case c1, c2;
    while(click_move(c1, c2)){
        b.bouge(b.get(c1), c2);
    }
    click();
    b.bouge(b.get(Case('A',2)),Case('A',3));
    click();
    b.bouge(b.get(Case('A',3)),Case('A',4));
    click();
    b.bouge(b.get(Case('A',1)),Case('A',3));
    click();
    b.bouge(b.get(Case('A',3)),Case('G',3));
    click();
    b.bouge(b.get(Case('B',1)),Case('A',3));
    click();
    b.bouge(b.get(Case('C',2)),Case('C',3));
    click();
    b.bouge(b.get(Case('D',2)),Case('D',3));
    click();
    b.bouge(b.get(Case('C',1)),Case('H',6));
    click();
    b.mange_vieux(b.get(Case('G',3)),Case('G',7));
    /*
    cout <<p.bouge(p.get(Case(0,1)),Case(0,2)) << endl;
    go_to(Case(0,1),Case(0,2), p.get(Case(0, 2)));
    click();
    cout <<p.bouge(p.get(Case(0,6)),Case(0,5)) << endl;
    go_to(Case(0,1),Case(0,2), p.get(Case(0, 2)));
    */
    click();
    return 0;
}
