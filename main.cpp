#include <iostream>
using namespace std;
#include "case.h"
#include "joueur.h"
#include "piece.h"
#include "plateau.h"

int main()
{
    Plateau p;
    p.affiche();
    click();
    cout <<p.bouge(p.get(Case(0,1)),Case(0,2)) << endl;
    go_to(Case(0,1),Case(0,2), p.get(Case(0, 2)));
    p.affiche();
    click();
    cout <<p.bouge(p.get(Case(0,6)),Case(0,5)) << endl;
    p.affiche();
    click();
    return 0;
}
