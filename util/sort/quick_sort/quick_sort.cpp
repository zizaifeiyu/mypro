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
  if(left == right)
    return true;

  int mp = (left + right) / 2;
  int lp = left;
  int rp = right;
  while(mp != lp || mp != rp)
  {
    while(rp > mp)
    {
      if(ia[rp] > ia[mp])
        --rp;
      else
      {
        Swap(ia[rp], ia[mp]);
        mp = rp;
        break;
      }
    }

    while(lp < mp)
    {
      if(ia[lp] <= ia[mp])
        ++lp;
      else
      {
        Swap(ia[lp], ia[mp]);
        mp = lp;
        break;
      }

    }
  }

  if(left < mp-1)
    QuickSort(ia, left, mp-1);
  if(mp+1 < right)
    QuickSort(ia, mp+1, right);

  return true;
}

} // namespace util
