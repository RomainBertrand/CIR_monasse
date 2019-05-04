#pragma once

class Piece;
class Plateau;

class Joueur {
    int color;
    Piece** boite;
public:
    Joueur (const Plateau& p, int col);
    void affiche() const;
    ~Joueur();
};
