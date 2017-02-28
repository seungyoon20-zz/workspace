#include "Organism.h"
#include "Ant.h"
#include "Doodle.h"
#include <iostream>
#include <cstdlib>
#include <queue>

using std::cout;
using std::queue;

struct position{
	int x;
	int y;
};

Organism*** update(queue <position> a, Organism*** B){
	while(!a.empty()){
		B[a.front().x][a.front().y]->resetStatus();
		a.pop();
	}
	return B;
}

queue <position> cleanUpAnts(int x, int y, queue <position> a){
//	int x = iterator->getX();
//	int y = iterator->getY();
	queue <position> b;
	position cursor;
	while(!a.empty()){
		cursor = a.front();
		if(cursor.x != x || cursor.y != y){
			b.push(cursor);
		}
		a.pop();
	}
	return b;
}

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
    int numOfAnts = (argc>=4)? atoi(argv[3]): 10;
    int timeStep = (argc >= 5 )? atoi(argv[4]): 40;
    int seed = (argc >= 6)? atoi(argv[5]): 2;
    int ifPause = (argc >= 7)? atoi(argv[6]): 0;
    
    
    //Organism* iterator;
    
    if(numOfDoodles + numOfAnts > grid*grid){
    	cout << "Too many organisms!";
    	exit(-1);
    }
    
    srand(seed);
    Board = new Organism** [grid];
    for(int i = 0; i < grid; i++){
    	Board[i] = new Organism* [grid];
    }
    
    for(int j = 0; j < grid; j++){
    	for(int k = 0; k < grid; k++){
    		Board[j][k] = 0;
    	}
    }


    queue <position> ants;
    queue <position> doodles;
    int r = int(rand()%grid);
    int c = int(rand()%grid);

    position iterator;
    for(int i = 0; i < numOfAnts; i++){
    	while(Board[r][c]){
    		r = int(rand()%grid);
    		c = int(rand()%grid);
    	}
    	iterator.x = r;
    	iterator.y = c;
    	Board[r][c] = new Ant(r, c, true);
    	ants.push(iterator);
    }

    for(int i = 0; i < numOfDoodles; i++){
        while(Board[r][c]){
        	r = int(rand()%grid);
       		c = int(rand()%grid);
       	}
        iterator.x = r;
        iterator.y = c;
        Board[r][c] = new Doodle(r, c, true);
        doodles.push(iterator);
    }

    printBoard(grid, grid, Board);

    Organism* helper;

    for(int i = 0; i < timeStep; i++){
    	while(!doodles.empty()&& Board[doodles.front().x][doodles.front().y]->getStatus()){
    		iterator = doodles.front();
    		doodles.pop();
    		helper = Board[iterator.x][iterator.y];
    		Board = Board[iterator.x][iterator.y]->move(grid, Board);
    		ants = cleanUpAnts(helper->getX(), helper->getY(), ants);
    		if(helper->getStepAfterLastEating() >= 3){
    			Board = helper->starvation(grid, Board);
    		}
    		else{
    			iterator.x = helper->getX();
    			iterator.y = helper->getY();
    			doodles.push(iterator);
    			if(Board[iterator.x][iterator.y]->getStep() >= 8){
    				Board = Board[iterator.x][iterator.y]->breed(grid, Board);
    				if(helper->getX() != doodles.back().x || helper->getY() != doodles.back().y){
    					iterator.x = helper->getX();
    					iterator.y = helper->getY();
    					doodles.push(iterator);
    				}
    			}
    		}


    	}

        while(!ants.empty()&& Board[ants.front().x][ants.front().y]->getStatus()){
            iterator = ants.front();
            ants.pop();
            helper = Board[iterator.x][iterator.y];
            Board = Board[iterator.x][iterator.y]->move(grid, Board);

            iterator.x = helper->getX();
            iterator.y = helper->getY();
            ants.push(iterator);

            if(Board[iterator.x][iterator.y]->getStep() >= 3){
                Board = Board[iterator.x][iterator.y]->breed(grid, Board);
                if(helper->getX() != ants.back().x || helper->getY() != ants.back().y){
                	iterator.x = helper->getX();
                	iterator.y = helper->getY();
                	ants.push(iterator);
                }
                //ants.push(iterator);
            }
        }

        if(ifPause == 0|| ifPause ==1 || i%ifPause == ifPause-1){
            printBoard(grid, grid, Board);
        }
        Board = update(doodles, Board);
        Board = update(ants, Board);
    }



    //cout << doodles.front()->getX();
    for(int i = 0; i < grid; i++){
    	delete[] Board[i];
    }
    delete[] Board;
    Board = 0;

    return 0;
}

