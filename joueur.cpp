#include "joueur.h"
#include "plateau.h"

Joueur::Joueur(Plateau& p, int col){
    color = col;
    boite = new Piece*[8*2];
    for(int i=col*5;i<col*5+2;i++){ // tiens compte de la couleur pour remplir la boite avec les bonnes pièces
        for(int j=0;j<8;j++){
            boite[j*8+i]=p.get(Case(j,i));
        }
    }
}
Joueur::~Joueur(){
    delete [] boite;
}
