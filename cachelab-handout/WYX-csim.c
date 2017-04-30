#include "cachelab.h"
#include <stdlib.h>
#include <stdio.h>

int s, b, E, hit, miss, eviction;
int S, B;

typedef struct{
	int v;
	int tag;
	char* block;
	int LRU;
}Line;

typedef struct{
	Line* lines;
}Set;

typedef struct{
	Set* sets;
}Cache;

Cache* initiate(){
	Cache newC;
	Cache* newCache = &newC;
	newCache->sets = (Set *) malloc((sizeof (Set)) * S);
	for(int i = 0; i < S; i++){
		newCache->sets[i].lines = (Line *) malloc((sizeof (Line)) * E);
		for(int j = 0; j < E; j ++){
			newCache->sets[i].lines[j].v = 0;
			newCache->sets[i].lines[j].tag = 0;
			newCache->sets[i].lines[j].block = (char *) malloc( B);
			newCache->sets[i].lines[j].LRU = 0;
		}
	}
	return newCache;
}

int ifHit(Set *S, int tag){
	for(int i = 0; i < E; i ++){
		Line iterator = S->lines[i];
		if(iterator.v){
			if(iterator.tag == tag){
				iterator.LRU = 0;
				return 1;
			}
		}
	}
	return 0;
}

int isFull(Set *S){
	for(int i = 0; i < E; i ++){
		if(S->lines[i].v == 0){
			return 0;
		}
	}
	return 1;
}

int getAvailableIndex(Set *S){
	for(int i = 0; i < E; i ++){
		if(S->lines[i].v == 0){
			return i;
		}
	}
	return -1;
}

void evict(Set *S, int tag){
	int max = 0;
	int index = 0;
	for(int i = 0; i < E; i ++){
		if( S->lines[i].LRU > max){
			max = S->lines[i].LRU;
			index = i;
		}
	}
	S->lines[index].tag = tag;
	S->lines[index].LRU = 0;
}

void update(Cache* C){
	for(int i = 0; i < S; i ++){
		for (int j = 0; j < E; j ++){
			if(C->sets[i].lines[j].v){
				C->sets[i].lines[j].LRU += 1;
			}
		}
	}
}


void simulate(Cache* C, unsigned long address){
	int mask = 0x7fffffff >> (31-s-b);
	int tag = 0;
	int setIndex = 0;
	tag = (address >> (s + b)) & mask;
	int mask2 = (1 << (s)) - 1;
	setIndex = (address >> b)& mask2;
	int isHit = ifHit(&C->sets[setIndex], tag);
	if(isHit){
		hit ++;
	}
	else{
		miss++;
		if(isFull(&C->sets[setIndex])){
			eviction ++;
			evict(&C->sets[setIndex], tag);
		}
		else{
			int i = getAvailableIndex(&C->sets[setIndex]);
			C->sets[setIndex].lines[i].v = 1;
			C->sets[setIndex].lines[i].tag = tag;
			C->sets[setIndex].lines[i].LRU = 0;
		}
	}
	update(C);
}

int main(int argc, char *argv[])
{

	FILE *fp;
	if(argc < 8){
		printf("No enough arguments");
		exit(-1);
	}
	else if(argc == 10){
		s = atoi(argv[3]);
		E = atoi(argv[5]);
		b = atoi(argv[7]);
		fp = fopen(argv[9], "r");
	}
	else{
		s = atoi(argv[2]);
		E = atoi(argv[4]);
		b = atoi(argv[6]);
		fp = fopen(argv[8], "r");
	}
	S = 2 << s;
	B = 2 << b;


	Cache C;
	C.sets = malloc(sizeof(Line*) * S);
	for(int i = 0; i < S; i++){
		C.sets[i].lines = malloc(sizeof(Line) * E);
		for(int j = 0; j < E; j ++){
			C.sets[i].lines[j].v = 0;
			C.sets[i].lines[j].tag = 0;
			//C.sets[i].lines[j].block = (char *) malloc((sizeof (char)) *B);
			C.sets[i].lines[j].LRU = 0;
		}
	}
	char command;
	long int address;
	if(fp == NULL){
		exit(-1);
	}
	while( command != EOF ){
		command = fgetc(fp);
		switch(command){
			case 'I':
				break;
			case 'L':
			case 'S':
				fscanf(fp, "%lx" , &address);
				simulate(&C, address);
				break;
			case 'M':
				fscanf(fp, "%lx" , &address);
				simulate(&C, address);
				simulate(&C, address);
				break;
			default:
				break;
		}
	}

	fclose(fp);
    printSummary(hit, miss, eviction);
    return 0;
}
//int main(int argc, char* argv[]){
//	printf("%d", argc);
//}
