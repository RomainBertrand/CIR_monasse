#include <iostream>
using namespace std;
#include "case.h"
#include "joueur.h"
#include "piece.h"
#include "plateau.h"

int main()
{
    Plateau p;
    display_grid_empty();
    display_board(&p);
    /**********************************************
    **************** TEST XORMODE *****************
    **********************************************/
    Image<AlphaColor> im; // Image en niveaux de gris
    string file = stringSrcPath("img/90/broi.png");
    if (! load(im, file)) {
        cerr << "Impossible d’ouvrir le fichier " << file << endl ;
        exit (1);
    }
    display(im, MARGIN+3*SPACE, MARGIN+3*SPACE, true);
    display(im, MARGIN+3*SPACE, MARGIN+4*SPACE, true);
    p.affiche();
    click();
    // fillRect(MARGIN/2+3*SPACE, MARGIN/2+3*SPACE, SPACE, SPACE, RED, true);
    display(im, MARGIN+3*SPACE, MARGIN+3*SPACE, true);

    /**********************************************
    ***********  FIN TEST XORMODE *****************
    **********************************************/
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
