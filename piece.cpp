#include "piece.h"
#include "plateau.h"
#include "cmath"

Piece::Piece(Case case_depart, int col){
    couleur = col;
    c = case_depart;
}

void Piece::bouge(Plateau &p,Case case_arrivee){
    c=case_arrivee; // on doit actualiser la position de la pièce et appeler la méthode bouge du plateau (pas encode codée)
    //p.p[8*case_arrivee.y+case_arrivee.x]=p.p[8*c.y+c.x];
    //p.p[8*c.y+c.x]=0:
}

// il faut appeler un accesseur sur le plateau qui répond si la case est vide sur le chemain dans permission_bouge.
// pas de plateau publique !!!!

// Gestion des déplacements possibles

bool Roi::permission_bouge(const Plateau &p, Case case_arrive) const {
    if (case_arrive.distance(c)==1) return true;
    else return false;
}

bool Dame::permission_bouge(const Plateau &p,Case case_arrive) const { // déplacement du fou OU de la tour
    if ((case_arrive.x == c.x || case_arrive.y == c.y) || (abs(case_arrive.x-c.x)==0 && abs(case_arrive.y-c.y)==0)) return true;
    else return false;
}

bool Cavalier::permission_bouge(const Plateau &p,Case case_arrive) const {
    if (abs(case_arrive.x-c.x)*abs(case_arrive.y-c.y)==2) return true;
    else return false;
}

bool Fou::permission_bouge(const Plateau &p, Case case_arrive) const {
    if (abs(case_arrive.x-c.x)==0 && abs(case_arrive.y-c.y)==0) return true;
    else return false;
}

bool Tour::permission_bouge(const Case case_arrive) const {
    if (case_arrive.x == c.x || case_arrive.y == c.y) return true;
    else return false;
}

bool Pion::permission_bouge(const Plateau &p, Case case_arrive) const { // les noirs en haut les blanc en bas
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
