#include <iostream>
#include <vector>
using namespace std;

struct tries {
  bool isWord = false;
  vector<tries *> children;
  tries() : isWord{false}, children{vector<tries *>(26, NULL)} {};
  ~tries() {
    for (tries *c : children)
      if (c)
        delete c;
  }
};

class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() : _t{new tries()} {}

  /** Adds a word into the data structure. */
  void addWord(string word) {
    tries *cur = _t;
    for (char c : word) {
      int ind = c - 'a';
      if (!cur->children[ind])
        cur->children[ind] = new tries();
      cur = cur->children[ind];
    }
    cur->isWord = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word, tries *cur = NULL) {
    if (cur == NULL)
      cur = _t;
    for (size_t i = 0; i < word.size(); ++i) {
      if (word[i] == '.') {
        for (tries *df : cur->children) {
          if (df && search(word.substr(i + 1), df)) {
            return true;
          }
        }
        return false;
      } else {
        int ind = word[i] - 'a';
        if (!cur->children[ind])
          return false;
        cur = cur->children[ind];
      }
    }
    return cur->isWord;
  }

private:
  tries *_t;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
