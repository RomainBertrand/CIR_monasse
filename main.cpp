#include <iostream>
#include <vector>

void init_terrain(bool terrain[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            terrain[i][j]=true;
        }
    }
}

class Case{
private:
    int i,j;
public:
    Case(int i,int j);
    Case();
};

Case::Case(){};

Case::Case(int a,int b){
    i = a;
    j = b;
}

void deplacement_possible(Case pos, Case depl[4]){
     Case dd[4] = {Case(0,1),Case(0,-1),Case(1,0),Case(-1,0)};
}

int main()
{

    bool terrain[8][8];



    return 0;
}
