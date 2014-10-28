#include <iostream>
#include <unistd.h>
#include "lru_cache.cpp"

using namespace std;
using namespace util::lru;

int main()
{
  while(true)
  {
    LRU_CACHE<int, int> lru;
    lru.Init(5);
    int key, val;
    int res;
    key = 1;
    res = lru.Get(key, val);
    cout<<"res:"<<res<<", val:"<<val<<endl;
    lru.Debug();

    val = 101;
    res = lru.Put(key, val);
    lru.Debug();
    key = 2, val = 202;
    res = lru.Put(key, val);
    lru.Debug();
    key = 3, val = 203;
    res = lru.Put(key, val);
    lru.Debug();
    key = 4, val = 204;
    res = lru.Put(key, val);
    lru.Debug();
    key = 5, val = 205;
    res = lru.Put(key, val);
    lru.Debug();
    key = 6, val = 206;
    res = lru.Put(key, val);
    lru.Debug();
    key = 7, val = 207;
    res = lru.Put(key, val);
    lru.Debug();
    key = 5, val = 205;
    res = lru.Put(key, val);
    lru.Debug();

    res = lru.Get(key, val);
    cout<<"res:"<<res<<",val:"<<val<<endl;
    lru.Debug();
    cout<<"end"<<endl;
    sleep(1);
  }
  return 0;
}
