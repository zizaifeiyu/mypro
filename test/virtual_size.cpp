#include <iostream>
using namespace std;

class A
{
public:
  virtual void funa(){cout<<"A::fun2()"<<endl;}
  virtual void funb(){cout<<"A::fun2()"<<endl;}
  virtual void func(){cout<<"A::fun2()"<<endl;}
  virtual void fund(){cout<<"A::fun2()"<<endl;}
  virtual void fune(){cout<<"A::fun2()"<<endl;}
  virtual void funf(){cout<<"A::fun2()"<<endl;}
private:
  int i;
  //int j;
  //int k;
};
/*
class B 
{
public:
  virtual void fun(){cout<<"B::fun()"<<endl;}
  virtual void fun1(){cout<<"B::fun1()"<<endl;}
  virtual void fun3(){cout<<"B::fun3()"<<endl;}
};

class C : public B, public A
{
public:
  virtual void fun(){cout<<"C::fun()"<<endl;}
  virtual void fun1(){cout<<"C::fun1()"<<endl;}
};

class D : public B
{
public:
  void fun(){cout<<"D::fun()"<<endl;}
};
*/


int main()
{
  cout<<"A size:"<<sizeof(A)<<endl;
 // cout<<"B size:"<<sizeof(B)<<endl;
 // cout<<"C size:"<<sizeof(C)<<endl;
 // cout<<"D size:"<<sizeof(D)<<endl;

  return 0;
}
