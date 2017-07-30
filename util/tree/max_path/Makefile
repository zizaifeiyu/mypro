all:max_path

max_path:max_path.o
	g++ max_path.o -o max_path
max_path.o:max_path.cpp
	g++ -c -g max_path.cpp

clean:
	rm -f *.o max_path *.core
