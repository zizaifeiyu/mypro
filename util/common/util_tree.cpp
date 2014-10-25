#include "util_tree.h"

namespace 
{

using namespace std;
using namespace util::common;

BinaryTree::BinaryTree()
{
  root_ = new BTN;
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

} // namespace
