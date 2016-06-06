#include <iostream>
using namespace std;

long c16to10(const char *a)
{
  long res = 0;
  long len = strlen(a);
  long weight = 16;
  long p = 1;
  long pos = 0;
  if(len > 0 && a[0] == '-')
  {
    p = -1;
    ++pos; 
  }

  while(pos < len)
  {
    long i = 0;
    if(a[pos] >= '0' && a[pos] <= '9')
      i = a[pos] - '0';
    else if(a[pos] >= 'a' && a[pos] <= 'f')
      i = a[pos] - 'a' + 10;
    else if(a[pos] >= 'A' && a[pos] <= 'F')
      i = a[pos] - 'A' + 10;
    else
      break;

    res = res * weight + i;
    ++pos; 
  }

  if(p == -1)
    res *= -1;
  return res;
}

int main()
{
  const char * a = "1Abcd";
  long res = c16to10(a);
  cout<<"long res:"<<res<<endl;
  int i = 1;
  cout<<~i<<endl;
  int j = -1;
  cout<<~j<<endl;

  return 0;
}
