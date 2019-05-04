#pragma once
#include "piece.h"
#include "case.h"
#include "graphics.h"


class Plateau {
    Piece** plateau; // On met le plateau en privé, si une pièce veut checker qu'elle peut bouger on demande le reseignement au tableau avec une méthode
public:
    Plateau();
    ~Plateau();
    void affiche() const;
    void bouge(Piece* p, Case c); // bouge une piece
    int permission_bouge(Piece* p, Case c); // renvoie 1 si l'on peut bouger la pièce. Retourne 2 si pas possible car la case est occupée, retourne 0 sinon
    void mange(Piece* p, Case c);
    bool permission_mange(Piece* p, Case c);
    Piece* get(Case c) const; // accesseur du plateau
    Piece* get(int i, int j) const;
    Piece* operator[](Case c) const;
    void set(Piece* p, Case c);
};
