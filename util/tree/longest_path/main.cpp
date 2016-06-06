#include <iostream>
#include <cmath>
#include "ml.h"
using namespace std;

int GenLongestPath(const TreeNode *root);

int main()
{
  TreeNode root;
  

  cout<<"finish."<<endl;
  return 0;
}

int GenLongestPath(struct TreeNode *root)
{
  if((NULL == root ) || (NULL == root->lchild && NULL == root->rchild) )
  {
    return 0;
  }

  int l_ml, r_ml;
  if(NULL != root->lchild)
  {
    l_ml = GenLongestPath(root->lchild); 
    root->ll = max(root->lchild->ll, root->lchild->rl) + 1;
  }
  else
  {
    l_ml = 0;
    root->ll = 0;
  }

  if(NULL != root->rchild)
  {
    r_ml = GenLongestPath(root->rchild); 
    root->rl = max(root->rchild->ll, root->rchild->rl) + 1;
  }
  else
  {
    r_ml = 0;
    root->rl = 0;
  }
  
  root->ml = max((root->ll + root->rl), max(l_ml, r_ml));
  return root->ml;
}
