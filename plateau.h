#pragma once
#include "piece.h"
#include "case.h"
#include "graphics.h"


class Plateau {
    Piece** plateau; // On met le plateau en privée, si une pièce veut checker qu'elle peut bouger on demande le reseignement au tableau avec une méthode
public:
    Plateau();
    ~Plateau();
    void affiche();
    void bouge(Piece* p, Case c); // bouge une piece
    bool permission_bouge(Piece* p, Case c); // renvoie true si l'on peut bouger la pièce
    Piece* get(Case c) const; // accesseur du plateau
    void set(Piece* p, Case c);
};
