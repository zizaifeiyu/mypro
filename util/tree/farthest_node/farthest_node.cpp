#include <iostream>

using namespace std;

typedef struct TreeNode
{
  int data;
  int max_d;
  int max_lh;
  int max_rh;
  struct TreeNode *l_child, *r_child;

  TreeNode()
  {
    data = 0;
    max_d = 0;
    max_lh = 0;
    max_rh = 0;
    l_child = NULL;
    r_child = NULL;
  }
  TreeNode(int i)
  {
    data = i;
    max_d = 0;
    max_lh = 0;
    max_rh = 0;
    l_child = NULL;
    r_child = NULL;
  }
}Node;

Node *InitTestTree();
bool DoSomething(Node *root);
bool GetMaxDistance(Node *root);

int main()
{
  Node *root = InitTestTree();
  if(root == NULL)
  {
    cout<<"root is null"<<endl;
  }

  GetMaxDistance(root);
  cout<<"max distance:"<<root->max_d<<endl;

  if(NULL != root)
  {
    delete[] root;
    root = NULL;
  }

  return 0;
}

Node *InitTestTree()
{
  cout<<"begin init test tree"<<endl;
  Node *root = new Node[10];
  for(int i = 0; i < 10; ++i)
  {
    root[i].data = i;
    root[i].max_d = 0;
    root[i].max_lh = 0;
    root[i].max_rh = 0;
  }

  for(int i = 0; i < 10; ++i)
  {
    if((2*i + 1) < 10)
    {
      root[i].l_child = &root[2*i + 1];
    }
    if((2*i + 2) < 10)
    {
      root[i].r_child = &root[2*i + 2];
    }
  }

  cout<<"end init test tree"<<endl;
  return root;
}

bool DoSomething(Node *root)
{
  if(NULL == root)
    return false;
  else
    cout<<root->data<<endl;
  return true;
}

bool DealLeafNode(Node *root)
{
  bool res = false;
  if(NULL == root)
    return res;

  root->max_d = 0;
  root->max_lh = 0;
  root->max_rh = 0;

  res = true;
  return res;
}

bool
GetMaxDistance(Node *root)
{
  bool res = true;
  if(root == NULL)
  {
    return res;
  }

  if(NULL == root->l_child && NULL == root->r_child) {
    return res;
  }

  if(NULL != root->l_child){
    GetMaxDistance(root->l_child);
    root->max_lh = root->l_child->max_lh + 1;
  } 

  if(NULL != root->r_child){
    GetMaxDistance(root->r_child);
    root->max_rh = root->r_child->max_rh + 1;
  } 

  if(NULL == root->l_child) {
    root->max_d = root->r_child->max_d;  
    return res;
  }

  if(NULL == root->r_child) {
    root->max_d = root->l_child->max_d;  
    return res;
  }

  if((root->max_lh + root->max_rh) > root->max_d){
    root->max_d = root->max_lh + root->max_rh;
  }

  return res;
}
