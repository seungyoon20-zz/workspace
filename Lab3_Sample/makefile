# Makefile for Lab Exercise 3
# WRITTEN BY: 	Hugh C. Lauer 7/19/2013
#
# This makefile is used as follows to regenerate files for the Lab3_Sample program.
#

CFLAGS = -g

all: Lab3_Sample

Lab3_Sample: Sample.o
	gcc -Wall -m32 $(CFLAGS) Sample.o -o Lab3_Sample 

Sample.o: Sample.c
	gcc -Wall -m32 $(CFLAGS) -c Sample.c
	
clean:
	rm -f *.o *.exe Lab3_Sample


