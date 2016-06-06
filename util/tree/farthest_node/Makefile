all: tt

tt:farthest_node.o
	g++ farthest_node.o -o tt

travel.o:farthest_node.cpp
	g++ -c farthest_node.cpp

clean:
	rm -f *.o tt core*
