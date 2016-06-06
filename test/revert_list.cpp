#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *InitList();
bool DestroyList(Node *head);
bool DispList(Node *head);
bool RevertList(Node **head);
int main()
{
  Node *head = InitList();
  Node *nl = head;

  DispList(head);

  cout<<"begin revert list"<<endl;
  RevertList(&head);

  DispList(head);
  DestroyList(nl);
  return 0;
}

Node *InitList()
{
  Node *node = new Node[4];
  if(NULL == node)
    return NULL;

  node[0].data = 1;
  node[0].next = &node[1];

  node[1].data = 2;
  node[1].next = &node[2];

  node[2].data = 3;
  node[2].next = &node[3];

  node[3].data = 4;
  node[3].next = NULL;

  return node;
}

bool DestroyList(Node *head)
{
  if(NULL != head)
    delete[] head;

  return true;
}

bool DispList(Node *head)
{
  while(NULL != head)
  {
    cout<<"node data:"<<head->data<<endl;
    head = head->next;
  }
  return true;
}

bool RevertList(Node **head)
{
  if(NULL == head || NULL == *head)
  {
    return true;
  }

  Node *last = NULL;
  Node *cur = *head;
  Node *next;

  while(NULL != cur)
  {
    next = cur->next;
    cur->next = last;
    last = cur;
    cur = next;
  }

  *head = last;
  return true;
}
