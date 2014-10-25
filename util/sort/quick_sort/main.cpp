#include <iostream>
#include "quick_sort.h"
using namespace std;
using namespace util;

int main()
{
  int a[10] = {1, 3, 5, 7, 9, 8,6,4,2,10};
  cout<<"src array:"<<endl;
  for(int i = 0; i < 10; ++i)
  {
    cout<<a[i]<<"\t";
  }
  cout<<endl;
  QuickSort(a, 0, 9);
  cout<<"sort array:"<<endl;
  for(int i = 0; i < 10; ++i)
  {
    cout<<a[i]<<"\t";
  }
  cout<<endl;
  return 0;
}
