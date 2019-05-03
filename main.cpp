#include <iostream>
using namespace std;
#include "case.h"
#include "joueur.h"
#include "piece.h"
#include "plateau.h"

int main()
{
    Plateau b;
    b.affiche();
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
    b.mange(b.get(Case('G',3)),Case('G',7));
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
