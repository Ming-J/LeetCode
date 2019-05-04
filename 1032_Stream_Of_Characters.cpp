#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

struct tries{
  bool ends = false;
  char c;
  vector<tries*> nextChar;
  tries(char chr):nextChar(26,NULL){c = chr;};
  ~tries(){
    for(auto it : nextChar){
      delete it;
    }
  }
};

class StreamChecker {
public:
  StreamChecker(vector<string> &words) {
    for (auto w : words) {
      tries* cur = tree;
      for(auto it = w.rbegin(); it != w.rend(); ++it){
	int index = *it - 'a';
	if(!cur->nextChar[index]){
	  cur->nextChar[index] = new tries(*it);
	}
	cur = cur->nextChar[index];
      }
      cur->ends = true;
    }
  }
  void print(){
    tries* cur = tree;
    string s = "";
    for(auto it : cur->nextChar){
      if(it){
	print(it,s + it->c);
      }
    }
  }

  void print(tries* cur, string s){
    if(cur->ends){
      cout<<s<<endl;
    }
    for(auto it : cur->nextChar){
      if(it){
	print(it,s+it->c);
      }
    }
  }
  bool query(char letter) {
    return false;
  }

private:
  tries* tree;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main(){
  vector<string> inputs = {"aba","zsx"};
  StreamChecker t(inputs);
  //t.print();
}
