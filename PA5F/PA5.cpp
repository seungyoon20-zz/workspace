#include <iostream>
#include <fstream>
#include <cstring>
#include "Rational.h"
#include <cstdlib>
#include <stack>
#include <ctype.h>
using std::ifstream;
using std::cout;
using std::endl;
using std::stack;


//HELPER FUNCTION, RETURN A RATIONAL
Rational calculate(char f,Rational& l,Rational& r){
    Rational  re;
    cout<<f<<' ';


    if(f=='+') re = l+r;
    if(f=='-') re = l-r;
    if(f=='*') re = l*r;
    if(f=='/') re = l/r;
    return re;
    
}//calculate(char f,Rational& l,Rational& r)

//HELPER FUNCTION, VOID
void calculateSelf(char f,Rational& l,Rational& r){
	 cout<<f;
	 if(f=='=') cout<<' ';
	 else
		 cout<<'=' << " ";


    if(f=='+') l+= r;
    if(f=='-') l-= r;
    if(f=='*') l*= r;
    if(f=='/') l/= r;
    if(f=='=') l= r;
}//calculateSelf(char f,Rational& l,Rational& r)

//HELPER FUNCTION, RETURN VOID BUT PRINT RESULT IN THE CMD LINE
void compareTo(char f, char n,Rational& l,Rational& r){
	bool a =false;
	 cout<<f;
	    if(n=='\n'){
	    	n=' ';
	    	cout<<' ';}
	    else
	    	cout<<n;

    if(f=='>'&&n=='=') a=(l>=r);
    if(f=='<'&&n=='=') a=(l<=r);
    if(f=='>'&&n==' ') a=(l>r);
    if(f=='<'&&n==' ') a=(l<r);
    if(f=='!'&&n=='=') a=(l!=r);
    if(f=='='&&n=='=') a=(l==r);
    if(a)
    	cout<<"\t:True"<<endl;
    else
    	cout<<"\t:False"<<endl;
}//compareTo(char f, char n,Rational& l,Rational& r)

//HELPER FUNCTION, GET THE INDEX OF VARIABLE WANTED
int findExp(Rational exps[50], char name){
    for(int i = 0; i < 50; i++){
        if(exps[i].getName() == name){
            return i;
        }
    }
    return -1;
}//findExp(Rational exps[50], char name)


//MAIN FUNCTION, RETURN 0 IF SUCCEED.
int main(int argc, char* argv[]){
    //Check if there is at least 1 inputfile.
    if(argc < 2 ){
        cout << "Need at least one input file!"<< endl;
        exit(-1);
    }
    
    int numOfVar;
    
    for(int i = 0; i < argc-1; i++){ //loop through each file
        ifstream f;
           f.open(argv[i+1]);
           cout<<endl<<"File name: "<<argv[i+1]<<endl;
           if(f.fail()){            //check whether the file has been opened
               cout<< "Problem reading input file!!" << endl;
               exit(-1);
           }
        numOfVar = 0; //initiate the variableArray
        Rational* exps = new Rational[50];
        
           istream& s = f;
           stack<Rational> table;
           Rational a;
           char c,nextC;
        
           while(!s.eof()){    //loop until touch the end of the file
        	   c=s.peek();
        	   while(c!='\n'&&!s.eof()){
        		   	   if(c==' ') //if it detect a whitespace it will skip this space and keep looking for others
        		   	   {
        		   		   s.get(c);
        		   	   }
        		   	   else
        		   	   {
        		   	   	  if(isdigit(c)){
        		   	   		   s>>a;
        		   	   		   cout<<a<<" ";
        		   	   		   table.push(a);

        		   	   	  }
                           
        				  else
        				  if(isalpha(c)){
                              s.get(c);
                              int index = findExp(exps, c);
                              //if the variable is already stored in the array
                              if(index != -1){
                                  table.push(exps[index]);
                                  cout << c << " ";
                              }
                              //if not found
                              else{
                                  s >> a;    //get the rational after the variable name
                                  Rational e(c, a);
                                  s >> nextC;   //get the operator after the rational

                                  if(nextC == '='){     //if the symbol is a assignment operator
                                      exps[numOfVar] = e;
                                      numOfVar += 1;
                                      table.push(e);
                                      cout <<c << " "<<a<<" "<<"= ";
                                  }
                                  else{             //if use the variable before define it, exit
                                      cout << "Unitialized expression!!" << endl;
                                      exit(-1);
                                  }
                              }
        				  }
        				  else{
        					s.get(c);
        					nextC=s.peek();
        					if(c=='-'&&isdigit(nextC)){ //if is negative symbol
        					 s.putback(c);
        					 s>>a;
        					 cout<< a<<" ";
        					 table.push(a);

        					}
        					else{   //c is a is operator, start operating
            					Rational r = table.top();
            					table.pop();
            					Rational l = table.top();
                                
            					table.pop();

            					if(nextC=='='){
            						if(c=='<'||c=='>'||c=='!'||c=='=')
            						compareTo(c,nextC,l,r);
            						else{
                                            if(l.getName() != 0){
                                                int index = findExp(exps, l.getName());
                                                calculateSelf(c,l,r);
                                                table.push(l);
                                                exps[index] = l;
                                            }
                                            else{
                                                calculateSelf(c,l,r);
                                                table.push(l);
                                            }
            							}
            						s.get(c);
            					  }
            					else if(c=='<'||c=='>'||c=='!'){
            						compareTo(c,nextC,l,r);
            					}
            					else if(c=='='){
                                    if(l.getName() != 0){
                                        int index = findExp(exps, l.getName());
                                        calculateSelf(c,l,r);
                                        table.push(l);
                                        exps[index] = l;
                                    }
                                    else{
                                        calculateSelf(c,l,r);
                                        table.push(l);
                                    }
                                    
            					}
            					else{
                					a=calculate(c,l,r);
                					table.push(a);
            					}
        					}

        				  }
        		   	   }

        		   	   c=s.peek();
        		   }
        	   while(!table.empty()){
        	           	   cout<<"\t:"<<table.top()<<" (double "<<table.top().getDouble()<<")"<<endl;
        	           	   table.pop();
        	              }
        	   s.get(c);
           }
        
        delete[] exps; ////delete the pointer to exps
        f.close(); //close file
    }
    return 0;
}//end of main function



