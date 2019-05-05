#include "plateau.h"
#include "piece.h"
#include <iostream>

Plateau::Plateau(){
    peut_etre_pris_en_passant = nullptr;
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
        set(new Pion(Case(j,1),1),Case(j,1));// on créé les pions blanc
    }
    for (int j=0;j<8;j++){
        set(new Pion(Case(j,6),0),Case(j,6));// on créé les pions noirs
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
    int i = permission_bouge(p,c);
    if (i==0){
        return;
    }
    else if (i==2 || i==5){ // prise "normale"
        delete get(c);
        clr_case(c);
    }
    else if (i==3){ // prise "en passant"
        std::cout << "yolo" << std::endl;
        delete peut_etre_pris_en_passant;
        Case est_pris_en_passant(c.get(0), p->get().get(1));
        clr_case(est_pris_en_passant);
        std::cout << "yolo" << std::endl;

    }
    if (i==6){
        peut_etre_pris_en_passant = p;
    }
    else{
        peut_etre_pris_en_passant = nullptr;
    }
    go_to(p->get(),c,p);
    set(p,c);
    set(nullptr,p->get());
    p->bouge(c);

}

void Plateau::mange_vieux(Piece *p, Case c){
    if (permission_mange(p,c)){
        clr_case(c);
        go_to(p->get(),c,p);
        delete get(c); // on supprime la pièce
        set(p,c);
        set(nullptr,p->get());
        p->bouge(c);
    }
}

/* Permissions bouge :
 *  - 0 = Non
 *  - 1 = Oui, case Libre, coup classique
 *  - 2 = Oui, prise de piece
 *  - 3 = Oui, fait une prise en passant
 *  - 4 = Oui, promotion d'un pion.
 *  - 5 = Oui, promotion en prenant d'un pion
 *  - 6 = Oui, pourra être pris en passant */

int Plateau::permission_bouge(Piece* p, Case c){ // on teste les permissions de bouger en connaissant le plateau, string pour indiquer quel piece bouge
    if (p == nullptr) return 0; //on ne peut pas bouger du vide
    if (c == p->get()) return 0; // on ne peut pas bouger sur la même case
    int must_take_or_not = 1;
    if (get(c) != nullptr){
        if (get(c)->get_color() == p->get_color()) return 0; // On en peut pas prendre une pièce de sa couleur
        must_take_or_not = 2;
    }
    if (!p->permission_bouge(c)) return 0;

    if (p->get_name() == "roi"){
        // TODO : à compléter (echec, roque)
        return must_take_or_not;
    }
    else if (p->get_name()=="cavalier") {
        return must_take_or_not;
    }

    // on teste si il y a des pièces sur le trajet
    Deplacement dc = d_deplacement(p->get(), c);
    Case c_test = p->get();
    int dx = c.get(0) - c_test.get(0);
    int dy = c.get(1) - c_test.get(1);
    int dl = std::max(std::abs(dx), std::abs(dy));
    for (int i=1;i < dl;i++){
        c_test = c_test+dc;
        if (get(c_test) != nullptr) return 0; // Case occupée sur le déplacement
    }
    /* à ce moment, si la case d'arrivée est occupée, c'est par une pièce de la couleur opposée
     * la pièce a le droit de faire ce déplacement
     * il n'y a pas de case occupée sur le trajet
     * Il ne reste plus rien à vérifier. (à part les pions qui sont source de problèmes
     * notamment pour la prise en passant ou la prise tout court.) */

    if (p->get_name() == "pion"){
        // TODO : à compléter
        if (std::abs(dy) == 2) return 6; // pourra être pris en passant
        if (dx==0 && must_take_or_not == 2) return 0; // pion ne peut pas prendre tout droit
        if (std::abs(dx)==1 && must_take_or_not == 1){ // y a-t-il un pion qu'on peut prendre en passant ?
            if (peut_etre_pris_en_passant != nullptr){
                if (peut_etre_pris_en_passant->get_color() == p->get_color()) return 0;
                Case sera_pris = peut_etre_pris_en_passant->get();
                if (sera_pris.get(1) == p->get().get(1) && sera_pris.get(0) == c.get(0)) return 3;
                else return 0;
            }
            else return 0;
        }

        if (c.get(1) == 7 or c.get(1) == 0){
            return must_take_or_not+3;  // 4 ou 5
        }
        return must_take_or_not;
    }
    return must_take_or_not;
}


// inutile ? ?
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
