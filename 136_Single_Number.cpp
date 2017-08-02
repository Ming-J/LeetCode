#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int singleNumber(vector<int>& nums){
    int mask=0;
    for(int i=0;i<nums.size();i++){
      mask=mask^nums[i];
    }
    return mask;
  }
};

int main(){
  Solution test;
  int arr[11]={1,2,3,4,5,6,5,4,3,2,1};
  vector<int> input(arr,arr+sizeof arr/sizeof arr[0]);
  cout<<test.singleNumber(input)<<endl;
}
