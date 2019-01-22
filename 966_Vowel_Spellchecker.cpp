#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    unordered_set<string> exact;
    unordered_map<string, string> cap;
    unordered_map<string, string> vowel;
    vector<string> ans;
    for (auto word : wordlist) {
      if (exact.find(word) == exact.end())
        exact.insert(word);
      string capword = capitize(word);
      if (cap.find(capword) == cap.end())
        cap.insert(make_pair(capword, word));
      string withOutVowel = noVowel(word);
      if (vowel.find(withOutVowel) == vowel.end())
        vowel.insert(make_pair(withOutVowel, word));
    }
    for (auto query : queries) {
      if (exact.find(query) != exact.end()) {
        ans.push_back(query);
        continue;
      }
      string capword = capitize(query);
      auto it = cap.find(capword);
      if (it != cap.end()) {
        ans.push_back(it->second);
        continue;
      }
      string withOutVowel = noVowel(query);
      it = vowel.find(withOutVowel);
      if (it != vowel.end()) {
        ans.push_back(it->second);
        continue;
      }
      ans.push_back("");
    }
    return ans;
  }

private:
  bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }

  string capitize(string word) {
    string capword = word;
    transform(word.begin(), word.end(), capword.begin(), ::toupper);
    return capword;
  }

  string noVowel(string word) {
    string withOutVowel = "";
    for (char c : word) {
      if (isVowel(toupper(c)))
        withOutVowel.push_back(toupper(c));
      else
        withOutVowel.push_back('?');
    }
    return withOutVowel;
  }
};

int main() { cout << "HI" << endl; }