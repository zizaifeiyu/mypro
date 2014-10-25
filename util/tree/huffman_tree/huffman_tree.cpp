#include <algorithm>
#include "huffman_tree.h"

using namespace std;
using namespace util;

HuffmanTree::HuffmanTree()
{
  in_data_ = NULL;
}

HuffmanTree::HuffmanTree(const char *in_cdata)
{
  if(NULL == in_cdata)
  {
    in_data_ = NULL;
  }
  in_data_ = in_cdata;
}

HuffmanTree::HuffmanTree(
    const string &in_sdata)
{
  in_data_ = in_sdata.c_str();
}

int HuffmanTree::set_in_data(
    const char *in_cdata)
{
  if(NULL == in_cdata)
  {
    return ERR_IN_CDATA;
  }

  in_data_ = in_cdata;

  return RC_OK;
}

int HuffmanTree::set_in_data(
    const string &in_sdata)
{
  in_data_ = in_sdata.c_str();
  return RC_OK;
}

int HuffmanTree::build_cw_map()
{
  const char *c = in_data_;
  map<char, int>::iterator iter;
  while(*c != '\0')
  {
    if((iter = cw_map_.find(*c))
       != cw_map_.end()) 
    {
      ++iter->second;
    }
    else
    {
      cw_map_[*c] = 1;
    }
  }

  return RC_OK;
}

int HuffmanTree::build_cw_vec()
{
  build_cw_map();
  CharWeight cw;
  for(map<char,int>::iterator 
      iter = cw_map_.begin();
      iter != cw_map_.end();
      ++iter)
  {
    cw.c = iter->first;
    cw.w = iter->second;
    cws_vec_.push_back(cw);
  }

  //  sort
  sort(cws_vec_.begin(), cws_vec_.end(), HuffmanTree::CampareCW);

  return RC_OK;
}

int HuffmanTree::build_huffman_tree()
{
  build_cw_vec();

  return RC_OK;
}

int HuffmanTree::build_huffman_code()
{
  
  return RC_OK;
}
