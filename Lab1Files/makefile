# Make file for Lab Exercise 2
# WRITTEN BY: Michael Main (main@colorado.edu), Jan 11, 1997
# MODIFIED BY:  Glynis Hamel 3/2/99
# MODIFIED BY:  Glynis Hamel 3/21/02
# MODIFIED BY:  Glynis Hamel 11/14/05 Converted from C++ to C
# MODIFIED BY:  Hugh Lauer 04/06/09 Substituted $(CFLAGS) for -g
# MODIFIED BY:	Hugh Lauer 08/18/13 Added -Wall and -m32 to CFLAGS
# MODIFIED BY:	Hugh Lauer 12/29/2016 Removed -m32 flag (to allow 64-bit compilation)
#				Also added "all" target for Eclipse
#
# This makefile is used as follows to regenerate files for the sinewave program:
#   make intarray.o   --  Regenerates intarray.o by compiling
#   make sinewave.o   --  Regenerates sinewave.o by compiling
#   make sinewave     --  Regenerates the executable sinewave file by compiling
#   make              --  Same as "make sinewave"
#

CFLAGS = -g

sinewave: intarray.o sinewave.o
	gcc $(CFLAGS) -Wall sinewave.o intarray.o -lm -o sinewave 

intarray.o: intarray.h intarray.c
	gcc $(CFLAGS) -Wall -c intarray.c

sinewave.o: intarray.h sinewave.c
	gcc $(CFLAGS) -Wall -c sinewave.c

clean:
	rm -f sinewave.o intarray.o sinewave

all: sinewave


