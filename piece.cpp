#include "piece.h"

Piece::Piece(Case case_depart, int col){
    couleur = col;
    c = case_depart;
}

void Piece::bouge(Case case_arrivee){
    c=case_arrivee;
}

// Gestion des pas possibles

bool Roi::permission_bouge(Case case_arrive) const {
    if (case_arrive.distance(c)==1) return true;
    else return false;
}

bool Dame::permission_bouge(Case case_arrive) const {
    if (case_arrive.distance(c)==1) return true;
    else return false;
}

// Gestion des constructeurs des sous classes

Roi::Roi(Case c, int couleur) : Piece(c,couleur){}
Dame::Dame(Case c, int couleur) : Piece(c,couleur){}
Cavalier::Cavalier(Case c, int couleur) : Piece(c,couleur){}
Fou::Fou(Case c, int couleur) : Piece(c,couleur){}
Tour::Tour(Case c, int couleur) : Piece(c,couleur){}
Pion::Pion(Case c, int couleur) : Piece(c,couleur){}
