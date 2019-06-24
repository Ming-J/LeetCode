#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size())
      swap(str1, str2);
    
    auto last = find(str1.begin(), str1.end(), str2.begin());
    while (last != str1.end() && last + str2.size() != str1.end() &&
           distance(last, str1.end()) > str2.size()) {
      last = find(last, str1.end(), str2);
    }
    cout << str1 << ' ' << str2 << endl;
    if (last == str1.end()) {
      cout << "d" << endl;
      return "";
    } else if ((last + str2.size()) == str1.end()) {
      return str2;
    } else {
      size_t one = (last + str2.size()) - str1.begin();
      return gcdOfStrings(str1.substr(one), str2);
    }
  }
};

int main() {
  string a = "abab";
  string b = "ababab";
  Solution s;
  cout << "Answer: " << s.gcdOfStrings(a, b) << endl;
}
