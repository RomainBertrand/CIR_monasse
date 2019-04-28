#include "piece.h"
#include "plateau.h"
#include "cmath"

Piece::Piece(Case case_depart, int col){
    couleur = col;
    c = case_depart;
}

void Piece::bouge(Case case_arrivee){
    c=case_arrivee;
}

std::string Piece::get_name(){
    return name;
}

// il faut appeler un accesseur sur le plateau qui répond si la case est vide sur le chemain dans permission_bouge.
// pas de plateau publique !!!!

// Gestion des déplacements possibles

bool Roi::permission_bouge(Case case_arrive) const {
    if (case_arrive.distance(c)==1) return true;
    else return false;
}

bool Dame::permission_bouge(Case case_arrive) const { // déplacement du fou OU de la tour
    if ((case_arrive.x == c.x || case_arrive.y == c.y) || (abs(case_arrive.x-c.x)==0 && abs(case_arrive.y-c.y)==0)) return true;
    else return false;
}

bool Cavalier::permission_bouge(Case case_arrive) const {
    if (abs(case_arrive.x-c.x)*abs(case_arrive.y-c.y)==2) return true;
    else return false;
}

bool Fou::permission_bouge(Case case_arrive) const {
    if (abs(case_arrive.x-c.x)==0 && abs(case_arrive.y-c.y)==0) return true;
    else return false;
}

bool Tour::permission_bouge(Case case_arrive) const {
    if (case_arrive.x == c.x || case_arrive.y == c.y) return true;
    else return false;
}

bool Pion::permission_bouge(Case case_arrive) const { // les noirs en haut les blanc en bas
    if (couleur==0 && case_arrive.y-c.y==1) return true;
    else if (couleur==1 && c.y-case_arrive.y==1) return true;
    else return false;
}

// Gestion des constructeurs des sous classes

Roi::Roi(Case c, int couleur) : Piece(c,couleur){}
Dame::Dame(Case c, int couleur) : Piece(c,couleur){}
Cavalier::Cavalier(Case c, int couleur) : Piece(c,couleur){}
Fou::Fou(Case c, int couleur) : Piece(c,couleur){}
Tour::Tour(Case c, int couleur) : Piece(c,couleur){}
Pion::Pion(Case c, int couleur) : Piece(c,couleur){}
