#include "quick_sort.h"

namespace util
{
  
bool Swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
  return true;
}

bool QuickSort(int *ia, int left, int right)
{

  if(left + 1 >= right)
  {
    return true;
  }

  int lpos = left;
  int rpos = right;
  while(lpos < rpos)
  {
    while(ia[lpos] <= ia[rpos] && lpos < rpos) --rpos;
    if(lpos < rpos) Swap(ia[lpos], ia[rpos]);

    while(ia[lpos] <= ia[rpos] && lpos < rpos) ++lpos;
    if(lpos < rpos) Swap(ia[lpos], ia[rpos]);
  } 

  if(lpos != left) QuickSort(ia, left, lpos-1);
  if(rpos != right) QuickSort(ia, rpos+1, right);
  return true;
}

} // namespace util
