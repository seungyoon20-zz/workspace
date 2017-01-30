#include <stdio.h>
#include <stdlib.h>

int **A,**B,**C;
unsigned int r,c;


void setUpArray(int x,int y){
  A = malloc(x*sizeof(int *));
  if(A) for(int i=0;i<x;i++){
      A[i]= malloc(y*sizeof(int));
      if(!A[i])exit(-1);     // error returning
    }
  
  B = malloc(x*sizeof(int *));
  if(B) for(int j=0;j<x;j++){
      B[j]= malloc(y*sizeof(int));
      if(!B[j])exit(-1);     // error returning
    }

  C = malloc(x*sizeof(int *));
  if(C) for(int k=0;k<x;k++){
      C[k]= malloc(y*sizeof(int));
      if(!C[k]) exit(-1);  // error returning
    }

  for(int a=0;a<x;a++)
    for(int b=0;b<x;b++){
      A[a][b]=0;B[a][b]=0;C[a][b]=0;}
}

int main(int argc,char *argv[])
{
FILE *input;
 int x,y,gens; //Variables for recording the size of the life initiation and the 

 if(argc < 5)printf("Error");  // Error testing

 x = atoi(argv[1]);
 y = atoi(argv[2]);
 gens = atoi(argv[3]);
 input = fopen(argv[4],"r");
 if(!input) printf("Unable to open the file.\n");
 if(gens);
 r = 3*x;c=3*y;
 
 setUpArray(r,c); // Set up the three board

  for (int l =x;l<2*x;l++)
   for(int m =y; m<=2*y;m++){
     int c = getc(input);
     if(c==120){
	A[l][m]=1;
	}
     if(c==10)m=m+y;
      printf("%d\n",c);
   }
/*
 for(int a=0;a<r;a++){printf("\n");
   for(int b=0;b<c;b++){ printf("%d",A[a][b]);}
   }*/
}
