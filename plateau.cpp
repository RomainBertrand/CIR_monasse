#include "plateau.h"
#include "piece.h"
#include <iostream>

Plateau::Plateau(){
    plateau = new Piece*[8*8];
    // On place les blancs
    set(new Tour(Case('A',1),1),Case('A',1));
    set(new Cavalier(Case('B',1),1),Case('B',1));
    set(new Fou(Case('C',1),1),Case('C',1));
    set(new Dame(Case('D',1),1),Case('D',1));
    set(new Roi(Case('E',1),1),Case('E',1));
    set(new Fou(Case('F',1),1),Case('F',1));
    set(new Cavalier(Case('G',1),1),Case('G',1));
    set(new Tour(Case('H',1),1),Case('H',1));

    // On place les noirs
    set(new Tour(Case('A',8),0),Case('A',8));
    set(new Cavalier(Case('B',8),0),Case('B',8));
    set(new Fou(Case('C',8),0),Case('C',8));
    set(new Dame(Case('D',8),0),Case('D',8));
    set(new Roi(Case('E',8),0),Case('E',8));
    set(new Fou(Case('F',8),0),Case('F',8));
    set(new Cavalier(Case('G',8),0),Case('G',8));
    set(new Tour(Case('H',8),0),Case('H',8));

    for(int j=2;j<6;j++){
        for (int i=0;i<8;i++) {
            set(nullptr,Case(i,j));
        }
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,1),1),Case(j,1)); // on crée les pions blancs
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,6),0),Case(j,6)); // on crée les pions noirs
    }
}

Plateau::~Plateau(){
    for(int i=0;i<8*8;i++){
        delete plateau[i];
    }
    delete [] plateau;
}

Piece* Plateau::operator[](Case c) const{
    return plateau[c.get(0)*8+c.get(1)];
}

Piece* Plateau::get(Case c) const{
    return plateau[c.get(0)*8+c.get(1)];
}
Piece* Plateau::get(int i, int j) const{
    return plateau[i*8+j];
}

void Plateau::set(Piece* p, Case c){
    plateau[c.get(0)*8+c.get(1)]=p;
}

void Plateau::bouge(Piece* p, Case c){
    if (permission_bouge(p,c)){
        go_to(p->get(),c,p);
        set(p,c);
        set(nullptr,p->get());
        p->bouge(c);
    }
}

void Plateau::mange(Piece *p, Case c){
    if (permission_mange(p,c)){
        clr_case(c);
        go_to(p->get(),c,p);
        delete get(c); // on supprime la pièce
        set(p,c);
        set(nullptr,p->get());
        p->bouge(c);
    }
}

