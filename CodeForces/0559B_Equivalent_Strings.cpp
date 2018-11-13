#include <iostream>
#include <string>
using namespace std;

class Equal {
public:
  bool checkString(string s1, string s2) {
    if (s1 == s2)
      return true;
    if (s1.size() == s2.size() && s1.size() % 2 != 0)
      return false;
    string s1_1 = s1.substr(0, s1.size() / 2);
    string s1_2 = s1.substr(s1.size() / 2, s1.size() / 2);
    string s2_1 = s2.substr(0, s2.size() / 2);
    string s2_2 = s2.substr(s2.size() / 2, s2.size() / 2);
    return (checkString(s1_1, s2_1) && checkString(s1_2, s2_2)) ||
           (checkString(s1_1, s2_2) && checkString(s1_2, s2_1));
  }

  string smallest(string s) {
    if (s.size() % 2 == 1)
      return s;
    string s1 = smallest(s.substr(0, s.size() / 2));
    string s2 = smallest(s.substr(s.size() / 2));
    if (s1 < s2)
      return s1 + s2;
    else
      return s2 + s1;
  }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  Equal t;
  if (t.smallest(s1) == t.smallest(s2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
