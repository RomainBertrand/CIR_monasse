#include "case.h"
#include <algorithm>
#include <cstdlib>

Case::Case(){};

Case::Case(int i, int j){
    x=i;
    y=j;
};

Case::Case(char a, int k){
    x=int(a)-65; // le A correspond à un 0
    y=k-1;
};

int Case::distance(Case c_prime){
    return std::max(abs(c_prime.x - x), abs(c_prime.y -y));
}

int Case::get(int a) const{
    switch (a) {
    case 0:
        return x;
    case 1:
        return y;
    default:
        return 0;
    }
}

Case Case::operator+(Case c1){
    return Case(x+c1.x,y+c1.y);
}

bool Case::operator==(Case c1){
    if (x==c1.x && y==c1.y) return true;
    else return false;
}
