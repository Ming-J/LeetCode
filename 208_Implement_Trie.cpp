#include <iostream>
#include <vector>
using namespace std;

struct CharNode{
  char c;
  bool isLast;
  vector<CharNode*> carr {26};
  CharNode():c(0),isLast(false){}
  CharNode(char ch,bool l):c(ch),isLast(l){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
      root = new CharNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      CharNode* cur = root;
      for(size_t i = 0; i < word.size(); ++i){
	char c = word[i] - 'a';
	bool last = (i == word.size() - 1)? true:false;
	if(cur->carr[c] == NULL){
	  cur->carr[c] = new CharNode(c,last);
	}
	if(last) cur->carr[c]->isLast = last;
	cur = cur->carr[c];
      }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      CharNode* cur = root;
      for(size_t i = 0; i < word.size(); ++i){
	char c = word[i] - 'a';
	if(cur->carr[c] == NULL) return false;
	cur = cur->carr[c];
      }
      return cur->isLast;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      CharNode* cur = root;
      for(size_t i = 0; i < prefix.size(); ++i){
	char c = prefix[i] - 'a';
	if(cur->carr[c] == NULL) return false;
	cur = cur->carr[c];
      }
      return cur!=NULL;
      for(auto it : cur->carr){
	if(it != NULL) return true;
      }
      return false;
    }

private:
  CharNode* root;
};
