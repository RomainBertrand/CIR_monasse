#pragma once

class Piece;


class Plateau {
    Piece** plateau; // On met le plateau en privée, si une pièce veut checker qu'elle peut bouger on demande le reseignement au tableau avec une méthode
public:
    Plateau ();
    ~Plateau();
    void bouge(Piece &p, Case c); // bouge une piece

};
