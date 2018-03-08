#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    if(nums.size() <= 1) return nums;
    int v1=INT_MIN,v2=INT_MIN,c1=0,c2=0;
    for(int nu : nums){
      if(nu == v1){
	++c1;
      }else if(nu == v2){
	++c2;
      }else{
	if(c1 == 0){
	  v1 = nu;
	  ++c1;
	}else if(c2 == 0){
	  v2 = nu;
	  ++c2;
	}else{
	  --c1;
	  --c2;
	}
      }
    }
    c1=c2=0;
    for( size_t i =0; i < nums.size(); ++i){
      if(v1 == nums[i]) c1++;
      if(v2 == nums[i]) c2++;
    }
    vector<int> res;
    if(v1 != INT_MIN && c1>(nums.size()/3.0)) res.push_back(v1);
    if(v2 != INT_MIN && c2>(nums.size()/3.0)) res.push_back(v2);
    cout<<v1<<' '<<v2<<endl;
    return res;
  }
};
