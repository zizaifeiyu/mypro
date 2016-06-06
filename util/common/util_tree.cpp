#include "util_tree.h"

namespace 
{

using namespace std;
using namespace util::common;

BinaryTree::BinaryTree()
{
  root_ = new BTN;
  root_->lchild = NULL;
  root_->rchild = NULL;
}

BinaryTree::~BinaryTree()
{
  if(NULL != root_)
  {
    delete root_;
  }

  for(vector<BTN*>::iterator iter = childs_.begin();
      iter != childs_.end();
      ++iter)
  {
    delete iter;
  }
}

bool BinaryTree::HasLCHild(BTN *node)
{
  if(NULL == node || NULL == node->lchild)
  {
    return false;
  }

  return true;
}

bool BinaryTree::HasRCHild(BTN *node)
{
  if(NULL == node || NULL == node->rchild)
  {
    return false;
  }

  return true;
}


bool BinaryTree::AddLChild(BTN *node, BTN *lchild)
{
  if(NULL == node || NULL == lchild || node->HasLCHild())
  {
    return false;
  }

  node->lchild = lchild;
}

bool BinaryTree::AddLChild(BTN *node, int data)
{
  if(NULL == node || node->HasLCHild())
  {
    return false;
  }

  BTN *lchild = new BTN;
 
  lchild->data = data;
  lchild->lchild = NULL;
  lchild->rchild = NULL;

  node->lchild = lchild;
}

bool BinaryTree::AddRChild(BTN *node, BTN *rchild)
{
  if(NULL == node || NULL == rchild || node->HasRCHild())
  {
    return false;
  }

  node->rchild = rchild;
}

bool BinaryTree::AddRChild(BTN *node, int data)
{
  if(NULL == node || node->HasRCHild())
  {
    return false;
  }

  BTN *rchild = new BTN;
 
  rchild->data = data;
  rchild->lchild = NULL;
  rchild->rchild = NULL;

  node->rchild = rchild;
}
} // namespace
