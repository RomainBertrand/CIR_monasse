#include "piece.h"
#include "plateau.h"
#include "cmath"

Piece::Piece(){}

Piece::Piece(Case case_depart, int col){
    couleur = col;
    c = case_depart;
}

void Piece::bouge(Case case_arrivee){
    c=case_arrivee;
}

void Pion::bouge(Case case_arrivee){
    c=case_arrivee;
}

void Roi::bouge(Case case_arrivee){
    c=case_arrivee;
    rock=false;
}

void Tour::bouge(Case case_arrivee){
    c=case_arrivee;
    rock=false;
}

std::string Piece::get_name(){return name;}
std::string Roi::get_name(){return name;}
std::string Dame::get_name(){return name;}
std::string Fou::get_name(){return name;}
std::string Cavalier::get_name(){return name;}
std::string Tour::get_name(){return name;}
std::string Pion::get_name(){return name;}


// il faut appeler un accesseur sur le plateau qui répond si la case est vide sur le chemain dans permission_bouge.
// pas de plateau publique !!!!

// Gestion des déplacements possibles

bool Roi::permission_bouge(Case case_arrive) const {
    if (case_arrive.distance(c)==1) return true;
    else return false;
}

bool Dame::permission_bouge(Case case_arrive) const { // déplacement du fou OU de la tour
    if ((case_arrive.get(0) == c.get(0) || case_arrive.get(1) == c.get(1)) || (abs(case_arrive.get(0)-c.get(0))==0 && abs(case_arrive.get(1)-c.get(1))==0)) return true;
    else return false;
}

bool Cavalier::permission_bouge(Case case_arrive) const {
    if (abs(case_arrive.get(0)-c.get(0))*abs(case_arrive.get(1)-c.get(1))==2) return true;
    else return false;
}

bool Fou::permission_bouge(Case case_arrive) const {
    if (abs(case_arrive.get(0)-c.get(0)) == abs(case_arrive.get(1)-c.get(1))) return true;
    else return false;
}

bool Tour::permission_bouge(Case case_arrive) const {
    if (case_arrive.get(0) == c.get(0) || case_arrive.get(1) == c.get(1)) return true;
    else return false;
}

bool Pion::permission_bouge(Case case_arrive) const { // les noirs en haut les blanc en bas
    if (couleur==1 && case_arrive.get(1)-c.get(1)==1) return true;
    else if (couleur==0 && c.get(1)-case_arrive.get(1)==1) return true;
    else return false;
}

// Gestion des constructeurs des sous classes

Roi::Roi(Case c, int couleur) : Piece(c,couleur){}
Dame::Dame(Case c, int couleur) : Piece(c,couleur){}
Cavalier::Cavalier(Case c, int couleur) : Piece(c,couleur){}
Fou::Fou(Case c, int couleur) : Piece(c,couleur){}
Tour::Tour(Case c, int couleur) : Piece(c,couleur){}
Pion::Pion(Case c, int couleur) : Piece(c,couleur){}
