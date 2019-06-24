#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> _map;


//Recursion 
string lcs(string a, string b) {
  if (!a.empty() && !b.empty()) {
    string a_front = a.substr(0, a.size() - 1);
    string b_front = b.substr(0, b.size() - 1);
    if (a.back() == b.back()) {
      _map[a_front + "_" + b_front] += 1;
      return lcs(a_front, b_front) + a.back();
    } else {
      _map[a + "_" + b_front] += 1;
      string one = lcs(a, b_front);
      _map[a_front + "_" + b] += 1;
      string two = lcs(a_front, b);
      return one.size() > two.size() ? one : two;
    }
  }
  return "";
}

//Using Memorization, Top down approach
string lcs_MOMO(string a, string b, unordered_map<string, string> &dp) {
  unordered_map<string,string>::iterator it = dp.find(a + " " + b);
  if(it != dp.end()) return it->second;
  if (!a.empty() && !b.empty()) {
    string a_front = a.substr(0, a.size() - 1);
    string b_front = b.substr(0, b.size() - 1);
    string result;
    if (a.back() == b.back()) {
      result = lcs_MOMO(a_front, b_front, dp) + a.back();
    } else {
      _map[a + "_" + b_front] += 1;
      string one = lcs_MOMO(a, b_front, dp);
      _map[a_front + "_" + b] += 1;
      string two = lcs_MOMO(a_front, b, dp);
      result =  one.size() > two.size() ? one : two;
    }
    dp.insert({a + " " + b,result});
    return result;
  }
  return "";
}

int main() {
  cout << lcs("HUMAN", "CHIMPANZEE") << endl;
  for (auto p : _map) {
    cout << p.second << " " << p.first << endl;
  }
  _map.clear();
  cout << lcs("MAN", "PIG") << endl;
  for (auto p : _map) {
    cout << p.second << " " << p.first << endl;
  }
  _map.clear();
  unordered_map<string,string> momo;
  cout << lcs_MOMO("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA", "GTCGTTCGGAATGCCGTTGCTCTGTAAA", momo)
       << endl;
  for (auto p : _map) {
    cout << p.second << " " << p.first << endl;
  }
}
