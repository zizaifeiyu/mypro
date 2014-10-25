#ifndef UTIL_HUFFMAN_TREE_H_
#define UTIL_HUFFMAN_TREE_H_


#include <map>
#include <string>
#include <vector>

#include "ht_const.h"

namespace util
{

struct CharWeight
{
  char c;
  int w;
};

class HuffmanTree
{
public:
  HuffmanTree();
  HuffmanTree(const char *in_cdata);
  HuffmanTree(const std::string &in_sdata);
  int build_huffman_code();
  std::string get_huffman_code(char in_c)const;
  int clean();
  int set_in_data(const char *in_cdata);
  int set_in_data(const std::string &in_sdata);

protected:
  static bool CampareCW(const CharWeight &i, const CharWeight &j)
  {
    return i.w > j.w;
  }

  int build_cw_map();
  int build_cws_vec();
  int build_huffman_tree();

private:
  const char *in_data_;
  std::map<char, int> cw_map_;
  std::vector<CharWeight> cws_vec_;
  std::map<char, std::string> huffman_code_;
};  // HuffmanTree

} // namespace util
#endif
