#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *lc;
  Node *rc;
};


bool DoSomething(Node *root);
bool IterFirst(Node *root);

Node *RebuildTree(int *p, int *m, int len);
int main()
{
  int p[] = {1, 2, 4, 5, 7, 3, 6};
  int m[] = {4, 2, 7, 5, 1, 3, 6};
  Node *root = RebuildTree(p, m, sizeof(p)/sizeof(int));

  IterFirst(root);
}

Node *RebuildTree(int *p, int *m, int len)
{
  if(len <= 0 || NULL == p || NULL == m)
    return NULL;

  Node *root = new Node;
  root->data = *p;

  int m_pos = 0;
  for(; m_pos < len; ++m_pos)
  {
    if(*p == m[m_pos])
      break;
  }

  root->lc = RebuildTree(p+1, m, m_pos);
  root->rc = RebuildTree(p+m_pos+1, m + m_pos + 1, len - m_pos -1);

  return root;
}


///
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

  if(NULL != root->lc)
    IterFirst(root->lc);

  if(NULL != root->rc)
    IterFirst(root->rc);

  return true;
}

