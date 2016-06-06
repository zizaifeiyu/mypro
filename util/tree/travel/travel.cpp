#include <iostream>
#include <stack>
#include <queue>

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
bool HighFirstNonRecursion(Node *root);
bool PushNodesLeftFirst(Node *root, stack<Node*> &ns);
bool HighMiddleNonRecursion(Node *root);
bool LevelNoRecursion(Node *root);
bool LevelNoRecursionLR(Node *root);

int main()
{
  Node *root = InitTestTree();
  if(root == NULL)
  {
    cout<<"root is null"<<endl;
  }
  cout<<"#### high first begine ####"<<endl;
  IterFirst(root);
  cout<<"#### high first end    ####"<<endl;

  cout<<"#### high first no recursion begine ####"<<endl;
  HighFirstNonRecursion(root);
  cout<<"#### high first no recursion end    ####"<<endl;

  cout<<"#### high middle begine ####"<<endl;
  IterMiddle(root);
  cout<<"#### high middle end    ####"<<endl;

  cout<<"#### high middle no recursion begine ####"<<endl;
  HighMiddleNonRecursion(root);
  cout<<"#### iter middle no recursion end    ####"<<endl;


  cout<<"#### high last begine ####"<<endl;
  IterLast(root);
  cout<<"#### high last end    ####"<<endl;

  cout<<"#### level no recursion begine ####"<<endl;
  LevelNoRecursion(root);
  cout<<"#### level no recursion end    ####"<<endl;

  LevelNoRecursionLR(root);
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
// 前序
bool HighFirstNonRecursion(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  stack<Node *> ns;
  ns.push(root);
  Node *tmp = NULL;
  while(!ns.empty())
  {
    tmp = ns.top();
    ns.pop();
    DoSomething(tmp);
    if(NULL != tmp->r_child)
      ns.push(tmp->r_child);
    if(NULL != tmp->l_child)
      ns.push(tmp->l_child);
  }
  
  return true;
}

// 深度遍历 非递归
// 中序
bool PushNodesLeftFirst(Node *root, stack<Node*> &ns)
{
  while(NULL != root)
  {
    ns.push(root);
    root = root->l_child;
  }
  return true;
}

bool HighMiddleNonRecursion(Node *root)
{
  if(NULL == root)
    return true;

  stack<Node *> ns;

  PushNodesLeftFirst(root, ns);

  Node *tmp;
  while(!ns.empty())
  {
    tmp = ns.top();
    ns.pop();
    DoSomething(tmp);
    PushNodesLeftFirst(tmp->r_child, ns);
  }

  return true;
}

// 广度遍历 递归
bool LevelRecursion(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  queue<Node *> qs;
  qs.push(root);

  Node *tmp;
  while(!qs.empty())
  {
    tmp = qs.front();
    qs.pop();
    DoSomething(tmp);
    if(NULL != tmp->l_child)
      qs.push(tmp->l_child);
    if(NULL != tmp->r_child)
      qs.push(tmp->r_child);
  }

  return true;
}

bool LevelNoRecursion(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  queue<Node *> qs;
  qs.push(root);

  Node *tmp;
  while(!qs.empty())
  {
    tmp = qs.front();
    qs.pop();
    DoSomething(tmp);
    if(NULL != tmp->l_child)
      qs.push(tmp->l_child);
    if(NULL != tmp->r_child)
      qs.push(tmp->r_child);
  }

  return true;
}

bool LevelNoRecursionLR(Node *root)
{
  if(NULL == root)
  {
    return true;
  }

  queue<Node *> qs;
  qs.push(root);
  int cn = 1;
  int nn = 0;

  Node *tmp;
  while(!qs.empty())
  {
    tmp = qs.front();
    qs.pop();
    --cn;
    if(NULL != tmp->l_child)
    {
      qs.push(tmp->l_child);
      ++nn;
    }
    if(NULL != tmp->r_child)
    {
      qs.push(tmp->r_child);
      ++nn;
    }
    if(0 == cn)
    {
      DoSomething(tmp);
      cn = nn;
      nn = 0;
    }
  }

  return true;
}
