#pragma once

class Case {
public:
    int x;
    int y;
    Case();
    Case(int i, int j);
    int distance(Case cprime);
    Case operator+(Case c1);
    bool operator==(Case c1)
};
