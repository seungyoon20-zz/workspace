#include "Ant.h"
#include <iostream>

Ant::Ant(): Organism(){
    
}
Ant::Ant(int _x, int _y): Organism(_x, _y){
    
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
void Ant::breed(int row, int col, Organism** B[]){
    
}

//Organism*** move(Organism* a, int row, int col, Organism** B[]){
//    step++;
//    
//    a->x = a->x-1;
//    B[a->x][a->y] = a;
//    delete B[a->x+1][a->y];
//    return B;
//
////    int count = 0;
////    if(x > 0 && !B[x-1][y]){
////        count +=1;
////    }
////    if(x < row-1 && !B[x+1][y]){
////        count +=1;
////    }
////    if(y > 0 && !B[x][y-1]){
////        count +=1;
////    }
////    if(y < col-1 && !B[x][y+1]){
////        count +=1;
////    }
////
////    if(count != 0){
////        int a[count];
////        for(int i = 0; i < count; i++){
////            if(x > 0 && !B[x-1][y]){
////                a[i] = 0;
////            }
////            if(x < row-1 && !B[x+1][y]){
////                a[i] = 1;
////            }
////            if(y > 0 && !B[x][y-1]){
////                a[i] = 2;
////            }
////            if(y < col-1 && !B[x][y+1]){
////                a[i] = 3;
////            }
////        }
////        int c = int(rand()%count);
////        if(a[c] == 0){
////            x -= 1;
////            B[x][y] = this;
////            B[x+1][y] = nullptr;
////        }
////        else if(a[c] == 1){
////            x += 1;
////            B[x][y] = this;
////            B[x-1][y] = nullptr;
////        }
////        else if(a[c] == 2){
////            y -= 1;
////            B[x][y] = this;
////            B[x][y+1] = nullptr;
////        }
////        else if(a[c] == 3){
////            y += 1;
////            B[x][y] = this;
////            B[x][y-1] = nullptr;
////        }
////    }
////    return B;
//}

void Ant::print(){
    std::cout << "O";
}
