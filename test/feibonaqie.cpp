#include <iostream>
using namespace std;

int GenFbnq(int i);

int main()
{
  
  int i = 2;
  cout<<"f("<<i<<"):"<<GenFbnq(i)<<endl;
  i = 3;
  cout<<"f("<<i<<"):"<<GenFbnq(i)<<endl;

  i = 4;
  cout<<"f("<<i<<"):"<<GenFbnq(i)<<endl;

  i = 5;
  cout<<"f("<<i<<"):"<<GenFbnq(i)<<endl;
  return 0;
}

int GenFbnq(int i)
{
  if(1 == i)
    return 0;
  else if( 2 == i)
    return 1;

  int a[2];
  a[0] = 0;
  a[1] = 1;
  int old = 1;

  for(int j = 2; j <= i; ++j)
  {
    old ^= 1;
    a[old] = a[0] + a[1];
  }

  return a[old];
}
