#include "Ant.h"
#include <iostream>
#include <cstdlib>



Ant::Ant(): Organism(){
    
}
Ant::Ant(int _x, int _y): Organism(_x, _y){
#include <cstdlib>
}
//Ant::Ant(const Ant& a):Organism(a.x, a.y, a.step){
//    
//}
Ant::Ant(int _x, int _y, int _step):Organism(_x, _y, _step){

}
Ant::~Ant(){
    step = 0;
    x = 0;
    y = 0;
}


//overriding
Organism*** Ant::breed(int g, Organism** B[]){
	step = 0;

    int count = 0;
    if(x > 0 && !B[x-1][y]){
        count +=1;
    }
    if(x < g-1 && !B[x+1][y]){
        count +=1;
    }
    if(y > 0 && !B[x][y-1]){
        count +=1;
    }
    if(y < g-1 && !B[x][y+1]){
        count +=1;
    }

    if(count != 0){
        int *s = new int[count];
        int i = 0;
        if(x > 0 && !B[x-1][y]){
            s[i] = 0;
            i++;
        }
        if(x < g-1 && !B[x+1][y]){
            s[i] = 1;
            i++;
        }
        if(y > 0 && !B[x][y-1]){
            s[i] = 2;
            i++;
        }
        if(y < g-1 && !B[x][y+1]){
            s[i] = 3;
            i++;
        }

        int c = int(rand()%count);

        if(s[c] == 0){
            B[x-1][y] = new Ant(x-1, y);
            //B[x][y] = 0;
            //delete this;
            return B;
        }
        else if(s[c] == 1){
            B[x+1][y] = new Ant(x+1, y);
            //B[x][y] = 0;
            //delete this;
            return B;
        }
        else if(s[c] == 2){
            B[x][y-1] = new Ant(x, y-1);
            //B[x][y] = 0;
            //delete this;
            return B;
        }
        else if(s[c] == 3){
            B[x][y+1] = new Ant(x, y+1);
            //B[x][y] = 0;
            //delete this;
            return B;
        }
    }
    return B;
}

Organism*** Ant::move(int g, Organism** B[]){
	step +=1;
    int count = 0;
    if(x > 0 && !B[x-1][y]){
        count +=1;
    }
    if(x < g-1 && !B[x+1][y]){
        count +=1;
    }
    if(y > 0 && !B[x][y-1]){
        count +=1;
    }
    if(y < g-1 && !B[x][y+1]){
        count +=1;
    }

    if(count != 0){
        int *s = new int[count];
        int i = 0;
        if(x > 0 && !B[x-1][y]){
            s[i] = 0;
            i++;
        }
        if(x < g-1 && !B[x+1][y]){
            s[i] = 1;
            i++;
        }
        if(y > 0 && !B[x][y-1]){
            s[i] = 2;
            i++;
        }
        if(y < g-1 && !B[x][y+1]){
            s[i] = 3;
            i++;
        }
        
        int c = int(rand()%count);

        if(s[c] == 0){
            B[x-1][y] = new Ant(x-1, y, step);
            B[x][y] = 0;
            delete this;
            return B;
        }
        else if(s[c] == 1){
            B[x+1][y] = new Ant(x+1, y, step);
            B[x][y] = 0;
            delete this;
            return B;
        }
        else if(s[c] == 2){
            B[x][y-1] = new Ant(x, y-1, step);
            B[x][y] = 0;
            delete this;
            return B;
        }
        else if(s[c] == 3){
            B[x][y+1] = new Ant(x, y+1, step);
            B[x][y] = 0;
            delete this;
            return B;
        }
    }
    return B;
}

void Ant::print(){
    std::cout << "O";
}
