all: ml 

ml:main.o
	g++ main.o -o lp 

main.o:main.cpp
	 g++ -c main.cpp

clean:
	rm -f *.o lp 
