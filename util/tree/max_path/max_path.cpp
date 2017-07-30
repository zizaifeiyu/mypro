#include <cstdlib>
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
//*************************************
//题目：
//     求一棵二叉树中距离相差最远的两个结点之间的距离。
//     
//        
//思路：注意指针声明了一定要赋值，否则会报错。
//        方法一：递归法
//距离相差最远的两个结点，共有以下两种情况：
//  (1)路径经过根结点，所以两个结点在根结点的不同分支上
//  (2)路径不经过根结点，所以两个结点应该是次根结点中相聚最远的两个结点。(递归思想)  
//  递归本质上还是采用了后续遍历的方法。由于是从叶子结点开始的所以每次处理都是第一种情况。
//        方法二：非递归法
//采用后序遍历二叉树的同时对二叉树的结点进行更新，每次更新都要更新最大距离。
//
//*************************************


//
//定义结点结构
//
struct NODE
{
  NODE* l_child;
  NODE* r_child;
  int n_max_left;
  int n_max_right;
  int data;    
};
int t_max_length = 0;    //最大距离

stack<NODE*> s;

//
//求最大距离(方法一)
//
void findMaxLength1(NODE* root)
{
}

//
//求最大距离(方法二)
//
void findMaxLength2(NODE* root)
{
}

//
//中序遍历
//
void inOrderTraverse(NODE* root)
{

}

//
//后序遍历
//
void postOrderTraverse(NODE* root)
{
  if(NULL == root)
  {
    return;
  }
  
  s.push(root);
  NODE *p = NULL;
  while(!s.empty())
  {
    p = s.top();
    while(NULL != p)
    {
      if(NULL != p->l_child)
        s.push(p->l_child);
      p = p->l_child;
    }
    p = s.top();
    cout<<p->data<<"\t"<<endl;
    s.pop();
    if(NULL != p->r_child)
      s.push(p->r_child);
  }
}

//
//初始化树
//
NODE* initTree()
{
  NODE* tree[10];

  for(int i=0;i<10;i++)
  {
    tree[i]=(NODE*)malloc(sizeof(NODE));
    tree[i]->n_max_left=0;
    tree[i]->n_max_right=0;
    tree[i]->l_child=NULL;
    tree[i]->r_child=NULL;
    tree[i]->data= i;
  }
  for(int i=0;i<=2;i++)
  {
    tree[i]->l_child=tree[2*i+1];
    tree[i]->r_child=tree[2*i+2];
  }
  tree[3]->l_child=tree[7];
  tree[5]->r_child=tree[8];
  return tree[0];
}
int main()
{    
  printf("后序遍历：");
  postOrderTraverse(initTree());
//  printf("\n");
//  printf("中序遍历：");
//  inOrderTraverse(initTree());
//  printf("\n");
//  findMaxLength2(initTree());
//  printf("非递归:%d\n",tMaxLength);
//  tMaxLength = 0;
//  findMaxLength1(initTree());
//  printf("递归法:%d\n",tMaxLength);
  return 0;
}
