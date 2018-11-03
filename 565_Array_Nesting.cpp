#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    vector<int> set(nums.size(),-1);
    int maxLength = 0;
    int currentSet = 1;
    for(size_t i = 0; i < nums.size(); ++i){
      int count = 0;
      for(size_t newIndex = i; set[newIndex] == -1;
	  newIndex=nums[newIndex],++count){
	set[newIndex] = currentSet;
      }
      maxLength = max(maxLength,count);
    }
    return maxLength;
  }
};

int main(){
  Solution t;
  vector<int> inpi = {5,4,0,3,1,6,2};
  cout<<t.arrayNesting(inpi)<<endl;;
}
