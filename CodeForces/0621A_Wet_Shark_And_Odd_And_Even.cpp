#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  long long int sum = 0;
  for(auto& i : nums){
    cin>>i;
    sum += i;
  }
  nums.push_back(0);
  sort(nums.begin(),nums.end());
  int lo = 0;
  while(lo<nums.size()){
    if((sum-nums[lo])%2==0){
      cout<<sum-nums[lo]<<endl;
      return 0;
    }
    ++lo;
  }
  cout<<0<<endl;
}
