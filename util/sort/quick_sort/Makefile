all:qs

qs:main.o quick_sort.o
	g++ main.o quick_sort.o -o qs
main.o:main.cpp
	g++ -c main.cpp
quick_sort.o:quick_sort.cpp
	g++ -c quick_sort.cpp

clean:
	rm -rf *.o qs
