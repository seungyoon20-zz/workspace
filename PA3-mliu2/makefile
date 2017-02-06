# Make file for PA3
# WRITTEN BY: Yixue Wang, Jan 27, 2017
# This makefile is used as follows to regenerate files for the life program:
#   make Tree.o   --  Regenerates Tree.o by compiling
#   make Input.o   --  Regenerates Input.o by compiling
#   make Output.o   --  Regenerates Output.o by compiling
#   make PA3.o   --  Regenerates PA3.o by compiling
#   make PA3    --  Regenerates the executable PA3 file by compiling
#   make              --  Same as "make PA3”
#

CFLAGS = -g0

PA3: Tree.o Input.o Output.o PA3.o
	gcc $(CFLAGS) -Wall Tree.o Input.o Output.o PA3.o -lm -o PA3

Tree.o: Tree.h Tree.c
	gcc $(CFLAGS) -Wall -c Tree.c

Input.o: Input.h Input.c
	gcc $(CFLAGS) -Wall -c Input.c

Output.o: Output.h Output.c
	gcc $(CFLAGS) -Wall -c Output.c

PA3.o: Tree.h Input.h Output.h PA3.c
	gcc $(CFLAGS) -Wall -c PA3.c

clean:
	rm -f Tree.o Input.o Output.o PA3.o PA3

all: PA3
