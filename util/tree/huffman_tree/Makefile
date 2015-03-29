all: ht

ht:main.o huffman_tree.o
	g++ main.o huffman_tree.o -o ht

huffman_tree.o:huffman_tree.cpp
	g++ -c huffman_tree.cpp

main.o:main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o ht
