#produced by ywang20
CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	Organism.o Doodle.o Ant.o PA6.o

LIBS =

TARGET =	PA6

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)