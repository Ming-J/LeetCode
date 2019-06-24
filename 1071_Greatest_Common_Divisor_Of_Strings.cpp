#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size())
      swap(str1, str2);
    auto last = str1.find(str2);
    if (last == string::npos)
      return "";
    while (last != string::npos && last + str2.size() < str1.size()) {
      str1 = str1.substr(last + str2.size());
      last = str1.find(str2);
    }
    return str1 == str2 ? str2 : gcdOfStrings(str1, str2);
  }
};

int main() {
  string a = "abcabc";
  string b = "abcabcabcabc";
  Solution s;
  cout << "Answer: " << endl << s.gcdOfStrings(a, b) << endl;
}
