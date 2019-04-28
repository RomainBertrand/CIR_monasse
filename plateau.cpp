#include "plateau.h"

Plateau::Plateau(){
    plateau = new Piece*[8*8];
}

Plateau::~Plateau(){
    for(int i=0;i<8*8;i++){
        delete plateau[i];
    }
    delete [] plateau;
}

Piece* Plateau::get(Case c){
    return plateau[c.x*8+c.y];
}

void Plateau::set(Piece* p, Case c){
    plateau[c.x*8+c.y]=p;
}

bool Plateau::bouge(Piece* p, Case c){ // on teste les permissions de bouger en connaissant le plateau, string pour indiquer quel piece bouge
    if (c == p->c) return false; // on ne peut pas bouger sur la même case
    if (p->get_name().compare(std::string("roi"))){
        if (p->permission_bouge(c) && get(c)==0){
            p->bouge(c);
            set(p,c);
            set(0,p->c);
            return true;
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("dame"))){
        return true;
    }
    else if (p->get_name().compare(std::string("fou"))){
        return true;
    }
    else if (p->get_name().compare(std::string("cavalier"))){
        if (p->permission_bouge(c) && get(c)==0){
            p->bouge(c);
            set(p,c);
            set(0,p->c);
            return true;
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("tour"))){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.x - p->c.x;
            int dy = c.y - p->c.y; // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy==0){
                for(int i=1;i<=dx;i++){
                    if (get(p->c + Case(i,0))!=0) return false;
                }
                p->bouge(c);
                set(p,c);
                set(0,p->c);
                return true;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->c + Case(i,0))!=0) return false;
                }
                p->bouge(c);
                set(p,c);
                set(0,p->c);
                return true;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<=dy;i++){
                    if (get(p->c + Case(0,i))!=0) return false;
                }
                p->bouge(c);
                set(p,c);
                set(0,p->c);
                return true;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<=dy;i--){
                    if (get(p->c + Case(0,i))!=0) return false;
                }
                p->bouge(c);
                set(p,c);
                set(0,p->c);
                return true;
            }
        }
        else return false;

    }
    else if (p->get_name().compare(std::string("pion"))){
        if (p->permission_bouge(c) && get(c)==0){
            p->bouge(c);
            set(p,c);
            set(0,p->c);
            return true;
        }
        else return false;
    }
    else return false;
}
