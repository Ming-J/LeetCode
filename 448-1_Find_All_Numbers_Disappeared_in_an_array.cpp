/*========================================================
Time Complexity: O(N)
Space Complexity: O(1)

Going through the array. Making the value appeared in the array
negative. Going through the array again, if the value in current
position is not negitvie, we can assume the index has not appear.
========================================================== */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
  vector<int> findDisappearedNumbers(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
      int pos= abs(nums[i])-1;
      if(nums[pos]>0){
	nums[pos]=nums[pos]*-1;
      }
    }
    int numSize=nums.size();
    for(int i=0;i<numSize;i++){
      if(nums[i]>0){
	nums.push_back(i+1);
      }
    }
    nums.erase(nums.begin(),nums.begin()+numSize);
    return nums;
  }
};

int main(){
  vector<int> input;
  input.push_back(4);
  input.push_back(3);
  input.push_back(2);
  input.push_back(7);
  input.push_back(8);
  input.push_back(2);
  input.push_back(3);
  input.push_back(1);
  Solution test;
  vector<int> output;
  output=test.findDisappearedNumbers(input);
  for(int i=0;i<output.size();i++){
    cout<<output[i]<<endl;
  }
  cout<<"hello world!"<<endl;
}
