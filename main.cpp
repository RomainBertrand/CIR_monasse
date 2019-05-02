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
    cout <<p.bouge(p.get(Case(0,1)),Case(0,2)) << endl;
    p.affiche();
    cout <<p.bouge(p.get(Case(0,6)),Case(0,5)) << endl;
    p.affiche();
    return 0;
}
