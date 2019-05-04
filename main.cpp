#include <iostream>
using namespace std;
#include "case.h"
#include "joueur.h"
#include "piece.h"
#include "plateau.h"
#include "graphics.h"

int main()
{
    load_all_pieces();
    Plateau p;
    click();

    p.affiche();
    cout <<p.bouge(p.get(Case(0,1)),Case(0,2)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,6)),Case(0,5)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,5)),Case(0,6)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(1,0)),Case(2,2)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(1,1)),Case(1,2)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,2)),Case(1,3)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,0)),Case(0,4)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,4)),Case(5,4)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,2)),Case(1,1)) << endl;
    p.affiche();
    return 0;
}
