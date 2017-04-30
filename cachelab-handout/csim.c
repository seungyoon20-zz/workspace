/*
=======================================================================================================
Name		: csim.c
Author		: mliu2-ywang20
Version		: 1.1
Copyright	:
Description	: Runs the whole PA3 project
=======================================================================================================
 */
#define _GNU_SOURCE
#include "cachelab.h"
#include <math.h>
#include <stdio.h>
#include "string.h"
#include <stdlib.h>

typedef struct Lines{					// The data type for the line
	int age;
	int validbit;
	unsigned long int tag;
	int block;
}Line;
int Load(Line **line,unsigned long int address,int s,int b,int E);
void incrementAge(Line **line,int S,int E);
void prinfOutput(int output);

int main(int argc,char *argv[])
{
  int usage = 0;					// The variables for storing the command line information
  int trace = 0;
  int hitCount = 0;
  int missCount = 0;
  int evictionCount = 0;
  int s = 0;
//  int e = 0;
  int b = 0;
  int S = 0;						// S will be calculated
  int E = 0;
  char *address;
  FILE *input;
  Line **line;						// The cache it self
  if(argc>1)
    {
	  int count = 1;					// Storing the cmd input logic using a while loop, when specific values is found, the count will be incremented differently
	  while(count<argc){
		  if(strcmp (argv[count],"-h")==0) {usage = 1;count++;}
		  else if(strcmp (argv[count],"-v")==0) {trace = 1;count++;}
		  else if(strcmp(argv[count],"-s")==0) {
			s = atoi(argv[count+1]);
			S = pow(2,s);
			count += 2;
		  }
		  else if(strcmp(argv[count],"-E")==0) {
			E = atoi(argv[count+1]);
			count += 2;
		  }
		  else if(strcmp(argv[count],"-b")==0) {
			b = atoi(argv[count+1]);
			count += 2;
		  }
		  else if(strcmp(argv[count],"-t")==0) {
			address = argv[count+1];
			input = fopen(address,"r"); // Read the file
			count += 2;
		  }
	  }

    }

 	line = malloc(S*sizeof(Line*));   // Set up the array
 	for(int i = 0; i<S;i++){
 		line[i] =malloc(E*sizeof(Line));
 	}
    if(b==1);
    // The up the type line in the cache
 	for(int i = 0; i<S;i++){
 		for(int j = 0; j<E;j++){
 			 Line line_default;
 			line_default.age = -1;
 			line_default.tag = -1;
 			line[i][j] = line_default;
 		}
 	}

 	char c = 0;
 	unsigned long int adr;
 	int output = 0;				// For storing different outputs caused by M L or S
 	int output2 = 0;

 	while(c!=EOF){				// This is the logic for add instructions it reads the input from file and process it depends on whether it is M L,S.
 		c = fgetc(input);
 		if(c!=EOF&&c!='\n')
 		if(trace ==1)
 		printf("%c",c);
 		 if(c== 'L'){
 		 	fscanf(input,"%lx",&adr);
 		 	if(trace==1)
 		 	printf(" %lx ",adr);
 		 	output = Load(line,adr,s,b,E);
 		 }
 		 else if(c== 'S'){
 		 	fscanf(input,"%lx",&adr);
 		 	if(trace==1)
 		 	printf(" %lx ",adr);
 		 	 output = Load(line,adr,s,b,E);
 		 }
 		 else if(c== 'M'){				// When it is M it will have two output
 		 	fscanf(input,"%lx",&adr);
 		 	if(trace==1)
 		 	printf(" %lx ",adr);
 		 	 output = Load(line,adr,s,b,E);
 		 	 output2= Load(line,adr,s,b,E);
 		 }

 		 if(c==EOF||c=='\n'){
 			if(trace==1)
 			 prinfOutput(output);
 			 if(output ==1){			// Output 1 means miss, 2 measn hit and 3 means miss eviction  thus incrementing the count of miss or hit or eviction
 				 missCount++;
 			 }
 			 if(output ==2){
 				 hitCount++;
 			 }
 			 if(output ==3){
 				 missCount++;
 				 evictionCount++;
 			 }
 			 output =0;
 			 if(output2!=0){
 	 			 if(output2 ==1){
 	 				 missCount++;
 	 			 }
 	 			 if(output2 ==2){
 	 				 hitCount++;
 	 			 }
 	 			 if(output2 ==3){
 	 				 missCount++;
 	 				 evictionCount++;
 	 			 }
 	 			if(trace==1)
 				 prinfOutput(output2);
 				 output2 = 0;
 			 }
 			if(trace==1)
 			 printf("\n");
 		 }
 	}
 	if(usage == 1)
 	printf("Hit:%d Miss:%d Eviction:%d",hitCount,missCount,evictionCount);
 	printf("\n");//Right now starts to read the file
}
// This is for gettting the index from the address by & this with address
int getDigit(int s){
	int value = 0;
	for(int i =0;i<s;i++){
		value+=pow(2,i);
	}
	return value;
}
// Load is the main operation of the cache, since right now there is not big difference between store and load, I just have one function called load
int Load(Line **line,unsigned long int address,int s,int b,int E){				// return 1 means miss 2 means hit 3 means enviction
	int mask = 0x7fffffff>>(31-s-b);
	int a = getDigit(s);
	 int compare = a<<b;
	int index = ((address & compare)>>b)&mask;
	unsigned long int tag = (address>>s>>b)&mask;       // Get the tag of the
	int found =0;
	int i = 0;
	int output =0;
	while(i<E && found ==0){
		if(line[index][i].age!=-1){					// Found the new one
			if(line[index][i].tag == tag){
				line[index][i].age =0;
				found = 1;
				output = 2;
			}
		}
		i++;
	}
	if(output!=2) output =1;
	i = 0;
	while(found ==0&&i<E){							// check for miss
		if(line[index][i].age==-1){
			line[index][i].tag = tag;
			line[index][i].age = 0;
			found =1;
		}
		i++;
	}
	i = 0;
	int maxIn = 0;
	int max = line[index][0].age;
	if(found ==0){
		while (i<E){							// check for eviction
			if(line[index][i].age>max){
				maxIn = i;
				max = line[index][i].age;
			}
			i++;
		}
		line[index][maxIn].age = 0;
		line[index][maxIn].tag = tag;
		output = 3;
	}
	incrementAge(line,pow(2,s),E);				// After each time load, the age of lines in the cache will be increments to form the LRU cache
	return output;
}
// This will increment age of lines in cache if it is not -1
void incrementAge(Line **line,int S,int E){
	for(int i = 0; i<S;i++){
		for(int j = 0; j<E;j++){
			if(line[i][j].age!=-1){
				line[i][j].age++;
			}
		}
	}
}
// based on different value of output has the corresponding prinf on cmd.
void prinfOutput(int output){
	if(output == 2) printf("%s"," hit");
	if(output == 1) printf("%s"," miss");
	if(output == 3) printf("%s"," miss eviction");
}
