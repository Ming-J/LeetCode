#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TrieNode{
  char c;
  bool isWord = false;
  vector<TrieNode*> children;
  TrieNode(char c,bool w):c(c),isWord(w){
    children.assign(26, NULL);
  };
  ~TrieNode(){
    for(auto node : children) delete node;
  }
};

class Tries{
public:
  Tries(){
    root = new TrieNode(0,false);
  }
  
  void insert(string word){
    TrieNode* cur = root;
    for(size_t i = 0; i < word.size(); ++i){
      if(cur->children[word[i]-'a'] == NULL){
	cur->children[word[i]-'a'] = new TrieNode(word[i],false);
      }
      cur = cur->children[word[i] - 'a'];
      if(i == word.size() - 1) cur->isWord = true;
    }
  }

  string bfs(){
    queue<pair< TrieNode*,string > > qu;
    qu.push({root,""});
    pair<TrieNode*,string> last;
    while(!qu.empty()){
      size_t size = qu.size();
      for(size_t i = qu.size() - 1; i < size; --i){
	TrieNode* current = qu.front().first;
	for(size_t j = current->children.size() - 1;
	    j < current->children.size(); --j){
	  if(current->children[j] && current->children[j]->isWord)
	    qu.push(make_pair(current->children[j],
			      qu.front().second+static_cast<char>(j+'a')));
	}
	last = qu.front();
	qu.pop();
      }
    }
    return last.second;
  }
  
private:
  TrieNode* root;
};
  
class Solution {
public:
  string longestWord(vector<string>& words) {
    Tries dic;
    for(string word : words) dic.insert(word);
    return dic.bfs();
  }
};
