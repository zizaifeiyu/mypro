#include <iostream>
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
bool GetTreeWeight(Node *root, int &weight);

int main()
{
  Node *root = InitTestTree();
  if(root == NULL)
  {
    cout<<"root is null"<<endl;
  }

  int weight = 0;
  GetTreeWeight(root, weight);
  cout<<"tree weight :"<<weight<<endl;

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

bool
GetTreeWeight(Node *root, int &weight)
{
  bool res = false;
  weight = 0;
  if(NULL == root)
  {
    return res;
  }

  queue<Node *> n_q;
  Node *np;
  int cw = 1;
  int nw = 0;
  int num = 0;
  n_q.push(root);
  while(!n_q.empty())
  {
    np = n_q.front();
    n_q.pop();

    if(NULL != np->l_child)
    {
      n_q.push(np->l_child);
      ++nw;
    }
    if(NULL != np->r_child)
    {
      n_q.push(np->r_child);
      ++nw;
    }

    if(++num == cw)
    {
      cw = nw;
      nw = 0;
      num = 0; 
      if(cw > weight)
        weight = cw;
    }
  }
  
  return res;
}
