#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canReorderDoubled(vector<int>& A) {
    map<int,int> count;
    for(int& n : A) ++count[n];
    while(!count.empty()){
      pair<int, int> front = *count.begin();
      int val = front.first;
      if(--count[val] == 0) count.erase(val);
      if(val >= 0 && count.find(val*2) != count.end() && count[val*2] > 0){
	if(--count[val*2] == 0) count.erase(val*2);
	continue;
      }
      if(val%2 == 0 && count.find(val/2) != count.end() && count[val/2] > 0){
	if(--count[val/2] == 0) count.erase(val/2);
	continue;
      }
      return false;
    }
    return true;
  }
};
