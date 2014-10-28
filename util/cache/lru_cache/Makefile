all:lru

lru:main.o lru_cache.o
	g++ main.o lru_cache.o -o lru
main.o:main.cpp
	g++ -c main.cpp
lru_cache.o:lru_cache.cpp
	g++ -c lru_cache.cpp

clean:
	rm -rf *.o lru
