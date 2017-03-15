#include "Organism.h"
#include "Ant.h"
#include "Doodle.h"
#include <iostream>
#include <cstdlib>
#include <queue>

using std::cout;
using std::queue;

struct position{				//this structure position is to store the position of alive organisms on the board
	int x;
	int y;
};//position

Organism*** update(queue <position> a, Organism*** B){	//set ifNeedBehave to true for every Organism in the queue
	while(!a.empty()){
		B[a.front().x][a.front().y]->resetStatus();
		a.pop();
	}
	return B;
}//update(queue <position> a, Organism*** B)

queue <position> cleanUpAnts(int x, int y, queue <position> a){
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
}//cleanUpAnts(int x, int y, queue <position> a)

int countQueue(queue <position> a){
	int result = 0;
	while(!a.empty()){
		result ++;
		a.pop();
	}
	return result;
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
}//printBoard(int row, int col, Organism** B[])


int main(int argc, char* argv[]){
	//The board for simulation
	Organism*** Board;

	//read all the arguments(might be defaut)
    int grid = (argc>=2)? atoi(argv[1]): 20;
    int numOfDoodles = (argc>=3)? atoi(argv[2]): 5;
    int numOfAnts = (argc>=4)? atoi(argv[3]): 100;
    int timeStep = (argc >= 5 )? atoi(argv[4]): 1000;
    int seed = (argc >= 6)? atoi(argv[5]): 1;
    int ifPause = (argc >= 7)? atoi(argv[6]): 0;
    
    //double check the seed
    if(seed == 0){
    	seed = time(0);
    }

    //check if the board can hold all the organisms
    if(numOfDoodles + numOfAnts > grid*grid){
    	cout << "Too many organisms!";
    	exit(-1);
    }
    
    //start the random number generator
    srand(seed);

    //initialize the rows
    Board = new Organism** [grid];
    //initialize the colunms
    for(int i = 0; i < grid; i++){
    	Board[i] = new Organism* [grid];
    }
    
    //clean the board to make sure no garbage on the board
    for(int j = 0; j < grid; j++){
    	for(int k = 0; k < grid; k++){
    		Board[j][k] = 0;
    	}
    }

    //start queues to remember the position of Organisms
    queue <position> ants;
    queue <position> doodles;
    int totalAnts = numOfAnts;
    int totalDoodles = numOfDoodles;

    //randomly generate row and colunm values
    int r = int(rand()%grid);
    int c = int(rand()%grid);

    //make a iterator of position
    position iterator;

    //put ants in the board
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

    cout << "Initial Stage" << std::endl;
    printBoard(grid, grid, Board);

    Organism* helper;

    int i = 0;
    while(i < timeStep){
    	while(!doodles.empty()&& Board[doodles.front().x][doodles.front().y]->getStatus()){
    		iterator = doodles.front();
    		doodles.pop();
    		helper = Board[iterator.x][iterator.y];
    		Board = Board[iterator.x][iterator.y]->move(grid, Board);
    		ants = cleanUpAnts(helper->getX(), helper->getY(), ants);
    		numOfAnts = countQueue(ants);
    		if(helper->getStepAfterLastEating() >= 3){
    			Board = helper->starvation(grid, Board);
    			numOfDoodles --;
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
    					numOfDoodles++;
    					totalDoodles ++;
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
                	numOfAnts++;
                	totalAnts++;
                }
            }
        }

        if(ifPause == 0|| ifPause ==1 || i%ifPause == ifPause-1){
        	cout << "After " << i+1 <<" step(s)" <<std::endl;
            printBoard(grid, grid, Board);
        }

        if(numOfDoodles ==0 || numOfAnts ==0){
        	break;
        }
        Board = update(doodles, Board);
        Board = update(ants, Board);
        i++;
    }

    cout << "Arguments: \n";
    cout << "Grid: ";
    if(argc>=2){
    	cout <<argv[1] << std::endl;
    }
    else{
    	cout <<  "(default) 20" << std::endl;
    }

    cout << "Number of doodleBugs: ";
    if(argc>=3){
        cout <<argv[2] << std::endl;
    }
    else{
    	cout <<  "(default) 5" << std::endl;
    }

    cout << "Number of ants: ";
    if(argc>=4){
        cout <<argv[3] << std::endl;
    }
    else{
    	cout <<  "(default) 100" << std::endl;
    }

    cout << "Time_steps: ";
    if(argc>=5){
        cout <<argv[4] << std::endl;
    }
    else{
    	cout <<  "(default) 1000" << std::endl;
    }

    cout << "Seed: ";
    if(argc>=6){
    	if(atoi(argv[5]) == 0){
            cout <<"time(0)" << std::endl;
    	}
    	else{
            cout <<argv[5] << std::endl;
    	}

    }
    else{
    	cout <<  "(default) 1" << std::endl;
    }

    cout << "\n\n";
    cout << "Total ants during simulation: "<< totalAnts<< std::endl;
    cout << "Ants remaining: " << numOfAnts<< std::endl;
    cout << "Total doodlebugs during simulation: " << totalDoodles << std::endl;
    cout << "Doodlebugs remaining: " << numOfDoodles << "\n"<< std::endl;

    cout << "Number of steps played: " << i <<std::endl;
    cout << "End Stage" << std::endl;
    printBoard(grid, grid, Board);

    for(int i = 0; i < grid; i++){
    	delete[] Board[i];
    }
    delete[] Board;
    Board = 0;

    return 0;
}

