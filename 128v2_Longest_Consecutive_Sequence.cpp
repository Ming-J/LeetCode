#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    for(int n : nums) set.insert(n);
    int maxInterval = 0;
    for(int cur:nums){
      if(set.find(cur) != set.end()){
	set.erase(cur);
	int interval = 1;
	int diff = 1;
	while(set.find(cur+diff)!=set.end()){
	  set.erase(cur+diff++);
	  ++interval;
	}
	diff = 1;
	while(set.find(cur-diff) != set.end()){
	  set.erase(cur-diff++);
	  ++interval;
	}
	maxInterval = max(maxInterval,interval);
      }
    }
    return maxInterval;
  }
};
