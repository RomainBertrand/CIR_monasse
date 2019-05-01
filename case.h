#pragma once

class Case {
    int x;
    int y;
public:
    Case();
    Case(int i, int j);
    int get(int a) const;
    int distance(Case cprime);
    Case operator+(Case c1);
    bool operator==(Case c1);
};
