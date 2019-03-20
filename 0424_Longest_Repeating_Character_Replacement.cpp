#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  int characterReplacement(string s, int k) {
    int lo = 0, hi = 0, wid_size = 0;
    int char_count[26] = {0};
    for (; hi < s.size(); ++lo) {
      int max_char = 0;
      do {
        ++char_count[s[hi++]-'A'];
        for (int i = 0; i < 26; ++i) {
          max_char = max(char_count[i], max_char);
	}
	cout<<endl;
        wid_size = max(wid_size, hi - lo);
      } while ((hi - lo) - max_char <= k);
      cout<<lo <<s[lo]<<' '<< hi<<s[hi] << ' '<<max_char<<endl;
      --char_count[s[lo]-'A'];
    }
    return max(wid_size, hi - lo);
  }
};

int main() {
  Solution t;
  cout << t.characterReplacement("AABABBA", 1) << endl;
  ;
  cout << "Hello" << endl;
}
