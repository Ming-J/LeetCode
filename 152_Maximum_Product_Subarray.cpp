#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
  int maxProduct(vector<int>& nums){
    if(nums.size()==1){
      return nums[0];
    }else{
      int product, maxProduct;
      vector<int> maxPro(nums.size() ,0);
      vector<int> minPro(nums.size() ,0);
      maxPro[i] = minPro[i] = nums[0];
      for(size_t i = 0; i < nums.size(); ++i){
	if(nums[i] > 0){
	  maxPro[i] = max( maxPro[i
	}else{

	}
	return maxPro[nums.size()];
    }
  }
};
