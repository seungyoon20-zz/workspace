#include "Organism.h"
#include "Ant.h"
//#include "Doodle.h"
#include <iostream>
#include <cstdlib>

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
	int nowStep = a->getStep()+1;
//    //a->setX(nowX-1);
//    B[nowX-1][nowY] = new Ant(nowX-1, nowY);
//    delete a;
//    B[nowX][nowY] = 0;
//    return B;
	int count = 0;
	if(nowX > 0 && !B[nowX-1][nowY]){
		count += 1;
	}
	if(nowX < (g-1) && !B[nowX+1][nowY]){
		count += 1;
	}
	if(nowY >0 && !B[nowX][nowY-1]){
		count += 1;
	}
	if(nowY < g-1 && !B[nowX][nowY+1]){
		count += 1;
	}

	if(count != 0){
		int *s = new int[count];
		int i = 0;
		if(nowX > 0 && !B[nowX-1][nowY]){
			s[i] = 0;
	        i++;
		}
		if(nowX < g-1 && !B[nowX+1][nowY]){
			s[i] = 1;
			i++;
		}
		if(nowY > 0 && !B[nowX][nowY-1]){
	        s[i] = 2;
	        i++;
	    }
		if(nowY < g-1 && !B[nowX][nowY+1]){
	        s[i] = 3;
	        //std::cout << s[i];
	        i++;
	    }

	    int c = int(rand()%count);
	    if(s[c] == 0){
	    	B[nowX-1][nowY] = new Ant(nowX-1, nowY, nowStep);
	    	delete a;
	    	B[nowX][nowY] = 0;
	    	return B;
	    }
	    else if(s[c] == 1){
	    	B[nowX+1][nowY] = new Ant(nowX+1, nowY, nowStep);
	    	delete a;
	    	B[nowX][nowY] = 0;
	    	return B;
	    }
	    else if(s[c] == 2){
	        B[nowX][nowY-1] = new Ant(nowX, nowY-1, nowStep);
	        delete a;
	        B[nowX][nowY] = 0;
	        return B;
	    }
	    else if(s[c] == 3){
	        B[nowX][nowY+1] = new Ant(nowX, nowY+1, nowStep);
	        delete a;
	        B[nowX][nowY] = 0;
	        return B;
	    }
	}

	return B;
}

int main(int argc, char* argv[]){
    Organism*** Board;
    int seed;
    

    seed = time(0);
    srand(seed);
    Board = new Organism**[3];
    Board[0] = new Organism*[3];
    Board[1] = new Organism*[3];
    Board[2] = new Organism*[3];
    
    Board[2][0] = new Ant(2, 0);
    printBoard(3, 3, Board);
    cout << "\n";
    Board = AntMove(Board[2][0], Board, 3);
    printBoard(3, 3, Board);


    delete[] Board[0];
    delete[] Board[1];
    delete[] Board[2];
    
    delete[] Board;
    Board = 0;
    return 0;
}

