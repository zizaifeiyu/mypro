#include "trie.h"

using namespace std;
using namespace util::trie;

Trie::Trie()
{
  _root = NULL;
}

Trie::~Trie()
{
  if(NULL != _root)
  {
    TN *tmp_tn = NULL;
    queue<TN*> qe_tn;
    qe_tn.push(_root);

    while(!qe_tn.empty())
    {
      tmp_tn = qe_tn.front();
      qe_tn.pop();

      if(NULL != tmp_tn->rbro)
      {
        tmp_tn->push(tmp_tn->rbro);
      }

      if(NULL != tmp_tn->lchild)
      {
        tmp_tn->push(tmp_tn->lchild);
      }
      
      cout<<"delete: "<<tmp_tn->data<<endl;
      delete tmp_tn;
    }
  }
}

bool Trie::Init()
{  
  if(NULL != _root)
  {
    cerr<<"Trie::init, reinit."<<endl;
    return false;
  }


  return true;
}

bool Trie::AddString(const string &str)
{
  return AddString(str.c_str());
}

bool Trie::AddString(const char *const cstr)
{
  if(NULL == _root)
  {
    return false;
  }

  TN *ptn = _root->lchild;
  TN *pparent = _root;
  const char *ctmp = cstr;
  while(*tmp != '\n' && ptn != NULL)
  {
    if(!(('A'<=*ctmp && *ctmp <= 'Z')||('a' <= *ctmp && *ctmp <='z')))
    {
      cerr<<"receive string has analpha, string:"<<cstr<<"."<<endl;
    }

    if(ptn->data == *ctmp)
    {
      ++ctmp;
      pparent = ptn;
      ptn = ptn->lchild;
      break;
    }
    else if(tn->data < *ctmp)
    {
         
    }
  }
}

bool Trie::AddTN(const TN *parent, const TN *lbro, const TN *rbro,
    TN *tn)
{
  try
  {
    tn = new TN;
  }
  catch(bad_alloc& ba)
  {
    cerr<<"Trie::AddTN, bad_alloc caught: "<<ba.what()<<endl; 
    tn = NULL;
    return false;
  }

  tn->lchild = NULL;
  tn->rbro = NULL;

  return true;
}
