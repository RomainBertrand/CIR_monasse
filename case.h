#pragma once

class Case {
    int x;
    int y;
public:
    Case();
    Case(int i, int j);
    Case(char a, int k);
    void set(int i, int j){x=i;y=j;}
    int get(int a) const;
    int distance(Case cprime);
    Case operator+(Case c1);
    bool operator==(Case c1);
};
