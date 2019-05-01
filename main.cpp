#include <iostream>
using namespace std;
#include "case.h"
#include "joueur.h"
#include "piece.h"
#include "plateau.h"

int main()
{
    Plateau p;
    Joueur j1(p,0);
    Joueur j2(p,1);
	return 0;
}
