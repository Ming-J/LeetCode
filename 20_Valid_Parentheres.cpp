#include <cassert>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> lookup = {{')', '('}, {'}', '{'}, {']', '['}};
    for (char pren : s) {
      auto it = lookup.find(pren);
      if (it == lookup.end())
        st.push(pren);
      else {
        if (st.empty() || st.top() != it->second)
          return false;
        st.pop();
      }
    }
    return st.empty();
  }
};

int main() {
  Solution test;
  assert(true == test.isValid("()(){}"));
  cout << "First Assert is Correct" << endl;
  assert(false == test.isValid("()({}"));
  cout << "Second Assert is Correct" << endl;
  assert(true == test.isValid(""));
  cout << "Third Assert is Correct" << endl;
}
