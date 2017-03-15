#include "Organism.h"
#include "Ant.h"
#include "Doodle.h"
#include <iostream>
#include <cstdlib>
#include <queue>

using std::cout;
using std::queue;


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
    cout << "\n\n";
}


int main(int argc, char* argv[]){
	Organism*** Board;

    int grid = (argc>=2)? atoi(argv[1]): 5;
    int numOfDoodles = (argc>=3)? atoi(argv[2]): 1;
    int numOfAnts = (argc>=4)? atoi(argv[3]): 0;
    int timeStep = (argc >= 5 )? atoi(argv[4]): 10;
    int seed = (argc >= 6)? atoi(argv[5]): 2;
    int ifPause = (argc >= 7)? atoi(argv[6]): 0;
    
    
    Organism* iterator;
    
    if(numOfDoodles + numOfAnts > grid*grid){
    	cout << "Too many organisms!";
    	exit(-1);
    }
    
    srand(seed);
    
    Board = new Organism**[grid];
    for(int i = 0; i < grid; i++){
    	Board[i] = new Organism*[grid];
    }
    


    queue <Organism*> ants;
    queue <Organism*> doodles;
    int r = int(rand()%grid);
    int c = int(rand()%grid);

    for(int i = 0; i < numOfAnts; i++){
    	while(Board[r][c]){
    		r = int(rand()%grid);
    		c = int(rand()%grid);
    	}
    	Board[r][c] = new Ant(r, c, true);
    	ants.push(Board[r][c]);
    }

    for(int i = 0; i < numOfDoodles; i++){
        while(Board[r][c]){
        	r = int(rand()%grid);
       		c = int(rand()%grid);
       	}
       	Board[r][c] = new Doodle(r, c, true);
       	doodles.push(Board[r][c]);
    }

    printBoard(grid, grid, Board);

//     cout << "\n\n";
//     Organism* iterator = doodles.front();
//    //printBoard(grid, grid, Board);
//    //cout << iterator->getX();
//    //cout << iterator->getY();
//    Board = iterator->move(grid,Board);
//
//    printBoard(grid, grid, Board);
//    cout << iterator->getX();
//    cout << iterator->getY();
//    cout << iterator->getStep();
//    cout << iterator->getStepAfterLastEating();
//
//    cout << "\n\n";
//    Board = iterator->move(grid,Board);
//
//        printBoard(grid, grid, Board);
//        cout << iterator->getX();
//        cout << iterator->getY();
//        cout << iterator->getStep();
//        cout << iterator->getStepAfterLastEating();
//
//        cout << "\n\n";
//        Board = iterator->breed(grid,Board);
//
//            printBoard(grid, grid, Board);
//            cout << iterator->getX();
//            cout << iterator->getY();
//            cout << iterator->getStep();
//            cout << iterator->getStepAfterLastEating();
//
//
//
//            cout << "\n\n";
//            Board = iterator->move(grid,Board);
//
//                printBoard(grid, grid, Board);
//                cout << iterator->getX();
//                cout << iterator->getY();
//                cout << iterator->getStep();
//                cout << iterator->getStepAfterLastEating();
//
//                Board = iterator->move(grid,Board);



    for(int i = 0; i < timeStep; i++){
    	while(doodles.front() && doodles.front()->getStatus()){
    		iterator = doodles.front();
    		Board = iterator->move(grid, Board);
    		if(iterator->getStepAfterLastEating() >= 3){
    			Board = iterator->starvation(grid, Board);
                continue;
    		}
            doodles.push(iterator);
    		if(iterator->getStep() >= 8){
                Board = iterator->breed(grid, Board);
                doodles.push(iterator);
    		}
            doodles.pop();
    	}
        while(ants.front() && ants.front()->getStatus()){
            iterator = ants.front();
            Board = iterator->move(grid, Board);
            doodles.push(iterator);
            if(iterator->getStep() >= 8){
                Board = iterator->breed(grid, Board);
                ants.push(iterator);
            }
            ants.pop();
        }
        if(ifPause == 0|| ifPause ==1 || i%ifPause == ifPause-1){
            printBoard(grid, grid, Board);
        }
    }
    
    for(int i = 0; i < grid; i++){
    	delete[] Board[i];
    }
    delete[] Board;
    Board = 0;

    return 0;
}

