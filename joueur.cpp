#include "joueur.h"
#include "plateau.h"
#include <iostream>

Joueur::Joueur(const Plateau& p, int col){
    color = col;
    boite = new Piece*[8*2];
    if(col==1){
        for(int i=0;i<2;i++){ // tiens compte de la couleur pour remplir la boite avec les bonnes pièces
            for(int j=0;j<8;j++){
                boite[j+i*8]=p.get(Case(j,i));
            }
        }
    }
    if(col==0){
        for(int i=6;i<8;i++){ // tiens compte de la couleur pour remplir la boite avec les bonnes pièces
            for(int j=0;j<8;j++){
                boite[j+(i-6)*8]=p.get(Case(j,i));
            }
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
