#include "joueur.h"
#include "plateau.h"
#include <iostream>

Joueur::Joueur(const Plateau& p, int col){
    color = col;
    boite = new Piece*[8*2];
    for(int j=0;j<2;j++){ // tiens compte de la couleur pour remplir la boite avec les bonnes pièces
        for(int i=0;i<8;i++){
            boite[i+j*8]=p.get(Case(i,j+6*((col+1)%2)));
        }
    }
}
Joueur::~Joueur(){
    delete [] boite;
}

void Joueur::affiche(){
    std::cout << "DEBUT AFFICHE JOUEUR" << std::endl;
    for(int i=0;i<8*2;i++) std::cout << boite[i] << std::endl;
    std::cout <<"FIN AFFICHE JOUEUR" << std::endl;
}
