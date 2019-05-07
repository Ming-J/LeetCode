#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct tries {
  bool ends = false;
  vector<tries *> children;
  tries() : ends(false), children(26, NULL){};
  ~tries() {
    for (tries *it : children) {
      if (it)
        delete it;
    }
  }
};

class StreamChecker {
public:
  StreamChecker(vector<string> &words) : tree(new tries()) {
    for (auto w : words) {
      tries *cur = tree;
      for (auto it = w.rbegin(); it != w.rend(); ++it) {
        int index = *it - 'a';
        if (cur->children[index] == NULL) {
          cur->children[index] = new tries();
        }
        cout << index << " " << *it << endl;
        cur = cur->children[index];
      }
      cur->ends = true;
    }
  }

  void print(tries *cur, string s = "") {
    if (cur == NULL)
      cur = tree;
    if (cur->ends) {
      cout << s << endl;
    }
    for (size_t i = 0; i < 26; ++i) {
      if (cur->children[i]) {
        char c = i + 'a';
        print(cur->children[i], s + c);
      }
    }
  }
  bool query(char letter) {
    qu += letter;
    tries *cur = tree;
    for (auto it = qu.rbegin(); it != qu.rend(); ++it) {
      int index = *it - 'a';
      if (!cur->children[index])
        return false;
      cur = cur->children[index];
      if (cur->ends)
        return true;
    }
    return false;
  }
  ~StreamChecker() { delete tree; }

private:
  string qu;
  tries *tree;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
  vector<string> inputs = {"cd", "f","kl"};
  StreamChecker t(inputs);
  t.print(NULL);
  if (t.query('a'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if (t.query('b'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if (t.query('c'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if (t.query('d'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if (t.query('e'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if (t.query('f'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if (t.query('g'))
    cout << "true" << endl;
  else
    cout << "false" << endl;
}
