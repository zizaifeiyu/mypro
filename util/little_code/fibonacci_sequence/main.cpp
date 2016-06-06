#include <iostream>
#include "fibonacci_sequence.h"

using namespace std;


int main()
{
  unsigned int n = 10;
  long fn = GetFibonacciNumNonRecursion(n);

  cout<<"main fn("<<n<<"):"<<fn<<endl;

  return 0;
}


