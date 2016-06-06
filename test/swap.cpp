#include <time.h>
#include <iostream>
using namespace std;

void NormalSwap(int &i, int &j);
void YHSwap(int &i, int &j);

int main()
{
  time_t tm;
  time(&tm);
  cout<<"tm = "<<tm<<endl;
  int i = 3;
  int j = 9;
  for(int k = 0; k < 900000000; ++k)
  {
    NormalSwap(i ,j);
  }
  time_t tm1;
  time(&tm1);
  cout<<"elapsed time = "<<(tm1 - tm)<<endl;
  for(int k = 0; k < 900000000; ++k)
  {
    YHSwap(i, j);
  }
  time_t tm2;
  time(&tm2);
  cout<<"elapsed time = "<<(tm2 - tm1)<<endl;
  return 0;
}

void NormalSwap(int &i, int &j)
{
  int t = i;
  i = j;
  j = t;
}

void YHSwap(int &i, int &j)
{
  i ^= j;
  j ^= i;
  i ^= j;
}
