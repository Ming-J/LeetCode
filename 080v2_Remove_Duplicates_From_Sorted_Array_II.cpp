#include <iostream>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 2)return nums.size();
    int index = 2;
    for(int i = 2; i < nums.size(); ++i){
      if(nums[i] != nums[index-2]){
	nums[index] = nums[i];
	++index;
      }
    }
    return index;
  }
};

int main(){
  vector<int> inp = {1,2,3,3,3,4,4,5};

}
