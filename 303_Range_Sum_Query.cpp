#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
  vector<int> table;
public:
    NumArray(vector<int> nums) {
      int sum=0;
      for(size_t i=0;i<nums.size();i++){
	sum+=nums[i];
	table.push_back(sum);
      }
    }
    
    int sumRange(int i, int j) {
      if(i==0){
	return table[j];
      }else{
	return table[j]-table[i-1];
      }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 * 1,2,3,4,5   1,3,6,10,15
 */