int Plateau::permission_bouge(Piece* p, Case c){ // on teste les permissions de bouger en connaissant le plateau, string pour indiquer quel piece bouge
    if (p == nullptr) return 0; // on ne peut pas bouger du vide
    if (c == p->get()) return 0; // on ne peut pas bouger sur la même case
    if (p->get_name().compare(std::string("roi"))==0){
        if (p->permission_bouge(c)){
            if (get(c)!=nullptr) return 2;
            return 1;
        }
        else return 0;
    }
    else if (p->get_name().compare(std::string("dame"))==0){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy>0){
                for(int i=1;i<dx;i++){
                    if (get(p->get() + Case(i,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,dx))!=nullptr) return 2; // si la case cible est non occupée on doit manger
                return 1; // sinon on prend
            }
            if (dx>0 && dy<0){
                for(int i=1;i<dx;i++){
                    if (get(p->get() + Case(i,-i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,-dx))!=nullptr) return 2;
                return 1;
            }
            if (dx<0 && dy>0){
                for(int i=-1;i>dx;i--){
                    if (get(p->get() + Case(i,-i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,-dx))!=nullptr) return 2;
                return 1;
            }
            if (dx<0 && dy<0){
                for(int i=-1;i<dx;i--){
                    if (get(p->get() + Case(i,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,dx))!=nullptr) return 2;
                return 1;
            }
            if (dx>0 && dy==0){
                for(int i=1;i<dx;i++){
                    if (get(p->get() + Case(i,0))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,0))!=nullptr) return 2;
                return 1;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>dx;i--){
                    if (get(p->get() + Case(i,0))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,0))!=nullptr) return 2;
                return 1;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<dy;i++){
                    if (get(p->get() + Case(0,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(0,dy))!=nullptr) return 2;
                return 1;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<dy;i--){
                    if (get(p->get() + Case(0,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(0,dy))!=nullptr) return 2;
                return 1;
            }
        }
        else return 0;

    }
    else if (p->get_name().compare(std::string("fou"))==0){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy>0){
                for(int i=1;i<dx;i++){
                    if (get(p->get() + Case(i,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,dx))!=nullptr) return 2; // si la case cible est non occupée on doit manger
                return 1; // sinon on prend
            }
            if (dx>0 && dy<0){
                for(int i=1;i<dx;i++){
                    if (get(p->get() + Case(i,-i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,-dx))!=nullptr) return 2;
                return 1;
            }
            if (dx<0 && dy>0){
                for(int i=-1;i>dx;i--){
                    if (get(p->get() + Case(i,-i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,-dx))!=nullptr) return 2;
                return 1;
            }
            if (dx<0 && dy<0){
                for(int i=-1;i<dx;i--){
                    if (get(p->get() + Case(i,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,dx))!=nullptr) return 2;
                return 1;
            }
        }
        else return 0;
    }
    else if (p->get_name().compare(std::string("cavalier"))==0){
        if (p->permission_bouge(c)){
            if (get(c)!=nullptr) return 2;
            return 1;
        }
        else return 0;
    }
    else if (p->get_name().compare(std::string("tour"))==0){
        if (p->permission_bouge(c)){ // on check le board
            int dx = c.get(0) - p->get().get(0);
            int dy = c.get(1) - p->get().get(1); // on calcule la différence des cases et on fait tous les cas possibles
            if (dx>0 && dy==0){
                for(int i=1;i<dx;i++){
                    if (get(p->get() + Case(i,0))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,0))!=nullptr) return 2;
                return 1;
            }
            if (dx<0 && dy==0){
                for(int i=-1;i>dx;i--){
                    if (get(p->get() + Case(i,0))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(dx,0))!=nullptr) return 2;
                return 1;
            }
            if (dx==0 && dy>0){
                for(int i=1;i<dy;i++){
                    if (get(p->get() + Case(0,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(0,dy))!=nullptr) return 2;
                return 1;
            }
            if (dx==0 && dy<0){
                for(int i=-1;i<dy;i--){
                    if (get(p->get() + Case(0,i))!=nullptr) return 0;
                }
                if (get(p->get()+ Case(0,dy))!=nullptr) return 2;
                return 1;
            }
        }
        else return 0;

    }
    else if (p->get_name().compare(std::string("pion"))==0){
        if (p->permission_bouge(c)){
            if (get(c)!=nullptr) return 2;
            return 1;
            }
        else return 0;
    }
    else return 0;
}

bool Plateau::permission_mange(Piece *p, Case c){
    if (get(c)==nullptr) return false; // on ne peut pas manger du vide
    else if (p->get_color()!=get(c)->get_color()){
        return (permission_bouge(p,c)==2);
    }
    else return false;
}


void Plateau::affiche() const{
    std::cout << "DEBUT AFFICHE PLATEAU" << std::endl;
    for(int j=7;j>=0;j--){
        for(int i=0;i<8;i++){
            if(get(Case(i,j))!=nullptr)
                std::cout << get(Case(i,j))->get_name() << " ";
            else
                std::cout << "vide ";
        }
        std::cout<<std::endl;
    }
    std::cout <<"FIN AFFICHE PLATEAU" << std::endl;
}
