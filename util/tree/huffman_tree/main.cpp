#include <iostream>
#include "huffman_tree.h"

using namespace std;
using namespace util;
int main()
{
  cout<<"------ begin ------"<<endl;

  HuffmanTree huffman_tree;
  huffman_tree.set_in_data("abcbccd");
  huffman_tree.build_huffman_code();

  cout<<"------ huffman code: ------"<<endl;
  huffman_tree.DebugInfo();

  cout<<"------ end ------"<<endl;

  return 0;
}

