#include "plateau.h"
#include "piece.h"

Plateau::Plateau(){
    plateau = new Piece*[8*8];
    // On place les blancs
    set(new Tour(Case(0,0),1),Case(0,0));
    set(new Cavalier(Case(1,0),1),Case(1,0));
    set(new Fou(Case(2,0),1),Case(2,0));
    set(new Dame(Case(3,0),1),Case(3,0));
    set(new Roi(Case(4,0),1),Case(4,0));
    set(new Fou(Case(5,0),1),Case(5,0));
    set(new Cavalier(Case(6,0),1),Case(6,0));
    set(new Tour(Case(7,0),1),Case(7,0));

    // On place les noirs
    set(new Tour(Case(0,7),0),Case(0,7));
    set(new Cavalier(Case(1,7),0),Case(1,7));
    set(new Fou(Case(2,7),0),Case(2,7));
    set(new Dame(Case(3,7),0),Case(3,7));
    set(new Roi(Case(4,7),0),Case(4,7));
    set(new Fou(Case(5,7),0),Case(5,7));
    set(new Cavalier(Case(6,7),0),Case(6,7));
    set(new Tour(Case(7,7),0),Case(7,7));

    for(int i=2;i<6;i++){
        for (int j=0;j<8;j++) {
            set(nullptr,Case(j,i));
        }
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,1),1),Case(j,1));// on créé les pions blanc
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,7),0),Case(j,6));// on créé les pions noirs
    }
}

Plateau::~Plateau(){
    for(int i=0;i<8*8;i++){
        delete plateau[i];
    }
    delete [] plateau;
}

Piece* Plateau::get(Case c){
    return plateau[c.get(0)*8+c.get(1)];
}

void Plateau::set(Piece* p, Case c){
    plateau[c.get(0)*8+c.get(1)]=p;
}

bool Plateau::bouge(Piece* p, Case c){ // on teste les permissions de bouger en connaissant le plateau, string pour indiquer quel piece bouge
    if (c == p->get()) return false; // on ne peut pas bouger sur la même case
    if (p->get_name().compare(std::string("roi"))){
        if (p->permission_bouge(c) && get(c)==nullptr){
            p->bouge(c);
            set(p,c);
            set(nullptr,p->get());
            return true;
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("dame"))){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy>0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx>0 && dy<0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx<0 && dy>0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx<0 && dy<0){
                for(int i=-1;i<=dx;i--){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx>0 && dy==0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<=dy;i++){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<=dy;i--){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
        }
        else return false;

    }
    else if (p->get_name().compare(std::string("fou"))){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy>0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx>0 && dy<0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx<0 && dy>0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx<0 && dy<0){
                for(int i=-1;i<=dx;i--){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("cavalier"))){
        if (p->permission_bouge(c) && get(c)==nullptr){
            p->bouge(c);
            set(p,c);
            set(nullptr,p->get());
            return true;
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("tour"))){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy==0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<=dy;i++){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<=dy;i--){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                p->bouge(c);
                set(p,c);
                set(nullptr,p->get());
                return true;
            }
        }
        else return false;

    }
    else if (p->get_name().compare(std::string("pion"))){
        if (p->permission_bouge(c) && get(c)==nullptr){
            p->bouge(c);
            set(p,c);
            set(nullptr,p->get());
            return true;
        }
        else return false;
    }
    else return false;
    return false;
}
