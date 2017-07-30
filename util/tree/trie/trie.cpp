#include "trie.h"

using namespace std;
using namespace util::trie;

Trie::Trie()
{
  root_ = NULL;
}

Trie::~Trie()
{
  if(NULL != root_)
  {
    TN *tmp_tn = NULL;
    queue<TN*> qe_tn;
    qe_tn.push(root_);

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
  if(NULL != root_)
  {
    cerr<<"Trie::init, reinit."<<endl;
    return false;
  }

  return AddTN(NULL, NULL, NULL, root_);
}

bool Trie::AddString(const string &str)
{
  return AddString(str.c_str());
}

bool Trie::AddString(const char *const cstr)
{
  if(NULL == root_)
  {
    return false;
  }

  TN *ptn = root_->lchild;
  TN *pparent = root_;
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
      continue;
    }
    else if(tn->data < *ctmp)
    {
      TN *tmp_tn = NULL;
      if(!AddString(pparent, NULL, tn, tmp_tn))
      {
        return false;
      }

    }
  }
}

bool Trie::AddTN(const TN *parent, const TN *lbro, const TN *rbro,
    TN *tn)
{
  if(NULL != rn)
  {
    return false;
  }

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

  if(NULL != parent)
  {
    parent->lchild = tn;
    tn->rbro = parent->lchild;
  }

  if(NULL != lbro)
  {
    tn->rbro = tmp_tn;  
    lbro->rbro = tn;
  }

  if(NULL != rbro)
  {
    tn->rbro = rbro;
  }

  return true;
}
