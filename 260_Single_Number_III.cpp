#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  vector<int> singleNumber(vector<int>& nums){
    unordered_set<int> container;
    for(int i=0;i<nums.size();i++){
      if(container.count(nums[i])>0){
	container.erase(nums[i]);
      }else{
	container.insert(nums[i]);
      }
    }
    vector<int> result;
    for(auto itr=container.begin();itr!=container.end();++itr){
      result.push_back(*itr);
    }
    return result;
  }
};

int main(){
  int num[6]={1,2,1,3,2,5};
  vector<int> input(num,num+6);
  Solution result;
  result.singleNumber(input);
}
