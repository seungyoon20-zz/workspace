# Make file for PA2
# WRITTEN BY: Yixue Wang, Jan 27, 2017
# This makefile is used as follows to regenerate files for the sinewave program:
#   make Board.o   --  Regenerates Board.o by compiling
#   make Game.o   --  Regenerates Game.o by compiling
#   make Life.o   --  Regenerates Life.o by compiling
#   make Life    --  Regenerates the executable sinewave file by compiling
#   make              --  Same as "make Life”
#

CFLAGS = -g

Life: Board.o Game.o Life.o
	gcc $(CFLAGS) -Wall Board.o Game.o Life.o -lm -o Life 

Board.o: Life.h Board.c
	gcc $(CFLAGS) -Wall -c Board.c

Game.o: Life.h Game.c
	gcc $(CFLAGS) -Wall -c Game.c

Life.o: Life.h Life.c
	gcc $(CFLAGS) -Wall -c Life.c

clean:
	rm -f Board.o Game.o Life.o Life

all: Life
