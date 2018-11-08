#include <iostream>
#include <chrono>
#include <unordered_map>
using namespace std;

/*
  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26

  12  => 2   AB, L
  226 => 3  BZ, VF, BBF

*/

class Solution {
public:
  int numDecodings(string s) {
    return dc(s); 
  }

  int dc(string s){
    //cout<<s<<endl;
    if(dp.find(s)!=dp.end()) return dp[s];
    if(s.empty()) return 1;
    //if(s.size() == 1 && s!="0") return 1;
    int rec = 0;
    int single_val = stoi(s.substr(0,1));
    int double_val = stoi(s.substr(0,2));
    if(s.size() >= 1 && single_val > 0 && single_val <= 26)
      rec += dc(s.substr(1));
    if(s.size() >= 2 &&s.front()!='0'&& double_val > 0 && double_val <= 26)
      rec += dc(s.substr(2));
    dp[s] = rec;
    return rec;
  }

private:
  unordered_map<string, int> dp;
};

int main(){
  Solution s;
  auto t_start = chrono::steady_clock::now();
  cout<<s.numDecodings("9272971672512277354953939427689518239714228293463398742522722274929422229859968434281231132695842184")<<endl;
  auto t_end = chrono::steady_clock::now();
  auto t_diff = t_end - t_start;
  cout<<chrono::duration <double, milli> (t_diff).count()<<endl;
}
