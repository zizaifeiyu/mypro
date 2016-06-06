#include <iostream>
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

int HuffmanTree::build_cws_map()
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
    ++c;
  }

  return RC_OK;
}

int HuffmanTree::build_cws_vec()
{
  build_cws_map();
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

int HuffmanTree::build_huffman_code()
{
  build_cws_vec();

  string last_hf_code = "";
  char cur_char;

  while(!cws_vec_.empty())
  {
    cur_char = cws_vec_.back().c;
    cout<<" build hufman code, char:"<<cws_vec_.back().c<<", \tweight:"<< cws_vec_.back().w<<endl;
    cws_vec_.pop_back();
    string hf_code = last_hf_code + "1";
    huffman_code_[cur_char] = hf_code; 
    last_hf_code += "0";
  } 

  return RC_OK;
}

int HuffmanTree::Clean()
{
  cw_map_.clear();
  cws_vec_.clear();
  huffman_code_.clear();
  return 0;
}

int HuffmanTree::DebugInfo()
{
  for(map<char, string>::iterator iter=huffman_code_.begin(); 
      iter!=huffman_code_.end(); 
      ++iter)
  {
    cout<<"char: "<< iter->first<< ",\thf_code: "<<iter->second<<endl;
  }
  return 0;
}
