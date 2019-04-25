#include "case.h"
#include <algorithm>
#include <cstdlib>

Case::Case(){};

Case::Case(int i, int j){
    x=i;
    y=j;
};

int Case::distance(Case c_prime){
    return std::max(abs(c_prime.x - x), abs(c_prime.y -y));
}
