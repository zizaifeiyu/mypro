#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
  char * cs = new char [10];
  cs[0] = 'a';
  cs[1] = 'b';
  cs[2] = 'c';
  cs[3] = 'd';
  cs[4] = '\0';
  cout<<"cs val:"<<cs<<"  cs address:"<<static_cast<const void *>(cs)<<"."<<endl;

  pid_t pid;
  for(int i=0; i<10; ++i)
  {
    pid = fork();
    if(pid == 0)
    {
      continue;
    }
    else if(pid > 0)
    {
      if(5 == i)
      {
        cs[2] = '@';
      }
      break;
    }
    else
    {
      cerr<<"fork error, pid < 0"<<endl;
    }

  }
  if(pid == 0)
  {
    cout<<"father cs val:"<<cs<<"  cs address:"<<static_cast<const void *>(cs)<<"."<<endl;
    wait(0);
  }
  else
  {
    cout<<"sub cs val:"<<cs<<"  cs address:"<<static_cast<const void *>(cs)<<"."<<endl;
  }
  delete[] cs;
  return 0;
}
