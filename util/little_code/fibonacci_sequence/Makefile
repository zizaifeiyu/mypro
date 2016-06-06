all: fn 

fn:main.o fibonacci_sequence.o
	g++ main.o fibonacci_sequence.o -o fn

fibonacci_sequence.o:fibonacci_sequence.cpp
	g++ -c fibonacci_sequence.cpp
main.o:main.cpp 
	g++ -c main.cpp

clean:
	rm -f *.o fn core*
