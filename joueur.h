#pragma once

class Piece;
class Plateau;

class Joueur {
    int color;
    Piece** boite;
public:
    Joueur (Plateau& p, int col);
    ~Joueur();
};
