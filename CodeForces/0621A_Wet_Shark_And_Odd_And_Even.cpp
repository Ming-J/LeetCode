#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  vector<int> nums(n);
  long sum = 0;
  for(auto& i : nums){
    cin>>i;
    sum += i;
  }
  sort(nums.begin(),nums.end());
  int lo = 0;
  while(lo<nums.size()){
    if((sum-num[lo])%2==0){
      cout<<sum-num[lo]<<endl;
      return 0;
    }
  }
  cout<<0<<endl;
}
