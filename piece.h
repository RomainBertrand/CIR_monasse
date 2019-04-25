#pragma once
#include "case.h"

class Plateau; //le .h a juste besoin de savoir que le plateau existe mais pas besoin des méthodes

class Piece {
public:
    int couleur; // 0 = noir, 1 = blanc
    Case c;
    virtual bool permission_bouge(Plateau &p,Case c) const;
    void bouge(Plateau &p,Case c);
    Piece(Case c, int couleur);
    virtual ~Piece(){}
};

class Roi : public Piece {
public:
    Roi(Case c, int couleur);
    virtual bool permission_bouge(const Plateau &p,Case c) const;
    bool rock(Case c);
};

class Dame : public Piece {
public:
    Dame(Case c, int couleur);
    virtual bool permission_bouge(const Plateau &p,Case c) const;
};

class Fou : public Piece {
public:
    Fou(Case c, int couleur);
    virtual bool permission_bouge(const Plateau &p,Case c) const;
};

class Cavalier : public Piece {
public:
    Cavalier(Case c, int couleur);
    virtual bool permission_bouge(const Plateau &p,Case c) const;
};

class Tour : public Piece {
public:
    Tour(Case c, int couleur);
    virtual bool permission_bouge(const Plateau &p,Case c) const;
};

class Pion : public Piece {
public:
    Pion(Case c, int couleur);
    virtual bool permission_bouge(const Plateau &p,Case c) const;
};
