#include "plateau.h"

Plateau::Plateau(){
    p = new Piece*[8*8];
}

Plateau::~Plateau(){
    for(int i=0;i<8*8;i++){
        delete p[i];
    }
    delete [] p;
}
