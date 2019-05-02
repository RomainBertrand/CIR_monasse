#pragma once
#include "piece.h"
#include "case.h"
#include "graphics.h"


class Plateau {
    Piece** plateau; // On met le plateau en privé, si une pièce veut checker
    // qu'elle peut bouger on demande le renseignement au tableau avec une méthode
public:
    Plateau();
    ~Plateau();
    void affiche();
    bool bouge(Piece* p, Case c); // bouge une piece
    Piece* get(Case c) const; // accesseur du plateau
    void set(Piece* p, Case c);
};
