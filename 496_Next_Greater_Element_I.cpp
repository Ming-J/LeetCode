#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
Using hash map to optiimize. Using a stack to kept track of the right
most order. compare the stack until an number if bigger. If stack is
empty assign the value to -1. Linear Complexity. Line Space Complexity.
O(m+n)
S(m+n)
*/

class Solution{
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums){
    vector<int> ans;
    unordered_map<int,int> hash;
    stack<int> deck;
    for(int i=nums.size()-1;i>=0;i--){
      if(i==nums.size()-1){
	hash[nums[i]]=-1;
      }else{
	if(nums[i]<deck.top()){
	  hash[nums[i]]=deck.top();
	  deck.push(nums[i]);
	}else{
	  while(!deck.empty()&&deck.top()<nums[i]){
	    deck.pop();
	  }
	  hash[nums[i]]=deck.empty()?-1:deck.top();
	}
      }
      deck.push(nums[i]);
    }
    for(int i=0;i<findNums.size();i++){
      ans.push_back(hash[findNums[i]]);
    }
    return ans;
  }
};
