#include <iostream>
using namespace std;

class Word {
public:
  Word(string input) : str{input} {
    fn = 0;
    int dot = 0;
    for (char c : str) {
      if (c != '.') {
        if (dot > 0)
          fn += dot - 1;
        dot = 0;
      } else
        ++dot;
    }
    if (dot > 0)
      fn += dot - 1;
  }

  void change(int pos, char c) {
    if (str[pos - 1] != '.' && c == '.') {
      if (pos == 1 && str[pos] == '.')
        ++fn;
      else if (pos == str.size() && str[pos - 2] == '.')
        ++fn;
      else if (str[pos - 2] == '.' && str[pos] == '.')
        fn += 2;
      else if (str[pos - 2] == '.' || str[pos] == '.')
        ++fn;
    }
    if (str[pos - 1] == '.' && c != '.') {
      if (pos == 1 && str[pos] == '.')
        --fn;
      else if (pos == str.size() && str[pos - 2] == '.')
        --fn;
      else if (str[pos - 2] == '.' && str[pos] == '.')
        fn -= 2;
      else if (str[pos - 2] == '.' || str[pos] == '.')
        --fn;
    }
    str[pos-1] = c;
  }
  int showFN() { return fn; }

private:
  string str;
  int fn;
};

int main() {
  //freopen("input.txt", "r", stdin);
  int n, q;
  string input;
  cin>>n>>q;
  cin >> input;
  Word t(input);
  for (int i = 0; i < q; ++i) {
    int pos;
    char c;
    cin >> pos >> c;
    t.change(pos, c);
    cout << t.showFN() << endl;
  }
}
