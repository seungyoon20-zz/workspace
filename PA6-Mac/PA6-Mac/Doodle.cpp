#include "Doodle.h"
#include <iostream>
#include <cstdlib>

Doodle::Doodle(): Organism(), stepAfterEat(0){
    
}
Doodle::Doodle(int _x, int _y, bool _ifNeedBehave): Organism(_x, _y, _ifNeedBehave), stepAfterEat(0){
    
}
Doodle::Doodle(int _x, int _y, int _step, bool _ifNeedBehave): Organism(_x, _y, _step, _ifNeedBehave), stepAfterEat(0){
    
}
Doodle::Doodle(int _x, int _y, int _step, bool _ifNeedBehave, int _stepAfterEat): Organism(_x, _y, _step, _ifNeedBehave), stepAfterEat(_stepAfterEat){

}
Doodle::~Doodle(){
    step = 0;
    x = 0;
    y = 0;
    stepAfterEat = 0;
}


//overriding
Organism*** Doodle::breed(int g, Organism** B[]){

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
	    	step = 0;
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
	        	x-=1;
	        	B[x][y] = this;
	        	B[x+1][y] = new Doodle(x+1, y, step, false, stepAfterEat);
	        	step = 0;
	        	stepAfterEat = 0;
	            return B;
//	        	x-= 1;
//	        	B[x+1][y] = new Doodle(x+1, y, step, false, stepAfter)
	        }
	        else if(s[c] == 1){
	        	x+=1;
	            B[x][y] = this;
	            B[x-1][y] = new Doodle(x-1, y, step, false, stepAfterEat);
	            step = 0;
	            stepAfterEat = 0;
	            return B;
	        }
	        else if(s[c] == 2){
	        	y-=1;
	        	B[x][y] = this;
	        	B[x][y+1] = new Doodle(x, y+1, step, false, stepAfterEat);
	        	step = 0;
	        	stepAfterEat = 0;
	            return B;
	        }
	        else if(s[c] == 3){
	        	y+=1;
	        	B[x][y] = this;
	        	B[x][y-1] = new Doodle(x, y-1, step, false, stepAfterEat);
	        	step = 0;
	        	stepAfterEat = 0;
	            return B;
	        }
	    }
	    return B;
}

Organism*** Doodle::starvation(int g, Organism** B[]){
	B[x][y] = 0;
	delete this;
	return B;
}

Organism*** Doodle::move(int g, Organism** B[]){
    stepAfterEat +=1;
    step += 1;
    ifNeedBehave = false;
    
    int count = 0;
    if(x > 0 && B[x-1][y] && B[x-1][y]->isAnt()){
        count +=1;
    }
    if(x < g-1 && B[x+1][y] && B[x+1][y]->isAnt()){
        count +=1;
    }
    if(y > 0 && B[x][y-1] && B[x][y-1]->isAnt()){
        count +=1;
    }
    if(y < g-1 && B[x][y+1] && B[x][y+1]->isAnt()){
        count +=1;
    }
    
    if(count != 0){
    	stepAfterEat = 0;

        int *s = new int[count];
        int i = 0;
        if(x > 0 && B[x-1][y] && B[x-1][y]->isAnt()){
            s[i] = 0;
            i++;
        }
        if(x < g-1 && B[x+1][y] && B[x+1][y]->isAnt()){
            s[i] = 1;
            i++;
        }
        if(y > 0 && B[x][y-1] && B[x][y-1]->isAnt()){
            s[i] = 2;
            i++;
        }
        if(y < g-1 && B[x][y+1] && B[x][y+1]->isAnt()){
            s[i] = 3;
            i++;
        }
        
        int c = int(rand()%count);
        
        if(s[c] == 0){
            //delete B[x-1][y];
        	x= x-1;
            B[x][y] = this;
            B[x+1][y] = 0;
            //this = B[x-1][y];
            return B;
        }
        else if(s[c] == 1){
            //delete B[x+1][y];
//            B[x+1][y] = new Doodle(x+1, y, step, false);
//            B[x][y] = 0;
//            delete this;
        	x= x+1;
        	B[x][y] = this;
            B[x-1][y] = 0;
            return B;
        }
        else if(s[c] == 2){
        	y= y-1;
        	B[x][y] = this;
            B[x][y+1] = 0;
            return B;
        }
        else if(s[c] == 3){
        	y= y+1;
        	B[x][y] = this;
            B[x][y-1] = 0;
            return B;
        }
    }
    
    //count = 0;
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
            //delete B[x-1][y];
        	x= x-1;
            B[x][y] = this;
            B[x+1][y] = 0;
            //this = B[x-1][y];
            return B;
        }
        else if(s[c] == 1){
            //delete B[x+1][y];
//            B[x+1][y] = new Doodle(x+1, y, step, false);
//            B[x][y] = 0;
//            delete this;
        	x= x+1;
        	B[x][y] = this;
            B[x-1][y] = 0;
            return B;
        }
        else if(s[c] == 2){
            //delete B[x][y-1];
//            B[x][y-1] = new Doodle(x, y-1, step, false);
//            B[x][y] = 0;
//            delete this;
        	y= y-1;
        	B[x][y] = this;
            B[x][y+1] = 0;
            return B;
        }
        else if(s[c] == 3){
            //delete B[x][y+1];
//            B[x][y+1] = new Doodle(x, y+1, step, false);
//            B[x][y] = 0;
//            delete this;
        	y= y+1;
        	B[x][y] = this;
            B[x][y-1] = 0;
            return B;
        }
    }
    return B;
}
void Doodle::print(){
    std::cout << "X";
}

int Doodle::getStepAfterLastEating(){
    return stepAfterEat;
}

bool Doodle::isAnt(){
    return false;
}
