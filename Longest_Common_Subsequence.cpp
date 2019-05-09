#include <iostream>
#include <string>
using namespace std;

string lcs(string a, string b) {
  if (!a.empty() && !b.empty()) {
    string a_front = a.substr(0, a.size() - 1);
    string b_front = b.substr(0, b.size() - 1);
    if (a.back() == b.back())
      return lcs(a_front, b_front) + a.back();
    else {
      string one = lcs(a, b_front);
      string two = lcs(a_front, b);
      return one.size() > two.size() ? one : two;
    }
  }
  return "";
}

int main() {
  cout<<lcs("HUMAN","CHIMPANZEE");
}
