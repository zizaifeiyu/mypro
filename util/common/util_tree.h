#ifndef UTIL_COMMON_TREE_
#define UTIL_COMMON_TREE_

#include <vector>

namespace util
{
namespace common{

typedef struct BinaryTreeNode
{
  int data;
  BTN *lchild;
  BTN *rchild; 
}BTN;

class BinaryTree
{
public:
  BinaryTree();
  ~BinaryTree();
  bool HasLCHild(BTN *node); 
  bool HasRCHild(BTN *node); 
  bool AddLChild(BTN *node, BTN *lchild);
  bool AddLChild(BTN *node, int data);
  bool AddRChild(BTN *node, BTN *rchild);
  bool AddRChild(BTN *node, int data);
private:
  BTN *root_;
  vector<BTN *> childs_;

};

} // namespace common
} // namespace util
#endif
