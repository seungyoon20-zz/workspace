CS2302-PA2-C01-YixueWang-ywang20

********This program is totally my own work***********

*****Summary*****
-This program is made by Life.c, Game.c, Board.c and Life.h.
-The Life.h acts as an interface of the entire program. 
-The Life.c has the main function, reads the arguments and input file, and initialize the 
	game board.
	-Life.c allocates the memory of each game board(ex. game board B)by allocating memory for 
		each row first. Then using for-loop to allocate memory for the array starting from 
		B+i and jump to the next row until the end of B.
	-Life.c used for-loop to initialized all values on game boards.
	-Life.c has a integer c to store the value read from the input. The loop start from position
		B+x and read one more character each time.If c equals “x”, store 1 at its position.
		If c equals “o”, do nothing. Read the input file until getting a “\n”.
		If get a “\n”, stop the inner while-loop and enter next row.
-The Game.c contains functions supporting the game: ifStop() and playOne().
-The Board.c contains 
	-countNeighbors(), which considers a board and a position on the board 
	to count the number of neighbors of the given position.
	-ifSame(). Considers 2 boards and compare every element in the boards. If all elements
		are same in 2 boards, return 1, else return 0.



*****How to use it*****
-Run “make” in the cmd line to compile it first.
-Then call ./Life in the cmd line with at least 5 arguments indicating the program name,
 	the x value, y value, number of generation want to play, and the input filename. 	
	-The 6th and 7th arguments are read as options for print and pause.
	-If there are more than 7 arguments, arguments after the 7th will be automatically
		ignored.
-The x value and y value need to be determined by the player by checking the input file
 	first. For example the acorn.txt has 3 rows and 8 columns(at most, in the 3rd 
	row).
-The game board will be initialized as (3*x)*(3*y) to make sure there is enough space

-EX:    ./life 3 3 10 blinker.txt y n
	./life 3 8 10 acorn.txt y y 

-If you choose to pause between generations, you have to press ENTER to enter next 	
	generation every time the cmd line tells you to do so.

-Every time the program will print the initial board first and start to play.

-If you choose not to pause and not to print, the program will just print the initial board
	and the final state.


