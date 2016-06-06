all: tt

tt:weight.o
	g++ weight.o -o tt

travel.o:weight.cpp
	g++ -c weight.cpp

clean:
	rm -f *.o tt core*
