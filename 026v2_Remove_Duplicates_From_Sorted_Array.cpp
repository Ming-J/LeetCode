#include <iostream>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1)return nums.size();
    int unique = 0;
    int pointer = 0;
    while(pointer<nums.size()){
      if(nums[unique] != nums[pointer]){
	++unique;
      }
      nums[unique] = nums[pointer];
      ++pointer;
    }
    return unique+1;
  }
};

int main(){
  vector<int> inp = {1,2,3,3,3,4,4,5};

}
