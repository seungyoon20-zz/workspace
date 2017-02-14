
CFLAGS = -g

qSim: bankModel.o Customer.o Teller.o Event.o eventQueue.o tellerQueue.o
	g++ -Wall bankModel.o Customer.o Teller.o Event.o eventQueue.o tellerQueue.o -o qSim

bankModel.o: bankModel.cpp Customer.h Teller.h Event.h
	g++ -Wall -c bankModel.cpp

Customer.o: Customer.cpp Event.h Customer.h
	g++ -Wall -c Customer.cpp

Teller.o: Teller.cpp Event.h Teller.h
	g++ -Wall  -c Teller.cpp	
	
Event.o: Event.cpp Event.h
	g++ -Wall -c Event.cpp	
	
eventQueue.o: eventQueue.cpp Event.h
	g++ -Wall -c eventQueue.cpp	

tellerQueue.o: tellerQueue.cpp Event.h
	g++ -Wall -c tellerQueue.cpp		
clean:
	rm -f qSim bankModel.o Customer.o Teller.o Event.o eventQueue.o tellerQueue.o

all: qSim

