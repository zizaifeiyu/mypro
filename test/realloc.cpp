#include <iostream>
using namespace std;

int main()
{
  char *p = (char*)malloc(sizeof(char) * 10);
  cout<<"prt addr:"<<static_cast<const void *>(p)<<endl;
  p = (char*)realloc(p, sizeof(char) * 20);
  cout<<"prt addr:"<<static_cast<const void *>(p)<<endl;

  return 0;
}
