#include "plateau.h"
#include "piece.h"
#include <iostream>

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

    for(int j=2;j<6;j++){
        for (int i=0;i<8;i++) {
            set(nullptr,Case(i,j));
        }
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,1),1),Case(j,1));// on créé les pions blanc
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,7),0),Case(j,6));// on créé les pions noirs
    }
    display_grid_empty();
    for (int j=0;j<2;j++){
        for (int i=0;i<8;i++){
            display_piece(Case(i, j), plateau[i*8+j]);
            int j2 = 7-j;
            display_piece(Case(i, j2), plateau[i*8+j2]);
        }
    }
}

Plateau::~Plateau(){
    for(int i=0;i<8*8;i++){
        delete plateau[i];
    }
    delete [] plateau;
}

void Plateau::affiche(){
    std::cout << "DEBUT AFFICHE PLATEAU" << std::endl;
    for(int j=7;j>=0;j--){
        for(int i=0;i<8;i++){
        if(get(Case(i,j))!=nullptr) std::cout << get(Case(i,j))->get_name() << " ";
        else std::cout << "vide ";
        }
        std::cout<<std::endl;
    }
    std::cout <<"FIN AFFICHE PLATEAU" << std::endl;
}

Piece* Plateau::get(Case c) const{
    return plateau[c.get(0)*8+c.get(1)];
}

void Plateau::set(Piece* p, Case c){
    plateau[c.get(0)*8+c.get(1)]=p;
}

bool Plateau::bouge(Piece* p, Case c){ // on teste les permissions de bouger en connaissant le plateau, string pour indiquer quel piece bouge
    if (p == nullptr) return false; //on ne peut pas bouger du vide
    if (c == p->get()) return false; // on ne peut pas bouger sur la même case
    if (p->get_name().compare(std::string("roi"))==0){
        if (p->permission_bouge(c) && get(c)==nullptr){
            set(p,c);
            set(nullptr,p->get());
            p->bouge(c);
            return true;
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("dame"))==0){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy>0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx>0 && dy<0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx<0 && dy>0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx<0 && dy<0){
                for(int i=-1;i<=dx;i--){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx>0 && dy==0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<=dy;i++){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<=dy;i--){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
        }
        else return false;

    }
    else if (p->get_name().compare(std::string("fou"))==0){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy>0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx>0 && dy<0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx<0 && dy>0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,-i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx<0 && dy<0){
                for(int i=-1;i<=dx;i--){
                    if (get(p->get() + Case(i,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("cavalier"))==0){
        if (p->permission_bouge(c) && get(c)==nullptr){
            set(p,c);
            set(nullptr,p->get());
            p->bouge(c);
            return true;
        }
        else return false;
    }
    else if (p->get_name().compare(std::string("tour"))==0){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy==0){
                for(int i=1;i<=dx;i++){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>=dx;i--){
                    if (get(p->get() + Case(i,0))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<=dy;i++){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<=dy;i--){
                    if (get(p->get() + Case(0,i))!=nullptr) return false;
                }
                set(p,c);
                set(nullptr,p->get());
                p->bouge(c);
                return true;
            }
        }
        else return false;

    }
    else if (p->get_name().compare(std::string("pion"))==0){
        if (p->permission_bouge(c) && get(c)==nullptr){
            set(p,c);
            set(nullptr,p->get());
            p->bouge(c);
            return true;
        }
        else return false;
    }
    else return false;
    return false;
}
