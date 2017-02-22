#include <iostream>
#include <fstream>
#include <cstring>
#include "Rational.h"

using std::ifstream;
using std::cout;
using std::endl;

Rational calculate(char f,char n, Rational& l,Rational& r){
    Rational  re;
    if(f=='+'&&n==' ') re = l+r;
    if(f=='-'&&n==' ') re = l-r;
    if(f=='*'&&n==' ') re = l*r;
    if(f=='/'&&n==' ') re = l/r;
    return re;
    
}

void calculateSelf(char f,Rational& l,Rational& r){
    if(f=='+') l+= r;
    if(f=='-') l-= r;
    if(f=='*') l*= r;
    if(f=='/') l/= r;
}

bool compareTo(char f, char n,Rational& l,Rational& r){
    if(f=='>'&&n=='=')return l>=r;
    return true;
}


int main(int argc, char* argv[]){
    if(argc < 2 ){
        cout << "Need at least one input file!"<< endl;
        exit(-1);
    }
    Rational left;
    Rational right;
    Rational result;
    Rational& l = left;
    Rational& r = right;
    Rational& re = result;
    char symbol;
    char next;
    ifstream f;
    bool first =true;
    bool compare =false;
    bool cResult;
    for(int i = 0; i < argc-1; i++){
        f.open(argv[i+1]);
        if(f.fail()){
            cout<< "Problem reading input file!!" << endl;
            exit(-1);
        }
        istream& s = f;                     //check whether the file has been opened
        
        while(!f.eof()){                    // The first reading input file and output
            s >> left;
            cout<<left<<" ";
            first =true;
                while(s>>right){
                    s.get(symbol);
                    while(symbol==' '){
                        s.get(symbol);
                    }
                    s.get(next);
                    
                    if(first){                 //check for the first time doing
                        if(symbol=='<'||symbol=='>'||symbol=='!'||symbol=='='){
                            compare =true;
                            cResult =compareTo(symbol,next,l,r);
                        }
                        else if(next ==' '){
                        re=calculate(symbol,next,l,r);
                        first =false;
                        }
                        else if(next =='='){
                            calculateSelf(symbol,l,r);
                            re =l;
                        }
                    }
                    else if(next ==' ')
                    {
                        l = re;
                        re=calculate(symbol,next,l,r);
                    }
                    else if(next =='='){
                        calculateSelf(symbol,l,r);
                        re =l;
                    }
                    cout<<right<<" "<<symbol<<next;
                    if(next !=' ') cout<<" ";
                }
            if(compare)
            {
                if(cResult)cout<<"\t: True"<<endl;
                else
                    cout<<"\t: False"<<endl;
                compare =false;
            }
            else
                cout<<"\t:"<<re<<endl;
            }//if statement
        //}//while loopend
    }//for loop
    
    return 0;
}


