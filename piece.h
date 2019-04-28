#pragma once
#include "case.h"
#include <string>
// name

class Plateau; //le .h a juste besoin de savoir que le plateau existe mais pas besoin des méthodes

class Piece {
    std::string name = "piece";
public:
    int couleur; // 0 = noir, 1 = blanc
    Case c;
    virtual bool permission_bouge(Case c) const;
    std::string get_name();
    void bouge(Case c);
    Piece(Case c, int couleur);
    virtual ~Piece(){}
};

class Roi : public Piece {
    std::string name = "roi" ;
public:
    Roi(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
    bool rock(Case c);
};

class Dame : public Piece {
    std::string name = "dame" ;
public:
    Dame(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
};

class Fou : public Piece {
    std::string name = "fou" ;
public:
    Fou(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
};

class Cavalier : public Piece {
    std::string name = "cavalier" ;
public:
    Cavalier(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
};

class Tour : public Piece {
    std::string name = "tour" ;
public:
    Tour(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
};

class Pion : public Piece {
    std::string name = "pion" ;
public:
    Pion(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
};
