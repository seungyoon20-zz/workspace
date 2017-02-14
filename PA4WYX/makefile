# Make file for PA4
# WRITTEN BY: Yixue Wang
# This makefile is used as follows to regenerate files for the life program:
#   make Tree.o   --  Regenerates Tree.o by compiling
#   make Input.o   --  Regenerates Input.o by compiling
#   make Output.o   --  Regenerates Output.o by compiling
#   make PA3.o   --  Regenerates PA3.o by compiling
#   make PA3    --  Regenerates the executable PA3 file by compiling
#   make              --  Same as "make PA3”
#

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	Event.o  EventQueue.o Teller.o qSim.o

LIBS =

TARGET =	qSim

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)