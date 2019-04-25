#include <case.h>

class Piece {
    Piece* p;
public:
    int couleur; // 0 = noir, 1 = blanc
    Case c;
    virtual const bool permission_bouge(Case c);
    void bouge(Case c);
    Piece();
    Piece(Case c, int couleur);
    ~Piece();
};

class Roi : public Piece {
    virtual const bool permission_bouge(Case c);
    bool rock(Case c);
};

class Dame : public Piece {
    virtual const bool permission_bouge(Case c);
};

class Fou : public Piece {
    virtual const bool permission_bouge(Case c);
};

class Cavalier : public Piece {
    virtual const bool permission_bouge(Case c);
};

class Tour : public Piece {
    virtual const bool permission_bouge(Case c);
};

class Pion : public Piece {
    virtual const bool permission_bouge(Case c);
};
