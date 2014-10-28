#ifndef UTIL_CACHE_LRU_H_
#define UTIL_CACHE_LRU_H_

#include <vector>
#include <ext/hash_map>

namespace util
{
namespace lru
{

template <class K, class V>
struct Entry
{
  Entry *pre;
  Entry *next;
  K key;
  V val;
};

template <class K, class V>
class LRU_CACHE
{
  public:
    LRU_CACHE();
    ~LRU_CACHE();
    int Init(unsigned int cache_size);
    int Get(K &key, V &val);
    int Put(K &key, V &val);
    int Attach(Entry<K,V> *entry);
    int Deatch(Entry<K,V> *entry);
    int Debug();
  private:
    Entry<K,V> *head_;
    Entry<K,V> *tail_;
    Entry<K,V> *entries_;
    std::vector<Entry<K,V>*> free_enties_;
    __gnu_cxx::hash_map<K, Entry<K,V>*> hmap_;

};  // class LRU_CACHE

} // namespace lru
} // namespace util
#endif
