#include <iostream>
#include "lru_cache.h"

namespace util
{
namespace lru
{
using namespace std;  
using namespace __gnu_cxx;  

template<class K, class V>
LRU_CACHE<K, V>::LRU_CACHE()
{
  head_ = NULL;
  tail_ = NULL;
  entries_ = NULL;
}

template<class K, class V>
LRU_CACHE<K, V>::~LRU_CACHE()
{
  if(NULL != head_)
  {
    delete head_;
  }

  if(NULL != tail_)
  {
    delete tail_;
  }

  if(NULL != entries_)
  {
    delete[] entries_;
  }
}

template<class K, class V>
int LRU_CACHE<K, V>::Init(unsigned int cache_size)
{
  try{
    head_ = new Entry<K, V>;
    tail_ = new Entry<K, V>;
    entries_ = new Entry<K, V>[cache_size];

    head_->pre = NULL;
    head_->next = tail_;
    tail_->pre = head_;
    tail_->next = NULL;
    for(unsigned int i=0; i<cache_size; ++i)
    {
      free_enties_.push_back(&entries_[i]);
    }
  }
  catch(std::bad_alloc &e)
  {
    cerr<<"create lru cache error, "<<e.what()<<endl;
    delete[] entries_;
    entries_ = NULL;
    return -1;
  }

  return 0;
}
 
template<class K, class V>
int LRU_CACHE<K, V>::Get(K &key, V &val)
{
  typename hash_map<K,Entry<K,V>*>::iterator iter =hmap_.find(key);
  if(iter == hmap_.end())
  {
    cout<<"LRU_CACHE::Get, not found key:"<<key<<endl;
    return 1;
  }

  if(NULL == iter->second)
  {
    cout<<"LRU_CACHE::Get, key:"<<key<<"s val in map is null."
      <<endl;
    return -1;
  }

  val = iter->second->val; 
  cout<<"LRU_CACHE::Get, found key:"<<key<<", val:"<<val<<endl;
  return 0;
}

template<class K, class V>
int LRU_CACHE<K, V>::Put(K &key, V &val)
{
  Entry<K,V> *tmp_entry;
  typename hash_map<K,Entry<K,V>*>::iterator iter =hmap_.find(key);
  if(iter == hmap_.end()) // not in cache
  {
    cout<<"key:"<<key<<" not in cache."<<endl;
    if(!free_enties_.empty()) // has free entry
    {
      cout<<"has:"<<free_enties_.size()<<" free entries, get one" 
        <<endl;
      tmp_entry = free_enties_.back();
      free_enties_.pop_back(); 
      cout<<"has:"<<free_enties_.size()
        <<" free entries, afeter get one."<<endl;
    }
    else // no free entry
    {
      tmp_entry = tail_->pre;
      Deatch(tmp_entry);
      cout<<"no free entry,use last entry:"<<tmp_entry->key<<endl;
    }
    tmp_entry->key = key;
    tmp_entry->val = val;
    hmap_[key] = tmp_entry;
  }
  else
  {
    tmp_entry = iter->second;
    if(tmp_entry->val != val)
    {
      tmp_entry->val = val;
    }
    Deatch(tmp_entry);
  }

  Attach(tmp_entry);

  return 0;
}


template <class K, class V>
int LRU_CACHE<K,V>::Attach(Entry<K,V> *entry)
{
  head_->next->pre = entry;

  entry->pre = head_;
  entry->next = head_->next;

  head_->next = entry;

  return 0;
}

template <class K, class V>
int LRU_CACHE<K,V>::Deatch(Entry<K,V> *entry)
{

  entry->pre->next = entry->next;
  entry->next->pre= entry->pre; 

  return 0;
}

template <class K, class V>
int LRU_CACHE<K,V>::Debug()
{
  Entry<K,V> * entry = head_->next;
  cout<<"------ debue info ------"<<endl;
  cout<<"free_enties_.size():"<<free_enties_.size()<<endl;
  cout<<"cache info"<<endl;
  while(NULL != entry && tail_ != entry)
  {
    cout<<"one cache key:"<<entry->key<<", val:"<<entry->val<<endl;
    entry = entry->next;
  }

  cout<<"------ end of debug ------"<<endl;
  return 0;
}

} // namespace lru
} // namespace util
