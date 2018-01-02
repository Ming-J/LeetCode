#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int minMoves(vector<int>& nums){
    int count=0;
    int smallest=nums[0];
    int sum=0;
    for(int i=0;i<nums.size();i++){
      smallest=min(smallest,nums[i]);
      sum+=nums[i];
    }
    return sum-smallest*nums.size();
  }
};


int main(){
  vector<int> input;
  input={1,2,3};
  Solution test;
  cout<<test.minMoves(input)<<endl;
}
