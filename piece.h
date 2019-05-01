#pragma once
#include "case.h"
#include <string>

class Plateau; //le .h a juste besoin de savoir que le plateau existe mais pas besoin des méthodes

class Piece {
protected:
    std::string name = "piece";
    int couleur; // 0 = noir, 1 = blanc
    Case c;
public:
    virtual bool permission_bouge(Case c) const {return false;} // il faut la définir
    std::string get_name();
    virtual void bouge(Case c);
    Case get(){return c;}
    Piece(Case c, int couleur);
    Piece();
    virtual ~Piece(){}
};

class Roi : public Piece {
    bool rock = true;
    std::string name = "roi" ;
public:
    Roi(Case c, int couleur);
    virtual void bouge(Case c);
    virtual bool permission_bouge(Case c) const;
    bool rocker(Case c){}
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
    bool rock = true;
    std::string name = "tour" ;
public:
    Tour(Case c, int couleur);
    virtual void bouge(Case c);
    virtual bool permission_bouge(Case c) const;
};

class Pion : public Piece {
    std::string name = "pion" ;
public:
    Pion(Case c, int couleur);
    virtual bool permission_bouge(Case c) const;
};
