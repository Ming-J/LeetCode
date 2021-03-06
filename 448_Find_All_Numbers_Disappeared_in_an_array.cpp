/*========================================================
Time Complexity: O(N)
Space Complexity: O(2)

Using an extra vector to store the number in the num vector
and the find the missing numbery
========================================================== */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> findDisappearedNumbers(vector<int>& nums){
    vector<int> temp (nums.size(),0);
    for(int i=0;i<nums.size();i++){
      temp[nums[i]-1]=1;
    }
    vector<int> result;
    for(int i=0;i<temp.size();i++){
      if(temp[i]==0){
	result.push_back(i+1);
      }
    }
    return result;
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
