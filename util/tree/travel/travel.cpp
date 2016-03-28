#include <iostream>
#include <strace>

using namespace std;

typedef struct TreeNode
{
  int data;
  struct TreeNode *l_child, *r_child;
  TreeNode()
  {
    data = 0;
    l_child = NULL;
    r_child = NULL;
  }
  TreeNode(int i)
  {
    data = i;
    l_child = NULL;
    r_child = NULL;
  }
}Node;

Node *InitTestTree();
bool DoSomething(Node *root);
bool IterFirst(Node *root);
bool IterMiddle(Node *root);
bool IterLast(Node *root);

int main()
{
  Node *root = InitTestTree();
  if(root == NULL)
  {
    cout<<"root is null"<<endl;
  }
  cout<<"#### iter first begine ####"<<endl;
  IterFirst(root);
  cout<<"#### iter first end    ####"<<endl;

  cout<<"#### iter middle begine ####"<<endl;
  IterMiddle(root);
  cout<<"#### iter middle end    ####"<<endl;

  cout<<"#### iter last begine ####"<<endl;
  IterLast(root);
  cout<<"#### iter last end    ####"<<endl;

  if(NULL != root)
  {
    delete[] root;
    root = NULL;
  }

  return 0;
}

Node *InitTestTree()
{
  Node *root = new Node[10];
  for(int i = 0; i < 10; ++i)
  {
    root[i].data = i;
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

bool IterFirst(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  DoSomething(root);

  if(NULL != root->l_child)
    IterFirst(root->l_child);

  if(NULL != root->r_child)
    IterFirst(root->r_child);
  
  return true;
}

bool IterMiddle(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  if(NULL != root->l_child)
    IterMiddle(root->l_child);

  DoSomething(root);

  if(NULL != root->r_child)
    IterMiddle(root->r_child);
  
  return true;
}

bool IterLast(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  if(NULL != root->l_child)
    IterLast(root->l_child);

  if(NULL != root->r_child)
    IterLast(root->r_child);

  DoSomething(root);
  
  return true;
}

// 深度遍历 非递归
bool HighNonRecursion(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  strace<Node *root> ns;

  
  return true;
}

// 广度遍历 递归
bool LevelRecursion(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  strace<Node *root> ns;

  
  return true;
}
