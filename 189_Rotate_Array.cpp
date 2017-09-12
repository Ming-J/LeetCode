#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k=k%nums.size();
      int index=0;
      for(int i=nums.size()-k;i<nums.size();i++){
	nums[index]=nums[i];
	index++;
      }
      for(int i=index;i<nums.size()-k;i++){
	nums[index]=nums[i];
	index++;
      }
      
    }
};
