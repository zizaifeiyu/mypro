#ifndef UTIL_TREE_TRIE_H_
#define UTIL_TREE_TRIE_H_

#include <string>
#include <queue>

namespace util
{
namespace trie
{

typedef struct TreeNode
{
  char data;
  struct TreeNode *lchild;
  struct TreeNode *rbro;
}TN;

class Trie
{
public:
  Trie();
  ~Trie();
  bool Init();
  bool AddString(const std::string &str);
  bool AddString(const char *const cstr);
  bool DelString(const std::string &str);
  bool DelString(const char *const cstr);
  bool Retrieval(const std::string &str);
  bool Retrieval(const char *const cstr);
  bool DebugString() const;

protected:
  bool AddTN(const TN *parent, const TN *lbro, const TN *rbro,
      TN *tn);

private:  
  TN *_root;  
}


} // namespace trie
} // namespace util
#endif
