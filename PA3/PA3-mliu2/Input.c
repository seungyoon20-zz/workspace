/*
=======================================================================================================
Name		: Life.c
Author		: Mingquan Liu
Version		: 1.1
Copyright	:
Description	: Play Convey's game of life
=======================================================================================================
 */
#include <stdio.h>
#include "Tree.h"
#include <stdlib.h>
#include "Input.h"
#include <ctype.h>
#include <string.h>
//#include <time.h>
//extern FILE* timeOutput;


Node* parseFile(FILE *fp, Node *p, Node *parent){        // Select the desired word from the input file and store them into the tree.
    char temp[50];                                       // For temporary processing the word
    int c;
    int count;
    char *word;
    int temp_int;
   // Node *target;

    count = 0;
    while ((c = fgetc(fp)) != EOF) {
        if( c == 39 && count != 0 ){
            temp_int = fgetc(fp);
            
            if(isalpha(temp_int)){
                temp[count] = c;
                temp[count+1] = temp_int;
                count= count+ 2;
                continue;                      //When it detects words like it's
            }
           
        }
        
    	if(isalpha(c) ){				//if word chuu
    		temp[count] = tolower(c);
    		count++;
    		continue;
    	}

    	if (count == 0){						//if blank keep looking for words
    		continue;
    	}

    	temp[count] = 0;
    	word = malloc(count * sizeof(char));     // Copy the word from the temporary word and pass it to the tree.
        word = strcpy(word, temp);
        
        
        
    	p = addItem(p, word, parent);
        
        
//        clock_t begin = clock();
//        target = findItem(p, "elephant");
//        clock_t end = clock();
//        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
        
        
//        fprintf(timeOutput, "%f\n", time_spent);
    	free(word);
    	count = 0;
    }
    
    return p;

}

