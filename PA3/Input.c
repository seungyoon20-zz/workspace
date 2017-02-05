//////////PA3///////////ywang20/////////////////
#include <stdio.h>
#include "Tree.h"
#include <stdlib.h>
#include "Input.h"
#include <ctype.h>
#include <string.h>


Node* parseFile(FILE *fp, Node *p, Node *parent){
    char temp[50];
    int c;
    int count;
    char *word;
    int temp_int;


    count = 0;
    while ((c = fgetc(fp)) != EOF) {
        if( c == 39 && count != 0 ){
            temp_int = fgetc(fp);
            
            if(isalpha(temp_int)){
                temp[count] = c;
                temp[count+1] = temp_int;
                count= count+ 2;
                continue;
            }
           
        }
        
    	if(isalpha(c) ){				//if word chuu
    		temp[count] = tolower(c);
    		count++;
    		continue;
    	}

    	if (count == 0){						//if blank
    		continue;
    	}

    	temp[count] = 0;
    	word = malloc(count * sizeof(char));
        word = strcpy(word, temp);
    	p = addItem(p, word, parent);
    	free(word);
    	count = 0;
    }
    return p;

}

