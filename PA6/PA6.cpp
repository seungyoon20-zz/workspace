#include "Organism.h"
#include "Ant.h"
//#include "Doodle.h"
#include <iostream>



using std::cout;

void printBoard(int row, int col, Organism** B[]){
    
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(B[r][c]){
                B[r][c]->print();
            }
            else{
                cout << "-";
            }
        }
        cout << "\n";
    }
}

Organism*** AntMove(Organism* a, Organism** B[], int g){
    int nowX = a->getX();
    int nowY = a->getY();
    a->setX(nowX-1);
    B[nowX-1][nowY] = new Ant(nowX-1, nowY);
    //delete[] B[nowX][nowY];
    B[nowX][nowY] = nullptr;
    return B;
}

int main(int argc, char* argv[]){
    Organism*** Board;
    
    Board = new Organism**[3];
    Board[0] = new Organism*[3];
    Board[1] = new Organism*[3];
    Board[2] = new Organism*[3];
    
    Board[1][0] = new Ant(1, 0);
    printBoard(3, 3, Board);
    cout << "\n";
    Board = AntMove(Board[1][0], Board, 3);
    printBoard(3, 3, Board);
    
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3;  j++){
//            if(Board[i][j]){
//                delete[] Board[i][j];
//            }
//        }
//    }
    //delete[] Board[2][0];
    delete[] Board[0];
    delete[] Board[1];
    delete[] Board[2];
    
    delete[] Board;
    Board = 0;
    return 0;
}

