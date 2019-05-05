#pragma once

class Case {
    int x;
    int y;
public:
    Case();
    Case(int i, int j);
    Case(char a, int k);
    void set(int i, int j){x=i;y=j;}
    void set(char a, int k){x=int(a)-65;y=k-1;}
    int get(int a) const;
    int distance(Case cprime);
    Case operator+(Case c1);
    bool operator==(Case c1);
};
typedef Case Deplacement;
Deplacement d_deplacement(const Case c_start, const Case c_end);
