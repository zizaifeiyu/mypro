#include <iostream>
#include "fibonacci_sequence.h"


/*
long GetFibonacciNum(int n)
{
  //NonRecursion
  return 0;
}
*/

// 确认取值范围不越界
long GetFibonacciNumNonRecursion(unsigned int n)
{
  if(0 == n)
    return 0;
  else if(1 == n)
    return 1;

  long la[2];
  la[0] = 0;
  la[1] = 1;
  
  int pos = 0;
  for(unsigned int i = 2; i < n; ++i)
  {
    la[pos] = la[0] + la[1];
    std::cout<<"fn("<<i<<"):"<<la[pos]<<std::endl;
    pos ^= 1;
    std::cout<<"pos:"<<pos<<std::endl;
  }

  return (la[0] + la[1]);
}
